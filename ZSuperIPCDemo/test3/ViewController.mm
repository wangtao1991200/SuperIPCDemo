//
//  ViewController.m
//  test3
//
//  Created by YangFeixiang on 2018/4/5.
//  Copyright © 2018年 fenzhi. All rights reserved.
//

#import "ViewController.h"
#import "JSONStructProtocal.h"
#import "IPCNetManagerInterface.h"
#import "SEP2P_Error.h"
#import <AVKit/AVKit.h>
#import "UIViewController+LJWKeyboardHandlerHelper.h"

pthread_mutex_t h26xDecodeLock;
H26xHwDecoder *h26xDecode;

XBAudioUnitPlayer *player;
XBAudioUnitRecorder *recorder;

NSString *recordVideoPath;
KHJLiveRecordType recordType;
RecSess_t gVideoRecordSession = NULL;   // 直播录屏会话
dispatch_queue_t recordQueue = dispatch_queue_create("recordQueue", DISPATCH_QUEUE_SERIAL);

#pragma mark - 回放注册回调
typedef void(^playBackVideoOrAudioDataRetultBlock)(const char*uuid,int type,unsigned char*data,int len,long timestamp);

/// 设备周围网络列表
IPCNetWifiAplist_st wifiListCfg;


@interface ViewController ()<H26xHwDecoderDelegate>

{
    __weak IBOutlet UIImageView *imageView;
    __weak IBOutlet UIView *playerContentView;
    __weak IBOutlet UIButton *startTalkButton;
    
    NSString *docPath;
    NSFileManager *fileManager;
    
    __weak IBOutlet UIButton *qualityBtn;
    
    __weak IBOutlet UIView *rebackView;
    __weak IBOutlet UITextField *rebackView_ID;
    __weak IBOutlet UITextField *rebackView_Date;
    __weak IBOutlet UITextField *rebackView_Time;
    __weak IBOutlet UITextField *rebackView_Path;
    __weak IBOutlet NSLayoutConstraint *replayViewCY;
}
@end

@implementation ViewController

@synthesize textviewuuid,connectBtn,playBtn,statusLabel;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self registerLJWKeyboardHandler];

    ipcnetHandle.onAudioData=onAudioData;
    ipcnetHandle.onStatus=onStatus;
    ipcnetHandle.onVideoData=onVideoData;
    ipcnetHandle.onJSONString=onJSONString;
    
    IPCNetInitialize("");
//    [textviewuuid setText:@"IPCKA00006CESZBO"];
//    [textviewuuid setText:@"IPCA000015WAABW"];
//    [textviewuuid setText:@"IPCA000008GAIWC"];
//    [textviewuuid setText:@"IPCA000002AINYZ"];
    [textviewuuid setText:@"IPCKA00000AEZWEK"];

    h26xDecode = [[H26xHwDecoder alloc] init];
    h26xDecode.delegate = self;
    pthread_mutex_init(&h26xDecodeLock, NULL);
	
	recorder = [[XBAudioUnitRecorder alloc] initWithRate:XBAudioRate_8k bit:XBAudioBit_16 channel:XBAudioChannel_1];
    strcpy(recorder.mUUID, [textviewuuid.text UTF8String]);
    recorder.codeType = IPCNET_AUDIO_ENCODE_TYPE_G711A;
	//start
    //[recorder start];
	//stop
	//[recorder stop];
	
	player = [[XBAudioUnitPlayer alloc] initWithRate:XBAudioRate_8k bit:XBAudioBit_16 channel:XBAudioChannel_1];
    player.mUUID = textviewuuid.text;
    player.codeType = IPCNET_AUDIO_ENCODE_TYPE_G711A;
	//start
	//[player start];
	//stop
	//[player stop];
    
    recordType = KHJLiveRecordType_Normal;
    fileManager = [NSFileManager defaultManager];
    docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(changeQuality_Noti) name:@"changeQuality_Noti" object:nil];
}

- (IBAction)changeQualityAction:(id)sender
{
    UIAlertController *alertview = [UIAlertController alertControllerWithTitle:@"切换清晰度" message:nil preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *config = [UIAlertAction actionWithTitle:@"4K"
                                                     style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self setQualityLevel_withLevel:2];
    }];
    UIAlertAction *config1 = [UIAlertAction actionWithTitle:@"高清"
                                                      style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self setQualityLevel_withLevel:1];
    }];
    UIAlertAction *config2 = [UIAlertAction actionWithTitle:@"标清"
                                                      style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self setQualityLevel_withLevel:0];
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消"
                                                     style:UIAlertActionStyleCancel handler:nil];

    [alertview addAction:config];
    [alertview addAction:config1];
    [alertview addAction:config2];
    [alertview addAction:cancel];
    [self presentViewController:alertview animated:YES completion:nil];
}

#pragma mark - 设置清晰度
/// level 清晰度级别 0 标清，1 高清，2 4K超清
- (void)setQualityLevel_withLevel:(int)level
{
    int quality;
    if (level == 0) {
        quality = 0;
        [qualityBtn setTitle:@"标清" forState:UIControlStateNormal];
    }
    else if (level == 1) {
        quality = 1;
        [qualityBtn setTitle:@"高清" forState:UIControlStateNormal];
    }
    else {
        quality = 1;
        [qualityBtn setTitle:@"4K" forState:UIControlStateNormal];
    }
    
    if(h26xDecode!=nil){
        pthread_mutex_lock(&h26xDecodeLock);
        [h26xDecode releaseH26xHwDecoder];
        h26xDecode=nil;
        pthread_mutex_unlock(&h26xDecodeLock);
    }
    IPCNetSetResolutionR(textviewuuid.text.UTF8String, quality, OnSetQualityLevelCmdResult);
}

void OnSetQualityLevelCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnSetQualityLevelCmdResult %s cmd:%d uuid:%s json:%s\n",__func__,cmd, uuid, json);
    if (h26xDecode == nil) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"changeQuality_Noti" object:nil];
    }
}

- (void)changeQuality_Noti
{
    pthread_mutex_lock(&h26xDecodeLock);
    h26xDecode = [[H26xHwDecoder alloc] init];
    h26xDecode.delegate = self;
    h26xDecode.deviceID = @"";
    pthread_mutex_unlock(&h26xDecodeLock);
}

#pragma MARK - H26xHwDecoderDelegate

- (void)getImageWith:(UIImage *_Nonnull)image imageSize:(CGSize)imageSize deviceID:(NSString *_Nullable)deviceID
{
    imageView.image = image;
//    NSLog(@"width = %f,height = %f",imageSize.width,imageSize.height);
}

- (IBAction)openBtnAction:(UIButton *)sender
{
}


- (IBAction)turnAroundAction:(UIButton *)sender
{
    
}

- (void)startCamera
{
    
}

- (void)stopCamera
{
}

- (IBAction)editUUID:(UITextField *)sender {
    NSLog(@"input text is %@",sender.text);
}
- (IBAction)inputUUID:(id)sender {
    NSLog(@"input text is %@",sender);
}

- (IBAction)connect:(id)sender {
    NSLog(@"connect %@",textviewuuid.text);
    
    int ret1 = IPCNetStopIPCNetSession(textviewuuid.text.UTF8String);
    
    //int ret=IPCNetStartIPCNetSession(textviewuuid.text.UTF8String,"84567",&ipcnetHandle);
    int ret=IPCNetStartIPCNetSession(textviewuuid.text.UTF8String,"qq123456",&ipcnetHandle);
    NSLog(@"IPCNetStartIPCNetSession ret=%d",ret);
}

- (IBAction)disconnectBtn:(id)sender {
    const char *uuid=[textviewuuid.text UTF8String];
    IPCNetStopIPCNetSession(uuid);
}

void OnGetDeviceWiFi_CmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnGetDeviceWiFi_CmdResult\n");
    
    JSONObject jsdata(json);
    wifiListCfg.parseJSON(jsdata);
    IPCNetReleaseCmdResource(cmd,uuid,OnGetDeviceWiFi_CmdResult);

    NSLog(@"num =%d",wifiListCfg.num);
    
//    dispatch_async(dispatch_get_main_queue(), ^{
//        NSLog(@"json ======================================== %s\n", json);
//        [ViewController cString_changto_ocStringWith:json];
//    });
}

+ (NSDictionary *)cString_changto_ocStringWith:(const char *)cString
{
    NSString *json      = [NSString stringWithUTF8String:cString];
    if (json == nil) {
        return nil;
    }
    NSData *jsonData    = [json dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *body  = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:nil];
    return body;
}

#pragma mark -  开始播放
- (IBAction)playvideoBtn:(id)sender
{
    const char *uuid=[textviewuuid.text UTF8String];
    IPCNetStartVideo(uuid, 1);
}

#pragma mark -  Wi-Fi搜索
- (IBAction)getDeviceWifi:(id)sender
{
    int ret = IPCNetSearchWiFiR(textviewuuid.text.UTF8String, OnGetDeviceWiFi_CmdResult);
    NSLog(@"ret = %d",ret);
}

#pragma mark -  停止播放视频
- (IBAction)stopvideoBtn:(id)sender
{
    const char *uuid=[textviewuuid.text UTF8String];
    IPCNetStopVideo(uuid);
}

#pragma mark - 开始播放音频
- (IBAction)playaudioBtn:(id)sender
{
    const char *uuid = [textviewuuid.text UTF8String];
    IPCNetStartAudio(uuid);
	if(player != nil){
		[player start];
	}
}

#pragma mark - 停止播放音频
- (IBAction)stopaudioBtn:(id)sender
{
	if (player != nil) {
		[player stop];
	}
    const char *uuid=[textviewuuid.text UTF8String];
    IPCNetStopAudio(uuid);
}

#pragma mark - 开始对讲

- (IBAction)startTalkBtn:(UIButton *)sender
{
    if (!sender.selected) {
        sender.selected = YES;
        const char *uuid = [textviewuuid.text UTF8String];
        NSLog(@"注意！！！！请先开启视频流，设备端才能播放声音！！！！！");
        IPCNetStartTalk(uuid, IPCNET_AUDIO_G711A);
        [recorder start];
    }
}

#pragma mark - 停止对讲

- (IBAction)stopTalkBtn:(UIButton *)sender
{
    startTalkButton.selected = NO;
    const char *uuid=[textviewuuid.text UTF8String];
    NSLog(@"addStopTalkCode");
    [recorder stop];
    IPCNetStopTalk(uuid);
}

#pragma mark - 开始录屏

- (IBAction)startRecordBtnAction:(id)sender
{
    recordType = KHJLiveRecordType_Recording;
    recordVideoPath = [[self getTakeVideoDocPath_with_deviceID:@"deviceID"] stringByAppendingPathComponent:[self getVideoNameWithType:@"mp4" deviceID:@"deviceID"]];
}

#pragma mark - 结束录屏

- (IBAction)stopRecordBtnAction:(id)sender
{
    recordType = KHJLiveRecordType_stopRecoding;
    recordVideoPath = [[self getTakeVideoDocPath_with_deviceID:@"deviceID"] stringByAppendingPathComponent:[self getVideoNameWithType:@"mp4" deviceID:@"deviceID"]];
}

#pragma mark - 录屏视频列表

- (IBAction)getVideoList:(id)sender
{
    NSArray *array = [self getmp4VideoArray_with_deviceID:@"deviceID"];
    NSLog(@"array = %@",array);
    UIAlertController *alertview = [UIAlertController alertControllerWithTitle:@"添加设备" message:nil preferredStyle:UIAlertControllerStyleAlert];
    WeakSelf
    for (int i = 0; i < array.count; i++) {
        UIAlertAction *config = [UIAlertAction actionWithTitle:array[i]
                                                         style:UIAlertActionStyleDefault
                                                       handler:^(UIAlertAction * _Nonnull action) {
            [weakSelf chooseItemWith:array[i]];
        }];
        [alertview addAction:config];
    }
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    [alertview addAction:cancel];
    [self presentViewController:alertview animated:YES completion:nil];
}

- (void)chooseItemWith:(NSString *)videoName
{
    NSString *path = [self getTakeVideoDocPath_with_deviceID:@"deviceID"];
    AVPlayerViewController * av = [[AVPlayerViewController alloc] init];
    av.player = [AVPlayer playerWithURL:[NSURL fileURLWithPath:[NSString stringWithFormat:@"%@/%@",path,videoName]]];
    [self presentViewController:av animated:YES completion:^{}];
}

IPCNetOsdCfg_st mIPCNetOsdCfg;
void OnGetOSDCmdResult(int cmd,const char*uuid,const char*json)
{
    JSONObject jsdata(json);
    NSLog(@"OnGetOSDCmdResult cmd:%d,uuid:%s,json:%s",cmd,uuid,json);
    mIPCNetOsdCfg.parseJSON(jsdata);
    
    IPCNetReleaseCmdResource( cmd, uuid,OnGetOSDCmdResult);
}

#pragma mark - 获取 OSD 参数

- (IBAction)GetOSDBtn:(id)sender
{
    String str;
    const char *uuid=[textviewuuid.text UTF8String];
    IPCNetGetOsdCfg_st ipcNetGetOsdCfg;
    ipcNetGetOsdCfg.Vich=0;
    ipcNetGetOsdCfg.toJSONString(str);
    IPCNetGetOSDR(uuid,str.data(),OnGetOSDCmdResult);
}
void OnSetOSDCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnSetOSDCmdResult cmd:%d,uuid:%s,json:%s",cmd,uuid,json);
    IPCNetReleaseCmdResource( cmd, uuid,OnSetOSDCmdResult);
}

#pragma mark - 设置 OSD 参数

- (IBAction)SetOSDBtn:(id)sender
{
    String str;
    const char *uuid=[textviewuuid.text UTF8String];
    mIPCNetOsdCfg.OsdNameInfo->NameText="camera name";
    mIPCNetOsdCfg.OsdNameInfo->NameConf->Enable=1;
    mIPCNetOsdCfg.OsdNameInfo->NameConf->Xcord=200;
    mIPCNetOsdCfg.OsdNameInfo->NameConf->Ycord=200;
    mIPCNetOsdCfg.OsdNameInfo->NameConf->DisplayMode=1;
    
    mIPCNetOsdCfg.toJSONString(str);
    IPCNetGetOSDR(uuid,str.data(),OnSetOSDCmdResult);
}

IPCNETMoveAlarmCfg_st mIPCNETMoveAlarmCfg;
void OnGetAlarmCmdResult(int cmd,const char*uuid,const char*json)
{
    JSONObject jsdata(json);
    NSLog(@"OnGetAlarmCmdResult cmd:%d,uuid:%s,json:%s",cmd,uuid,json);
    mIPCNETMoveAlarmCfg.parseJSON(jsdata);
    
    IPCNetReleaseCmdResource( cmd, uuid,OnGetAlarmCmdResult);
}

#pragma mark - 设置 OSD 参数

- (IBAction)GetAlarmBtn:(id)sender
{
    const char *uuid = [textviewuuid.text UTF8String];
    IPCNetGetAlarmR(uuid,OnGetAlarmCmdResult);
}

void OnSetAlarmCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnSetAlarmCmdResult cmd:%d,uuid:%s,json:%s",cmd,uuid,json);
    
    IPCNetReleaseCmdResource( cmd, uuid,OnSetAlarmCmdResult);
}

#pragma mark - 设置报警信息

- (IBAction)SetAlarmBtn:(id)sender
{
    String str;
    const char *uuid=[textviewuuid.text UTF8String];
    
    mIPCNETMoveAlarmCfg.MoveInfo.MdEnable=1;
    mIPCNETMoveAlarmCfg.MoveInfo.Sensitive=5;
    
    mIPCNETMoveAlarmCfg.Week[0]->Flag=1;
    
    IPCNetTime_st*time=&mIPCNETMoveAlarmCfg.Week[0]->TimePeriod[0]->Start;
    time->Hour=0;
    time->Min=0;
    time->Sec=0;
    time=&mIPCNETMoveAlarmCfg.Week[0]->TimePeriod[0]->End;
    time->Hour=0;
    time->Min=0;
    time->Sec=0;
    
    for(int i=0;i<mIPCNETMoveAlarmCfg.MoveInfo.AreaCount;i++)
        mIPCNETMoveAlarmCfg.MoveInfo.Area[i]=1;
    
    mIPCNETMoveAlarmCfg.PolicyInfo.SnapInfo.PushEnable=1;
    mIPCNETMoveAlarmCfg.PolicyInfo.SnapInfo.PictureNum=1;
    
    mIPCNETMoveAlarmCfg.PolicyInfo.RecordInfo.RecEnable=1;
    
    mIPCNETMoveAlarmCfg.toJSONString(str);
    
    IPCNetSetAlarmR( uuid,str.data(),OnSetAlarmCmdResult);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onStatus:) name:@"onStatus" object:nil];
}
// P2P_STATUS_SUCCESSFUL
- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"onStatus" object:nil];
}
-(void)onStatus:(NSNotification *)notification
{
    NSDictionary * infoDic = [notification object];
    
    int status = [[infoDic objectForKey:@"status"] intValue];
    
    NSString*uuid=[infoDic objectForKey:@"uuid"];
    
    dispatch_async(dispatch_get_main_queue(), ^{
    NSLog(@"onStatus uuid:%@ status:%d",uuid,status);
    switch (status) {
       case ERROR_SEP2P_SESSION_CLOSED_CALLED:{
           [self->statusLabel setText:@"online"];
        }break;
        case ERROR_SEP2P_SESSION_CLOSED_TIMEOUT:{
            [self->statusLabel setText:@"timeout"];
        }break;
        case ERROR_SEP2P_INVALID_ID:{
            [self->statusLabel setText:@"INVALID ID"];
        }break;
        default:
            [self->statusLabel setText:@"offline"];
            break;
    }
    });
}

void onStatus(const char* uuid,int status)
{
    NSLog(@"uuid:%s status:%d",uuid,status);
    NSString *nsuuid;
    nsuuid=[[NSString alloc] initWithUTF8String:uuid];
    
    NSDictionary * infoDic = @{@"uuid":nsuuid, @"status":[NSNumber numberWithInt:status]};
    [[NSNotificationCenter defaultCenter] postNotificationName:@"onStatus" object:infoDic];
}
void onVideoData(const char* uuid,int type,unsigned char*data,int len,long timestamp)
{
    NSLog(@"onVideoData uuid:%s type:%d len:%d timestamp:%ld\n\n",uuid,type,len,timestamp);
    
    if(h26xDecode!=nil){
        pthread_mutex_lock(&h26xDecodeLock);
        [h26xDecode decodeH26xVideoData:data videoSize:len frameType:type timestamp:timestamp];
        pthread_mutex_unlock(&h26xDecodeLock);
    }
    
    if (recordType == KHJLiveRecordType_Recording) {
        NSLog(@"正在直播录屏 path = %@",recordVideoPath);
        dispatch_sync(recordQueue, ^{
            if (gVideoRecordSession) {
                int ret = IPCNetPutLocalRecordVideoFrame(gVideoRecordSession, type, (const char*)data, len, timestamp);
                if (ret == 0) NSLog(@"输入 Video 数据");
            }
            else {
                if (type >= IPCNET_H264E_NALU_BSLICE && type < IPCNET_H264E_NALU_BUTT) {
                    // h264
                    gVideoRecordSession = IPCNetStartRecordLocalVideo(recordVideoPath.UTF8String, IPCNET_VIDEO_ENCODE_TYPE_H264, 30, IPCNET_AUDIO_ENCODE_TYPE_G711A, 8000, 2, 1);
                }
                else if (type >= IPCNET_H265E_NALU_BSLICE) {
                    // h265
                    gVideoRecordSession = IPCNetStartRecordLocalVideo(recordVideoPath.UTF8String, IPCNET_VIDEO_ENCODE_TYPE_H265, 30, IPCNET_AUDIO_ENCODE_TYPE_G711A, 8000, 2, 1);
                }
            }
        });
    }
    else if (recordType == KHJLiveRecordType_stopRecoding) {
        // CLog(@"停止直播录屏 path = %@",liveRecordVideoPath);
        recordType = KHJLiveRecordType_Normal;
        IPCNetFinishLocalRecord(gVideoRecordSession);
        gVideoRecordSession = NULL;
    }
}
void onAudioData(const char* uuid,int type,unsigned char*data,int len,long timestamp)
{
    NSLog(@"onAudioData uuid:%s type:%d len:%d timestamp:%ld",uuid,type,len,timestamp);
    [player playThisAudioData:(uint8_t *)data audioSize:len frameType:type timestamp:timestamp];
    if (recordType == KHJLiveRecordType_Recording) {
//        dispatch_sync(recordQueue, ^{
//            if (gVideoRecordSession) {
//                int ret = IPCNetPutLocalRecordAudioFrame(gVideoRecordSession, type, (const char *)data, len, timestamp);
//                if (ret == 0) {
//                    NSLog(@"输入 Audio 数据");
//                }
//                else {
//                    NSLog(@"输入 Audio 数据 失败 ret = %d",ret);
//                }
//            }
//        });
    }
    else if (recordType == KHJLiveRecordType_stopRecoding) {
        recordType = KHJLiveRecordType_Normal;
        IPCNetFinishLocalRecord(gVideoRecordSession);
        gVideoRecordSession = NULL;
    }
}

void onJSONString(const char* uuid,int msg_type,const char* jsonstr)
{
    NSLog(@"uuid:%s msg:%d json:%s",uuid,msg_type,jsonstr);
}

void OnSearchDeviceResult(struct DevInfo*dev)
{
    NSLog(@"OnSearchDeviceResult uuid:%s ip:%s",dev->mUUID,dev->mIP);
}


void OnSearchDeviceResult(struct DevInfo*dev);

#pragma mark - 搜索周围设备

- (IBAction)searchBtn:(id)sender
{
    IPCNetSearchDevice(OnSearchDeviceResult);
}

// 直播录屏保存地址
- (NSString *)getTakeVideoDocPath_with_deviceID:(NSString *)deviceID
{
    NSString *videoPath = [docPath stringByAppendingPathComponent:[NSString stringWithFormat:@"Video/%@.mp4",deviceID]];
    BOOL isDir = NO;
    BOOL existed = [fileManager fileExistsAtPath:videoPath isDirectory:&isDir];
    if (!(isDir == YES && existed == YES)) {
        [fileManager createDirectoryAtPath:videoPath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return videoPath;
}

- (NSString *)getVideoNameWithType:(NSString *)fileType deviceID:(NSString *)deviceID
{
    // 获取年月日
    NSDictionary *dicDay = [self getTodayDate] ;
    NSString *khjtoday = [NSString stringWithFormat:@"%@%@%@",dicDay[@"year"],dicDay[@"month"],dicDay[@"day"]] ;
    NSString *picOrVideoName  = [NSString stringWithFormat:@"%@-%@",khjtoday,deviceID] ;
    
    NSTimeInterval now = [[NSDate date] timeIntervalSince1970];
    NSDateFormatter * formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyyMMddHHmmss"];
    NSDate * NowDate = [NSDate dateWithTimeIntervalSince1970:now];
    
    NSString * timeStr = [formatter stringFromDate:NowDate];
    NSString *allStr = [NSString stringWithFormat:@"%@-%@",picOrVideoName,timeStr];
    NSString *fileName = [NSString stringWithFormat:@"/%@.%@",allStr,fileType];
//    NSLog(@"fileName == %@",fileName);
    return fileName;
}

- (NSDictionary *)getTodayDate
{
    NSDate *today = [NSDate date];
    /* 日历类 */
    NSCalendar *calendar = [NSCalendar currentCalendar];
    /* 日历构成的格式 */
    NSCalendarUnit unit = kCFCalendarUnitYear|kCFCalendarUnitMonth|kCFCalendarUnitDay;
    /* 获取对应的时间点 */
    NSDateComponents *components = [calendar components:unit fromDate:today];
    
    NSString *year = [NSString stringWithFormat:@"%ld", (long)[components year]];
    NSString *month = [NSString stringWithFormat:@"%02ld", (long)[components month]];
    NSString *day = [NSString stringWithFormat:@"%02ld", (long)[components day]];
    
    NSMutableDictionary *todayDic = [[NSMutableDictionary alloc] init];
    [todayDic setObject:year forKey:@"year"];
    [todayDic setObject:month forKey:@"month"];
    [todayDic setObject:day forKey:@"day"];
    return todayDic;
}

#pragma mark - 取得一个目录下得所有mp4视频文件名

- (NSArray *)getmp4VideoArray_with_deviceID:(NSString *)deviceID
{
    NSArray *files = [fileManager subpathsAtPath:[self getTakeVideoDocPath_with_deviceID:deviceID]];
    NSMutableArray *file = [files mutableCopy];
    if ([deviceID isEqualToString:@""]) {
        [files enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            NSString *name = (NSString *)obj;
            if (![name containsString:@"mp4"]) {
                [file removeObject:obj];
            }
        }];
    }
    // 倒序输出，最新的在最前面
    NSArray *reversedArray = [[file reverseObjectEnumerator] allObjects];
    return reversedArray;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self.view endEditing:YES];
}

#pragma mark - 回放视频

- (IBAction)rebackAction:(id)sender
{
    rebackView.alpha = 1;
    [UIView animateWithDuration:0.25 animations:^{
        self->replayViewCY.constant = 0;
    }];
}

- (IBAction)cancel:(UIButton *)sender
{
    if (sender.tag == 10) {
        
        if (rebackView_Path.text.length == 0) {
            imageView.image = nil;
            /// 注册回放回调
            [self setPlaybackAudioVideoDataCallBack_with_deviceID:rebackView_ID.text reBlock:^(const char *uuid, int type, unsigned char *data, int len, long timestamp) {}];
            int ret = IPCNetStartPlaybackAtTimeR(rebackView_ID.text.UTF8String,
                                                 0,
                                                 [rebackView_Date.text intValue],
                                                 [rebackView_Time.text intValue],
                                                 OnStarPlayback_timeLine_CmdResult);
            NSLog(@"播放时间轴回放视频 IPCNetStartPlaybackAtTimeR，ret = %d",ret);
        }
        else {
            [self setPlaybackAudioVideoDataCallBack_with_deviceID:rebackView_ID.text reBlock:^(const char *uuid, int type, unsigned char *data, int len, long timestamp) {}];
            int ret = IPCNetStartPlaybackR(rebackView_ID.text.UTF8String, rebackView_Path.text.UTF8String, OnStartPlaybackCmdResult);
            NSLog(@"播放回放浏览列表的视频 IPCNetStartPlaybackAtTimeR，ret = %d",ret);
        }
    }
    else {
        rebackView.alpha = 0;
        [UIView animateWithDuration:0.25 animations:^{
            self->replayViewCY.constant = -250;
        }];
        int ret = IPCNetStopPlaybackR(rebackView_ID.text.UTF8String, OnGetStopPlaybackCmdResult);
        NSLog(@"停止视频回放stopPlayback_with_deviceID，ret = %d",ret);
    }
}

void OnGetStopPlaybackCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnGetStopPlaybackCmdResult %s cmd:%d uuid:%s json:%s\n",__func__,cmd, uuid, json);
}

void OnStartPlaybackCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnStartPlaybackCmdResult %s cmd:%d uuid:%s json:%s\n",__func__,cmd, uuid, json);
}

void OnStarPlayback_timeLine_CmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnStartPlaybackCmdResult %s cmd:%d uuid:%s json:%s\n",__func__,cmd, uuid, json);
}

- (void)setPlaybackAudioVideoDataCallBack_with_deviceID:(NSString *)deviceID reBlock:(playBackVideoOrAudioDataRetultBlock)reBlock
{
    int ret = IPCNetSetPlaybackAudioVideoDataCallBack(deviceID.UTF8String, OnSetPlaybackAudioVideoDataCallBackCmdResult);
    NSLog(@"注册回放回调，ret = %d",ret);
}

void OnSetPlaybackAudioVideoDataCallBackCmdResult(const char*uuid,int type,unsigned char*data,int len,long timestamp)
{
    if (type < 20 || type >= 50) {
        // h264 + h265
        NSLog(@"thread = %@",[NSThread currentThread]);
        [h26xDecode decodeH26xVideoData:data videoSize:len frameType:type timestamp:timestamp];
    }
}

#pragma mark - 下载报警图片

- (IBAction)downloadAlarmPic:(id)sender
{
    NSString *deviceID = @"IPCKF0001M7WAFQK";
    NSString *fileName = @"/mnt/s0/pic/vi0/202010/17/11/5222.md.*";
    NSString *path = @"/var/mobile/Containers/Data/Application/4EC3FAC8-C01D-4265-900D-EFCFB4B564C5/Documents/AlarmPic/IPCKF0001M7WAFQK/2020-10-17_115158.*";
    [self downloadPicWith:deviceID fileName:fileName path:path];
}

- (void)downloadPicWith:(NSString *)deviceID fileName:(NSString *)fileName path:(NSString *)path
{
#pragma mark - 文件传输协议
    int ret1 = IPCNetGetFileFromDevice(deviceID.UTF8String, fileName.UTF8String, path.UTF8String, OnGetFileFromDeviceCmdResult);
#pragma mark - 注册文件传输回调
    int ret2 = IPCNetSetFileTransferProgressCallback(deviceID.UTF8String, OnGetFileTransferProgressCallbackCmdResult);
    NSLog(@"文件传输协议 IPCNetGetFileFromDevice，ret1 = %d，ret2 = %d",ret1,ret2);
}

void OnGetFileFromDeviceCmdResult(int cmd,const char*uuid,const char*json)
{
    NSLog(@"OnGetFileFromDeviceCmdResult %s cmd:%d uuid:%s json:%s\n",__func__,cmd, uuid, json);
    NSDictionary *dict = [ViewController cString_changto_ocStringWith1:json];
    NSLog(@"dict = %@",dict);
    int ret = [dict[@"FileTransfer"][@"Transfer.Get"][@"Ret"] intValue];
    if (ret < 0) {
        NSLog(@"图片下载失败");
        dispatch_async(dispatch_get_main_queue(), ^{
            [[NSNotificationCenter defaultCenter] postNotificationName:@"TTDownloadFailedAlarmPicFromDevice_Key" object:nil];
        });
    }
}

+ (NSDictionary *)cString_changto_ocStringWith1:(const char *)cString
{
    NSString *json = [[NSString alloc] initWithUTF8String:cString];
    if (json == nil) {
        json = [NSString stringWithFormat:@"%s",cString];
        if ([json isEqualToString:@""]) {
            return nil;
        }
        NSData *jsonData    = [json dataUsingEncoding:NSUTF8StringEncoding];
        NSDictionary *body  = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:nil];
        return body;
    }
    NSData *jsonData    = [json dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *body  = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:nil];
    return body;
}

void OnGetFileTransferProgressCallbackCmdResult(int sor, const char*uuid,const char *file, int progress, int transferedSize)
{
    NSLog(@"OnSetDeviceIndicatorCmdResult %s sor:%d uuid:%s file:%s progress:%d transferedSize:%d\n",__func__,sor, uuid, file, progress, transferedSize);
    
    if (progress >= 100) {
//        NSString *fileName = TTStr(@"%s",file);
//        if ([fileName containsString:@"jpg"]) {
//            TLog(@"jpg 图片");
//        }
//        else if ([fileName containsString:@"i265"]) {
//            dispatch_async(dispatch_get_main_queue(), ^{
//                NSString *newFilePath = [fileName stringByReplacingOccurrencesOfString:@"i265" withString:@"jpg"];
//                [[NSNotificationCenter defaultCenter] postNotificationName:@"DownloadAlarmPic_Noti" object:@[fileName, newFilePath, @"36"]];
//                TLog(@"265 图片");
//            });
//        }
//        else if ([fileName containsString:@"i264"]) {
//            dispatch_async(dispatch_get_main_queue(), ^{
//                NSString *newFilePath = [fileName stringByReplacingOccurrencesOfString:@"i264" withString:@"jpg"];
//                [[NSNotificationCenter defaultCenter] postNotificationName:@"DownloadAlarmPic_Noti" object:@[fileName, newFilePath, @"35"]];
//                TLog(@"264 图片");
//            });
//        }
    }
    NSLog(@"图片下载 progress = %d%% ",progress);
    dispatch_async(dispatch_get_main_queue(), ^{
        [[NSNotificationCenter defaultCenter] postNotificationName:@"TTDownloadAlarmPicFromDevice_Key" object:@(progress)];
    });
}

@end


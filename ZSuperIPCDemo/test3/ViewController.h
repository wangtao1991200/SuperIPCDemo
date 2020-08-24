//
//  ViewController.h
//  test3
//
//  Created by YangFeixiang on 2018/4/5.
//  Copyright © 2018年 fenzhi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import "H26xHwDecoder.h"
#import "XBAudioUnitPlayer.h"
#import "XBAudioUnitRecorder.h"

typedef enum : NSUInteger {
    KHJLiveRecordType_Normal = 0,
    KHJLiveRecordType_Recording,
    KHJLiveRecordType_stopRecoding,
} KHJLiveRecordType;

@interface ViewController : UIViewController
{
    IBOutlet UICollectionView   *imgColView;
    struct IPCNetEventHandler ipcnetHandle;
}

@property (weak, nonatomic) IBOutlet UITextField *textviewuuid;
@property (weak, nonatomic) IBOutlet UIButton *connectBtn;
@property (weak, nonatomic) IBOutlet UIButton *playBtn;
@property (weak, nonatomic) IBOutlet UILabel *statusLabel;
@property (weak, nonatomic) IBOutlet UIButton *disconnectBtn;
@property (weak, nonatomic) IBOutlet UIButton *playaudioBtn;
@property (weak, nonatomic) IBOutlet UIButton *searchBtn;
@property (weak, nonatomic) IBOutlet UIButton *stopvideoBtn;
@property (weak, nonatomic) IBOutlet UIButton *stopaudioBtn;
@property (weak, nonatomic) IBOutlet UIButton *GetOSDBtn;
@property (weak, nonatomic) IBOutlet UIButton *SetOSDBtn;
@property (weak, nonatomic) IBOutlet UIButton *GetAlarmBtn;
@property (weak, nonatomic) IBOutlet UIButton *SetAlarmBtn;

@end


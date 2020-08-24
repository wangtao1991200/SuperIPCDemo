/*
* filename:JSONStructProtocal.h
* author:hujian
* date:2017/12/03 11:03
*/
#ifndef __JSON_STRUCT_PROTOCAL_H__
#define __JSON_STRUCT_PROTOCAL_H__
#include "JSONObject.hpp"

using namespace std;
#include<list>

#if _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

typedef char          T_S8;
typedef short int         T_S16;
typedef int         T_S32;
typedef long long         T_S64; 

typedef unsigned char        T_U8;
typedef unsigned short int       T_U16;
typedef unsigned int       T_U32;
typedef unsigned long long        T_U64;
#ifndef __APPLE__
typedef int BOOL;
#endif

typedef enum{
	IPCNET_LOGIN_REQ = 1000,
	IPCNET_LOGIN_RESP,

	IPCNET_KEEPALIVE_REQ,
	IPCNET_KEEPALIVE_RESP,

	IPCNET_STREAM_REQ,
	IPCNET_STREAM_RESP,

	IPCNET_TALK_REQ,
	IPCNET_TALK_RESP,

	IPCNET_FORCELOGOUT_REQ,
	IPCNET_FORCELOGOUT_RESP,

    IPCNET_STREAM_EX_REQ,
    IPCNET_STREAM_EX_RESP,
    
	IPCNET_NET_SYSINFO_REQ = 1020,
	IPCNET_NET_SYSINFO_RESP,

	IPCNET_USER_SET_REQ,
	IPCNET_USER_SET_RESP,

	IPCNET_MCU_INFO_REQ,
	IPCNET_MCU_INFO_RESP,

	IPCNET_GET_WIFI_AP_INFO_REQ = 1026,
	IPCNET_GET_WIFI_AP_INFO_RESP,
	
	IPCNET_SET_WIFI_AP_INFO_REQ = 1028,
	IPCNET_SET_WIFI_AP_INFO_RESP,
	
	IPCNET_ETH_SET_REQ = 1040,  //IPCNetEthConfig_st
	IPCNET_ETH_SET_RESP,
	
    IPCNET_ETH_GET_REQ = 1042,
    IPCNET_ETH_GET_RESP,    //IPCNetEthConfig_st
    
    IPCNET_NETWORK_MOBILE_SET_REQ = 1044, //Ipcnet3GInfo_st
    IPCNET_NETWORK_MOBILE_SET_RESP,

    IPCNET_NETWORK_MOBILE_GET_REQ = 1046,
    IPCNET_NETWORK_MOBILE_GET_RESP, //Ipcnet3GInfo_st

    IPCNET_NETWORK_WIFI_SET_REQ = 1048, //IPCNetWirelessConfig_st
    IPCNET_NETWORK_WIFI_SET_RESP,
    
    IPCNET_NETWORK_WIFI_GET_REQ = 1050,
    IPCNET_NETWORK_WIFI_GET_RESP,   //IPCNetWirelessConfig_st
    
    IPCNET_NETWORK_WIFI_SEARCH_GET_REQ = 1052,
    IPCNET_NETWORK_WIFI_SEARCH_GET_RESP,  //IpcnetNetworkWirelessSearch_st

    IPCNET_VIDEO_ENC_SET_REQ = 1054,    //IPCNetVideoEncodeCfg_st
    IPCNET_VIDEO_ENC_SET_RESP,

    IPCNET_VIDEO_ENC_GET_REQ = 1056,
    IPCNET_VIDEO_ENC_GET_RESP,  //IPCNetVideoEncodeCfg_st
    
    IPCNET_AUDIO_ENC_SET_REQ = 1058,   //IpcnetAudioEncodeCfg_st
    IPCNET_AUDIO_ENC_SET_RESP,

    IPCNET_AUDIO_ENC_GET_REQ = 1060,
    IPCNET_AUDIO_ENC_GET_RESP,  //IpcnetAudioEncodeCfg_st

    IPCNET_PTZ_GET_REQ = 1062,  //δ��
    IPCNET_PTZ_GET_RESP,    //δ��

    IPCNET_PTZ_SET_REQ = 1064,     //IPCPtzCtrlMsg_st
    IPCNET_PTZ_SET_RESP,
    
    IPCNET_MOVE_ALARM_SET_REQ = 1066, //IPCNETMoveCellAlarmCfg_st
    IPCNET_MOVE_ALARM_SET_RESP,

    IPCNET_MOVE_ALARM_GET_REQ = 1068,
    IPCNET_MOVE_ALARM_GET_RESP,

	IPCNET_AV_RECO_CONF_SET_REQ = 1070,
    IPCNET_AV_RECO_CONF_SET_RESP,

    IPCNET_AV_RECO_CONF_GET_REQ = 1072,
    IPCNET_AV_RECO_CONF_GET_RESP,

	IPCNET_AV_RECO_LIST_GET_REQ = 1074,
    IPCNET_AV_RECO_LIST_GET_RESP,

	IPCNET_AV_RECO_LIST_PAGE_GET_REQ = 1076,
    IPCNET_AV_RECO_LIST_PAGE_GET_RESP,

	IPCNET_AV_RECO_OP_REQ = 1078,
    IPCNET_AV_RECO_OP_RESP,     // 1079

	IPCNET_UPGRADE_REQ = 1080,
	IPCNET_UPGRADE_RESP,

	IPCNET_GET_GPIO_REQ = 1082,
	IPCNET_GET_GPIO_RESP,
	
	IPCNET_SET_GPIO_REQ = 1084,
	IPCNET_SET_GPIO_RESP,

	IPCNET_GET_SUBDEV_REQ = 1086,
	IPCNET_GET_SUBDEV_RESP,
	
	IPCNET_SET_SUBDEV_REQ = 1088,
	IPCNET_SET_SUBDEV_RESP,

	IPCNET_GET_BUS_REQ = 1090,
	IPCNET_GET_BUS_RESP,
	
	IPCNET_SET_BUS_REQ = 1092, //����͸��
	IPCNET_SET_BUS_RESP,    // 1093

	IPCNET_GET_DEV_INFO_REQ = 1094,
	IPCNET_GET_DEV_INFO_RESP,

	IPCNET_SET_DEV_INFO_REQ = 1096,
	IPCNET_SET_DEV_INFO_RESP,
	
	IPCNET_UPGRADE_CFG_REQ = 1098,
	IPCNET_UPGRADE_CFG_RESP,
	
	IPCNET_UPGRADE_AUTO_SET_REQ = 1100,
	IPCNET_UPGRADE_AUTO_SET_RESP,
	
	IPCNET_SET_DEFAULT_REQ = 1102,
    IPCNET_SET_DEFAULT_RESP,

	IPCNET_SET_REBOOT_REQ = 1104,
    IPCNET_SET_REBOOT_RESP,
    
    IPCNET_GET_NET_PORT_REQ = 1106,
    IPCNET_GET_NET_PORT_RESP,
    
    IPCNET_SET_NET_PORT_REQ = 1108,
    IPCNET_SET_NET_PORT_RESP,

	IPCNET_GET_GPIO_ARRAY_REQ = 1110,
	IPCNET_GET_GPIO_ARRAY_RESP,
	
	IPCNET_SET_GPIO_ARRAY_REQ = 1112,
	IPCNET_SET_GPIO_ARRAY_RESP,

    IPCNET_GET_MOTION_DETECT_REQ = 1114,
    IPCNET_GET_MOTION_DETECT_RESP,
    
    IPCNET_SET_MOTION_DETECT_REQ = 1116,
    IPCNET_SET_MOTION_DETECT_RESP,

	IPCNET_WIFI_STATUS_REPORT_RESP = 1201,       // 1201

    IPCNET_VIDEO_IFRAME_REQ = 1202,   //IPCNetVideoIFrame_st
    IPCNET_VIDEO_IFRAME_RESP,

    IPCNET_GET_VIDEO_QULITY_LEVEL_REQ = 1204,
    IPCNET_GET_VIDEO_QULITY_LEVEL_RESP,
    
    IPCNET_SET_VIDEO_QULITY_LEVEL_REQ = 1206,
    IPCNET_SET_VIDEO_QULITY_LEVEL_RESP,
    
    IPCNET_GET_NETWORKS_STATUS_REQ = 1208,
    IPCNET_GET_NETWORKS_STATUS_RESP,
	
	IPCNET_NET_CFG_PTZ_REQ = 1400,
	IPCNET_NET_CFG_PTZ_RESP,

	IPCNET_GET_TIME_REQ = 1402,
	IPCNET_GET_TIME_RESP,
	
	IPCNET_SET_TIME_REQ = 1404, //IPCNetTimeCfg_st
	IPCNET_SET_TIME_RESP,   //1405

    IPCNET_NET_PRESET_SET_PTZ_REQ = 1406,
	IPCNET_NET_PRESET_SET_PTZ_RESP, //IPCNetTimeCfg_st

    IPCNET_NET_PRESET_GET_PTZ_REQ = 1408,      
	IPCNET_NET_PRESET_GET_PTZ_RESP,

	//---����PC�ƹ�(��ͨ����) 
	IPCNET_GET_LAMP_REQ = 1410,
	IPCNET_GET_LAMP_RESP,
	
	IPCNET_SET_LAMP_REQ = 1412,
	IPCNET_SET_LAMP_RESP,

	//----ͼ��ת
	IPCNET_GET_OVERTURN_REQ = 1414,
	IPCNET_GET_OVERTURN_RESP,       //1415
	
	IPCNET_SET_OVERTURN_REQ = 1416,	
	IPCNET_SET_OVERTURN_RESQ,	
	
	/**�����ع�����**/
	IPCNET_GET_EXPOSURE_TYPE_REQ = 1418,
	IPCNET_GET_EXPOSURE_TYPE_RESP,
	
	IPCNET_SET_EXPOSURE_TYPE_REQ = 1420,
	IPCNET_SET_EXPOSURE_TYPE_RESP,

	/**�Զ��ع�**/
	IPCNET_GET_AUTO_EXPOSURE_REQ = 1422,
	IPCNET_GET_AUTO_EXPOSURE_RESP,

	IPCNET_SET_AUTO_EXPOSURE_REQ = 1424,
	IPCNET_SET_AUTO_EXPOSURE_RESP,      //1425

	/**�ֶ��ع�**/
	IPCNET_GET_MANUAL_EXPOSURE_REQ = 1426,
	IPCNET_GET_MANUAL_EXPOSURE_RESP,

	IPCNET_SET_MANUAL_EXPOSURE_REQ = 1428,
	IPCNET_SET_MANUAL_EXPOSURE_RESP,

	//----��ת�ڷ�ʽ
	IPCNET_GET_PICOLOR_REQ = 1430,	 /*��ȡ��ת��*/         //1430
	IPCNET_GET_PICOLOR_RESP,
	
	IPCNET_SET_PICOLOR_REQ = 1432, /*���ò�ת��*/
	IPCNET_SET_PICOLOR_RESP, 
	
	//----��������
	IPCNET_GET_ENVIRONMENT_REQ = 1434,		/*��ȡ����*///1--outdoorģʽ 0--indoorģʽ
	IPCNET_GET_ENVIRONMENT_RESP,
	
	IPCNET_SET_ENVIRONMENT_REQ = 1436,		/*���û���*///1--outdoorģʽ 0--indoorģʽ
	IPCNET_SET_ENVIRONMENT_RESP,

	//---2D/3D����
	IPCNET_GET_DENOISE_REQ = 1438,		/*1438 ��ȡ2D/3D ����*/	
	IPCNET_GET_DENOISE_RESP,
	
	IPCNET_SET_DENOISE_REQ = 1440,	/*����2D/3D ����*/          //1440
	IPCNET_SET_DENOISE_RESP,        

	//v1---��̬����
	IPCNET_GET_WDR_REQ = 1442,		/* 1442 ��ȡWDR*/
	IPCNET_GET_WDR_RESP,
	
	IPCNET_SET_WDR_REQ = 1444,		/*����WDR*/
	IPCNET_SET_WDR_RESP,		//1445

	//--��ƽ��
	IPCNET_GET_WH_BLANCE_REQ = 1446,
	IPCNET_GET_WH_BLANCE_RESP,
	
	IPCNET_SET_WH_BLANCE_REQ = 1448,
	IPCNET_SET_WH_BLANCE_RESP,

	//--��֡
	IPCNET_GET_SLOW_FRAME_RATE_REQ = 1450,
	IPCNET_GET_SLOW_FRAME_RATE_RESP,     
	
	IPCNET_SET_SLOW_FRAME_RATE_REQ = 1452,
	IPCNET_SET_SLOW_FRAME_RATE_RESP,
	
	//--����Ĭ��ֵ
	IPCNET_GET_EXPOSURE_DEFAULT_REQ = 1454,		//δ�õ�
	IPCNET_GET_EXPOSURE_DEFAULT_RESP,       //1455
	
	IPCNET_SET_EXPOSURE_DEFAULT_REQ = 1456,      
	IPCNET_SET_EXPOSURE_DEFAULT_RESP,

	//--����У��
	IPCNET_GET_BADPIXEL_DETECT_REQ = 1458, 	//δ�õ�
	IPCNET_GET_BADPIXEL_DETECT_RESP,
	
	IPCNET_SET_BADPIXEL_DETECT_REQ = 1460,
	IPCNET_SET_BADPIXEL_DETECT_RESP,       
	
	IPCNET_GET_ANTIFLICKER_REQ = 1462,	 	/*1462 ��ȡ������*/	
	IPCNET_GET_ANTIFLICKER_RESP,
	
	IPCNET_SET_ANTIFLICKER_REQ = 1464,		 /*���ÿ�����*/
	IPCNET_SET_ANTIFLICKER_RESP,        //1465
	
	//wdr v2---����������������ɾ��������Ӱ����������
	IPCNET_GET_RESERVE_REQ = 1466,		
	IPCNET_GET_RESERVE_RESP,
	
	IPCNET_SET_RESERVE_REQ = 1468,		
	IPCNET_SET_RESERVE_RESP,

	//----�Զ���ת���ֶ����ù���ֵ
	IPCNET_GET_PICOLOR4MANUlUAM_REQ = 1470,
	IPCNET_GET_PICOLOR4MANUlUAM_RESP,   
	
	IPCNET_SET_PICOLOR4MANUlUAM_REQ = 1472, 
	IPCNET_SET_PICOLOR4MANUlUAM_RESP,

    IPCNET_SNAP_SHOOT_REQ = 1474,
	IPCNET_SNAP_SHOOT_RESP,     //1475

    //Ԥ�õ�
	IPCNET_GET_PREPOINT_REQ = 1476,
	IPCNET_GET_PREPOINT_RESP,       //1477    

	IPCNET_SET_PREPOINT_REQ = 1478,
	IPCNET_SET_PREPOINT_RESP,       //1479
    
	IPCNET_OPERATE_PREPOINT_REQ = 1480,
	IPCNET_OPERATE_PREPOINT_RESP,       //1481

    //ftp��������
	IPCNET_SET_FTP_CFG_REQ = 1482,
	IPCNET_SET_FTP_CFG_RESP,

	IPCNET_GET_FTP_CFG_REQ = 1484,
	IPCNET_GET_FTP_CFG_RESP,        //1485

    /***Email cfg***/
	IPCNET_SET_EMAIL_CFG_REQ = 1486,
	IPCNET_SET_EMAIL_CFG_RESP,

	IPCNET_GET_EMAIL_CFG_REQ = 1488,
	IPCNET_GET_EMAIL_CFG_RESP,

    /***Ddns cfg***/
	IPCNET_SET_DDNS_CFG_REQ = 1490,
	IPCNET_SET_DDNS_CFG_RESP,

	IPCNET_GET_DDNS_CFG_REQ,
	IPCNET_GET_DDNS_CFG_RESP,

    /***�������ȣ��Աȶȣ����Ͷ�***/
	IPCNET_SET_CAM_PIC_CFG_REQ = 1494,
	IPCNET_SET_CAM_PIC_CFG_RESP,        //1495

	IPCNET_GET_CAM_PIC_CFG_REQ = 1496,
	IPCNET_GET_CAM_PIC_CFG_RESP,

	/****IRCUT�л�****/
	IPCNET_SET_IRCUT_REQ = 1498,
	IPCNET_SET_IRCUT_RESP,

	IPCNET_GET_IRCUT_REQ = 1500,
	IPCNET_GET_IRCUT_RESP,

	IPCNET_ALARM_REPORT_RESP = 1502,       // 1502�����ϴ�������Ϣ

    /****OSD cfg****/
	IPCNET_SET_OSD_REQ = 1503,
	IPCNET_SET_OSD_RESP = 1504,
    
	IPCNET_GET_OSD_REQ = 1505,
	IPCNET_GET_OSD_RESP = 1506,

	IPCNET_FORMAT_EXFAT_REQ = 1507,
	IPCNET_FORMAT_EXFAT_RESP,

	IPCNET_BINARY_DATA_MSG_REQ =   1509, //������������Ϣ
	IPCNET_BINARY_DATA_MSG_RESP,

	IPCNET_START_REMOTE_DEBUG_MSG_REQ = 1511, //����Զ�̵���
	IPCNET_START_REMOTE_DEBUG_MSG_RESP,

	IPCNET_END_REMOTE_DEBUG_MSG_REQ = 1513, //�ر�Զ�̵���
	IPCNET_END_REMOTE_DEBUG_MSG_RESP,

	IPCNET_GET_FUNC_CFG_REQ = 1515, //���ܲ�����ȡ
	IPCNET_GET_FUNC_CFG_RESP,    

    IPCNET_SET_FUNC_CFG_REQ = 1517, //���ܲ�������
	IPCNET_SET_FUNC_CFG_RESP,    

	IPCNET_GET_STA_LED_CFG_REQ = 1519, //��ȡ�Ƶ�ʹ��״̬
	IPCNET_GET_STA_LED_CFG_RESP,

    IPCNET_SET_STA_LED_CFG_REQ = 1521, //���õƵ�ʹ��
	IPCNET_SET_STA_LED_CFG_RESP,

    IPCNET_GET_DET_LUM_AREA_CFG_REQ = 1523, //��ȡ�������ȼ�����
    IPCNET_GET_DET_LUM_AREA_CFG_RESP,       

    IPCNET_SET_DET_LUM_AREA_CFG_REQ = 1525, //�����������ȼ�����
    IPCNET_SET_DET_LUM_AREA_CFG_RESP,  

    IPCNET_DISK_TEST_REQ = 1527, //disk����
    IPCNET_DISK_TEST_RESP,

    IPCNET_SET_P2P_SER_CODE_REQ = 1529, //����p2p����������
    IPCNET_SET_P2P_SER_CODE_RESP,

    IPCNET_GET_P2P_SER_CODE_REQ = 1531,        // 1531 ��ȡp2p����������
    IPCNET_GET_P2P_SER_CODE_RESP,

	IPCNET_GET_NETWORK_STRATEGY_REQ=1533,         // 1533 --������Ի�ȡ
	IPCNET_GET_NETWORK_STRATEGY_RESP,

	IPCNET_SET_NETWORK_STRATEGY_REQ=1535,         // 1535 --�����������
	IPCNET_SET_NETWORK_STRATEGY_RESP,

    IPCNET_GET_TIMER_CFG_REQ = 1537,       //��ȡ��ʱ������
    IPCNET_GET_TIMER_CFG_RESP,

    IPCNET_SET_TIMER_CFG_REQ = 1539,       //��ȡ��ʱ������
    IPCNET_SET_TIMER_CFG_RESP,

    IPCNET_GET_DISK_CFG_REQ = 1541,        //��ȡ���̲���
    IPCNET_GET_DISK_CFG_RESP,

    IPCNET_GET_TIMEZONE_CFG_REQ = 1543, //ʱ��������ʱ IPCNetTimeZoneCfg_st
    IPCNET_GET_TIMEZONE_CFG_RESP,

    IPCNET_SET_TIMEZONE_CFG_REQ = 1545, //ʱ��������ʱ IPCNetTimeZoneCfg_st
    IPCNET_SET_TIMEZONE_CFG_RESP,

    
    
    //---------------����������Ҫ��sdkЭ�����չ����������Э��----------
    IPCNET_INTERNEL_MSG_TYPE = 3000,

	REMOTE_MSG_LOGIN=3001,

    IPCNET_GET_USER_ALL_INFO_REQ = 3002,
    IPCNET_GET_USER_ALL_INFO_RESP,  //IPCNetGetUserGroupCfg_st

    IPCNET_GET_USER_INFO_REQ = 3004,    //IPCNetUserInfoReq_st
    IPCNET_GET_USER_INFO_RESP,  //IPCNetUserInfo_st
    
	IPCNET_GET_STREAM_REQ = 3006,

    IPCNET_SET_USER_INFO_REQ = 3006,    //IPCNetUserInfo_st
    IPCNET_SET_USER_INFO_RESP,

    IPCNET_GET_SYS_INFO = 3008,      //IPCNetCamInfo_st    
    IPCNET_GET_SYS_INFO_RESP,
    
    IPCNET_MSG_TYPE_BUTT = 4000,
	REMOTE_MSG_RESP_LOGIN = 4003,
}IPCNET_NET_MSG_TYPE_e;
typedef enum
{
    IPCNET_RET_OK,      //0�ɹ�
    
	_IPCNET_RET_OK_ = 100,     //����ǲ��õ�
	IPCNET_NET_RET_UNKNOWN,          //�����������101��ʼ
	IPCNET_NET_RET_VERSION_NOT_SUPPORT,
	IPCNET_RET_REQ_ILLEGAL,
	IPCNET_NET_RET_LOGIN_EXSIST,

	IPCNET_RET_UNLOGIN = 105, //5
	IPCNET_RET_PASSWARD_ERR,
	IPCNET_RET_UNAUTHORISED,
	IPCNET_RET_TIMEOUT,
	IPCNET_RET_NOT_FOUND,

    IPCNET_RET_USER_NOT_FOUND = 110,
	IPCNET_RET_PASSWARD_NULL,
	IPCNET_NET_RET_FIND_AND_SEND_OVER = 112,
	IPCNET_NET_RET_FIND_AND_SEND_APART,
	IPCNET_RET_SENDBUF_MEM_NOTENOUGH = 114,

	IPCNET_NET_RET_NEED_RESTART_APP = 602,
	IPCNET_NET_RET_NEED_RESTART_SYS,
	IPCNET_NET_RET_WRITE_FILE_ERR,
	
	IPCNET_NET_RET_REQ_NOT_SUPPORT = 605,
	IPCNET_NET_RET_NEED_VERIFY_ERR,
	IPCNET_NET_RET_NEED_CONFIG_UNEXIST,
	IPCNET_NET_RET_NEED_PASER_ERR,
	IPCNET_RET_NO_MEM,

	IPC_NET_RET_UPDATING = 610,
	IPC_NET_RET_OPERATE_BUSYING,
	IPCNET_RET_USER_NAME_TOO_LONG,
	IPCNET_RET_PASSWD_TOO_LONG,
	
	IPCNET_NET_RET_REQ_ID_UNKNOWN = 1001,
	IPCNET_NET_RET_REQ_UNKNOWN,

	IPCNET_RET_FORMAT_FAIL =1050,
	
	IPCNET_NET_RET_NULL = 0xFFFFFF, //���ֵ������Э�鷶Χ����Ϊ���ô�����on_ipcnet_msg_process()֪������������첽�ģ����������ظ���
}IPCNET_NET_RETURN_CODE_e;

#define STREAM_TYPE_VIDEO 0x01      //������Ƶ
#define STREAM_TYPE_AUDIO 0x02      //������Ƶ
#define STREAM_TYPE_COMP 0x03       //����������
#define DECODE_TYPE_VIDEO 0x04       //������Ƶ
#define DECODE_TYPE_AUDIO 0x08       //������Ƶ
#define DECODEM_TYPE_COMP 0x0c       //����������

//ptz control command ---------------------------------
enum PTZ_CONTROL_COMMAND{
	IPCNET_PTZ_UP = 0,
	IPCNET_PTZ_UP_STOP=1,
	IPCNET_PTZ_DOWN=2,    // 2
	IPCNET_PTZ_DOWN_STOP=3,
	IPCNET_PTZ_LEFT=4,    // 4
	IPCNET_PTZ_LEFT_STOP=5,
	IPCNET_PTZ_RIGHT=6,   // 6
	IPCNET_PTZ_RIGHT_STOP=7,
	IPCNET_PTZ_ZOOM_IN=8,     //8 �Ŵ�
	IPCNET_PTZ_ZOOM_OUT=9,    //9--��С
	IPCNET_PTZ_ZOOM_STOP=10,       // 10
	IPCNET_PTZ_FOCUS_FAR=11,       // 11--Զ��
	IPCNET_PTZ_FOCUS_NEAR=12,      // 12 --����
	IPCNET_PTZ_FOCUS_STOP=13,
	IPCNET_PTZ_SELF_CHECK=14,      //��̨�Լ�

	IPCNET_PTZ_UP_DOWN=15,          //����Ѳ��
	IPCNET_PTZ_LEFT_RIGHT=16,       //����Ѳ��
	IPCNET_AF_ZOOM_POSITION=17,       //AF�䱶��λ

	IPCNET_PTZ_UP_LEFT,
    IPCNET_PTZ_UP_LEFT_STOP,
    IPCNET_PTZ_UP_RIGHT,
    IPCNET_PTZ_UP_RIGHT_STOP,
    IPCNET_PTZ_DOWN_LEFT,
    IPCNET_PTZ_DOWN_LEFT_STOP,
    IPCNET_PTZ_DOWN_RIGHT,
    IPCNET_PTZ_DOWN_RIGHT_STOP,
};

typedef enum
{
	AV_RECO_OP_PLAY_REQ = 0,
	AV_RECO_OP_PLAY_RESP = 1,
//			AV_RECO_OP_PAUSE,

	AV_RECO_OP_LEFT_REQ = 2,
	AV_RECO_OP_LEFT_RESP = 3,

	AV_RECO_OP_RIGHT_REQ = 4,
	AV_RECO_OP_RIGHT_RESP = 5,

	AV_RECO_OP_STOP_REQ = 6,
	AV_RECO_OP_STOP_RESP = 7,

	AV_RECO_OP_SEEK_REQ = 8,
	AV_RECO_OP_SEEK_RESP = 9,
	//=========File Operation=============
	AV_RECO_OP_DOWNLOAD_FILE_REQ = 10,
	AV_RECO_OP_DOWNLOAD_FILE_RESP = 11,
	
	AV_RECO_OP_FILE_ATTRIBUTE_REQ = 12,
	AV_RECO_OP_FILE_ATTRIBUTE_RESP = 13,
	
	AV_RECO_OP_DELETE_FILE_REQ = 14,
	AV_RECO_OP_DELETE_FILE_RESP = 15,
	
	AV_RECO_OP_SET_RECORDER_CONFIG_REQ = 16,
	AV_RECO_OP_SET_RECORDER_CONFIG_RESP = 17,
	
	AV_RECO_OP_GET_RECORDER_CONFIG_REQ = 18,
	AV_RECO_OP_GET_RECORDER_CONFIG_RESP = 19,
	
	AV_RECO_OP_PLAY_PAUSE_REQ = 20,      //20-��ͣ
	AV_RECO_OP_PLAY_PAUSE_RESP = 21,
}REMOTE_FILE_OPERATION_ENUM;

typedef enum
{
	AUDIO_ADPCM = 20,
	AUDIO_G711A,
	AUDIO_G711U,
	AUDIO_G726,
	AUDIO_AMR,	
	AUDIO_ACC,
}AUDIO_TYPE;

typedef struct{
	int Start;
	int End;
}ValueRange_t;

#define CMD_TYPE_START  0x01        //��ʼ��������
#define CMD_TYPE_STOP   0x02        //������������
#define CMD_TYPE_START_EX  0x03        //��ʼ��������

//���ݰ�ͷ
typedef struct PKT_HEAD
{
    T_U32 frame_no;//����֡���
    T_U32  frame_size; //����֡����
    T_U8  frame_type;//֡����
    T_U8  pkt_no;//С֡���
    T_U16 pkt_size;//С֡����
    //������HI3512ȡ֡ʱʱ��� U64 �ֽ��
    T_U32 sec;
    T_U32 usec;
}PKT_HEAD_t;

typedef struct P2P_PKT_HEAD
{
    T_U32 signature;
    PKT_HEAD_t pkt_hd;
}P2P_PKT_HEAD_t;

struct VIDEO_BUF_HEAD
{
    unsigned int head; /* ͷ���������0xFF00FF */
    unsigned int timestamp; //ʱ����������¼������¼���ʱ����������ʵʱ��Ƶ����Ϊ0
    unsigned int len;    /*����*/
    unsigned char frametype;
	unsigned char streamid;
	unsigned char sessid;
	unsigned char version;
	unsigned int frameno; /*֡��*/
	unsigned short milistamp;/*2014.4.24������ʵʱ��Ƶʱ�������λ����*/	
};

#define SEPCAM_MOST_STR_VAR_LEN 32
#define MSG_HARD_BUF_LEN (1000)
#define MSG_START_SIGNATURE_LEN 4
#define MSG_START_SIGNATURE 0x55aabbcc
#define MAX_FRAME_LENGTH 2097152

//�豸�˺�PC��ͨѶЭ��<H>//protocol:Э��
typedef struct MSG_HEAD
{
	T_U32 msg_signature;
    T_U16  msg_type;
    //T_U16  ext_msg_type;
	T_U8 pkt_num;
	T_U8 pkt_id;

    T_U32  guid;
    T_U32  result;//0��ʾ�ɹ��������Ĵ����1��ʼ
    T_U32  version;//(V 1.0.0)
    
    T_U32  msg_head_len;//sizeof(msg_head) + ��չ���ȣ�;
    T_U32  msg_len;//(msg_head_len + ʵ�����ݳ��� )��
    T_U32  timestamp;
    T_U32 sequence;//���к�
    
    T_S8   dev_id[SEPCAM_MOST_STR_VAR_LEN];

    T_S8  tlv_num;	//�����TLV�ṹ�ģ����ֶ�ΪTLV����������������
    T_S8  res[7];
}MSG_HEAD_t;

//void SEPCAM_BuildMsgHdReq(void *buf, unsigned CmdType, unsigned guid, unsigned BodyLen, unsigned Sequence, char *DevID,int pkt_num,int pkt_id);
void SEPCAM_BuildMsgHdReq(void *buf, unsigned CmdType, unsigned guid,unsigned char pkt_num,unsigned char pkt_id, unsigned BodyLen, unsigned Sequence, char *DevID);
int BuildLoginReqMsg(char *pMsg, char *sUserName, char *sPassword);

class MSG_LOGIN_t
{
public:
	String user;//�û�����
	String passwd;//md5���ܺ������
	int interval;//�������ʱ��
	int utc;
	int parseJSON(JSONObject &jsdata){
	    int ret=1;
		JSONObject *jsroot= jsdata.getJSONObject("MSG_LOGIN_t");
		if(jsroot){
			ret &= jsroot->getString("user",user);
			ret &= jsroot->getString("passwd",passwd);
			ret &= jsroot->getInt("interval",interval);
			delete jsroot;
			return ret;
		}
		return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();

		JSONObject jsethnetwork;// = new JSONObject();
		jsethnetwork.put("user", user);
		jsethnetwork.put("passwd", passwd);
		jsethnetwork.put("interval", interval);
		jsethnetwork.put("utc", utc);
		jsroot.put("MSG_LOGIN_t", jsethnetwork);
		jsroot.toString(str);
		return str.length();
	}
};

typedef struct REQUEST_STREAM_CMD
{
	T_U8   channel;        //�����ͨ��0
	T_U8	 flag;			 //0����������1��������, 2: ֻ����Ƶ
	T_U8   stream_type;    //֡���ͣ���Ƶ��.��Ƶ������������1
	T_U8   cmd_type;       //�������ͣ���ʼ����,��������1
	T_U32    reserve;        //�����ֶ�
	Boolean_t parseJSON(JSONObject jsdata){
	    int ret=1;
		int value;
		JSONObject *jsroot= jsdata.getJSONObject("REQUEST_STREAM_CMD_t");
		if(jsroot){
			ret &= jsroot->getInt("channel",value);channel=value;
			ret &= jsroot->getInt("flag",value);flag=value;
			ret &= jsroot->getInt("stream_type",value);stream_type=value;
			ret &= jsroot->getInt("cmd_type",value);cmd_type=value;
			ret &= jsroot->getInt("reserve",value);reserve=value;
		
			delete jsroot;
			return true;
		}
		return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();

		JSONObject jsrsc;
		jsrsc.put("channel", (int)channel);
		jsrsc.put("flag", (int)flag);
		jsrsc.put("stream_type", (int)stream_type);
		jsrsc.put("cmd_type", (int)cmd_type);
		jsrsc.put("reserve", (int)reserve);
		jsroot.put("REQUEST_STREAM_CMD_t", jsrsc);
		jsroot.toString(str);
		return str.length();
	}
}REQUEST_STREAM_CMD_t;

typedef struct IPCNetCamColorCfg{
	Boolean_t SetDefault;    //�Ƿ�����Ĭ��ֵ
	int ViCh;//max=3
	int Brightness;//max=255 def:0
	int Chroma;//max=255 def:0
	int Contrast;//max=255 def:0x80
	    
	int Saturtion;//max=255 def:0
	int Acutance;//max=255 def:0
	IPCNetCamColorCfg(){
		SetDefault = false;
		ViCh=0;//max=3
		Brightness=-1;//max=255 def:0
		Chroma=-1;//max=255 def:0
		Contrast=-1;//max=255 def:0x80
	    
		Saturtion=-1;//max=255 def:0
		Acutance=-1;//max=255 def:0
	}
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("CamCfg.info");
		if(jsroot){
			jsroot->getInt("ViCh",ViCh);
			jsroot->getInt("Brightness",Brightness);
			jsroot->getInt("Chroma",Chroma);
			jsroot->getInt("Contrast",Contrast);
			jsroot->getInt("Saturtion",Saturtion);
			jsroot->getInt("Acutance",Acutance);
		
			delete jsroot;
			return true;
		}
		return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;
		
		JSONObject jsresult;
		jsresult.put("SetDefault",SetDefault);
		jsresult.put("ViCh",ViCh);
		jsresult.put("Brightness",Brightness);
		jsresult.put("Chroma",Chroma);
		jsresult.put("Contrast",Contrast);
		jsresult.put("Saturtion",Saturtion);
		jsresult.put("Acutance",Acutance);

		jsroot.put("CamCfg.info", jsresult);
		
		jsroot.toString(str);
			
		return str.length();
	}

	Boolean_t isValueValid(){
		return Acutance>=0 && Brightness>=0 && Chroma>=0 && 
			Contrast>=0 && Saturtion>=0 && Acutance>=0;
	}
}IPCNetCamColorCfg_st;

typedef struct IPCNetPicOverTurn{
	int ViCh;//max=3
	int Mirror;
	int Flip;

	IPCNetPicOverTurn(){
		ViCh=0;//max=3
	}
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("IspOverTurn.info");

		if(jsroot){
			jsroot->getInt("ViCh",ViCh);
			jsroot->getInt("Mirror",Mirror);
			jsroot->getInt("Flip",Flip);
		
			delete jsroot;
			return true;
		}
	    return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;
		
		JSONObject jsresult;
		jsresult.put("ViCh",ViCh);
		jsresult.put("Flip",Flip);
		jsresult.put("Mirror",Mirror);

		jsroot.put("IspOverTurn.info", jsresult);
		
		jsroot.toString(str);
			
		return str.length();
	}
}IPCNetPicOverTurn_st;
typedef struct IPCNetTime_st{
	int Hour;
	int Min;
	int Sec;
}IPCNetTime_st;
typedef struct IPCNetDate_st{
	int Year;
	int Mon;
	int Day;
}IPCNetDate_st;
typedef struct IPCNetTimeCfg{
	IPCNetDate_st *Date;
	IPCNetTime_st *Time;
	Boolean_t NtpEnable;
	String NtpServ;
	int TimeZone;
	IPCNetTimeCfg(){
		Date = new IPCNetDate_st();
		Time = new IPCNetTime_st();
	}
	~IPCNetTimeCfg(){
		delete Date;
		delete Time;
	}
	Boolean_t parseJSON(JSONObject &jsdata){
		int value;
		JSONObject *jsroot= jsdata.getJSONObject("Time.Conf");
		if(jsroot){
			Boolean_t bv;
			jsroot->getBoolean("NtpEnable",bv);
			NtpEnable = bv;
			jsroot->getString("NtpServ",NtpServ);
			jsroot->getInt("TimeZone",value);
			TimeZone = value;
					
			JSONObject *jsTime = jsroot->getJSONObject("Time");
			jsTime->getInt("Hour",value);
			Time->Hour = value;
			jsTime->getInt("Min",value);
			Time->Min = value;
			jsTime->getInt("Sec",value);
			Time->Sec = value;
					
			JSONObject *info = jsroot->getJSONObject("Date");
			info->getInt("Day",value);
			Date->Day = value;
			info->getInt("Mon",value);
			Date->Mon = value;
			info->getInt("Year",value);
			Date->Year = value;

			delete jsroot;
			return true;
		}
	    return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;

		JSONObject jsresult;
				
		jsresult.put("NtpEnable", NtpEnable);
		jsresult.put("NtpServ", NtpServ);
		jsresult.put("TimeZone",TimeZone);
				
		JSONObject jsTime;
		jsTime.put("Hour", Time->Hour);
		jsTime.put("Min", Time->Min);
		jsTime.put("Sec", Time->Sec);
		jsresult.put("Time", jsTime);
				
		JSONObject info;
		info.put("Day",Date->Day);
		info.put("Mon",Date->Mon);
		info.put("Year",Date->Year);
		jsresult.put("Date", info);
				
		jsroot.put("Time.Conf", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetTimeCfg_st;
typedef struct IPCNetRecordGetCfg{
	int ViCh;//sensor index.
	String Path;
	Boolean_t parseJSON(JSONObject &jsdata){
	    JSONObject *jsroot= jsdata.getJSONObject("Rec.Conf");
		if(jsroot!=0){
			jsroot->getInt("ViCh",ViCh);
			jsroot->getString("Path",Path);

			delete jsroot;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();

		JSONObject jresult;// = new JSONObject();
		jresult.put("ViCh", ViCh);
		jresult.put("Path", Path);
				
		jsroot.put("Rec.Conf", jresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetRecordGetCfg_st;
typedef struct DiskInfo{
	unsigned int Total;
	unsigned int Free;
	String Path;
	Boolean_t isValid;
	int Type;
}DiskInfo_st;
typedef struct{
    int Start;
    int End;
}IPCNetPeriod_st;
typedef struct RecTime{
	RecTime(){
		En=0;
		St1="00:00:00";
		Ed1="23:59:59";
		St2="00:00:00";
		Ed2="23:59:59";
		Enable=0;
		Period.clear();
	}
	~RecTime(){
		for(list<IPCNetPeriod_st*>::iterator it= Period.begin(); it!=Period.end(); ){
			IPCNetPeriod_st *rfi = *it;
			it++;
			free(rfi);
		}
	}
	//-----------------------------  new protocal  -----------------------------------
	Boolean_t Enable;
    int Day;//0:Everyday 1:Monday 2:Tuesday
    list<IPCNetPeriod_st*> Period;
	int PeriodMaxCnt;

	//-----------------------------  old protocal  -----------------------------------
	//startx->"00:00:00",endx->"23:59:59"
	//You can set any piece of time into this field, such as startx->"09:00:00",endx->"21:00:00"
	//startx is lower then endx
	int En;//enable
	String St1;//start 1
	String Ed1;//end 1
	String St2;
	String Ed2;
}RecTime_st;

//VeCh: record main(0) stream or sub(1) stream
//RecMins: record duration, please pick up one of the time from the RecMinsOption in the json struct feedback from OnCmdResult_t which can trigger by IPCNetGetRecordR
//ReserveSize:how many disk size would you want to reserve
typedef struct IPCNetRecordCfg{
	int newProtocal;//0:old protocal 1:new protocal

	Boolean_t Enable;
	int ViCh;//sensor index.
	int VeCh;
	DiskInfo_st *DiskInfo;
	int RecMinsOptionNum;
	int RecMinsOption[32];
	int RecMins;//set with index of RecMinsOption
	int Mode;//0:auto mode 1:manual mode
	Boolean_t AutoDel;
	RecTime_st *RecTime[8];//0:every day 1:Monday 2:Tuesday
	int PackageType;
	int ReserveSize;
	IPCNetRecordCfg(){
		int i;
		DiskInfo=new DiskInfo_st;
		for(i=0;i<8;i++){
			RecTime[i]=new RecTime_st;
		}
		newProtocal=0;
		Enable=0;
	}
	~IPCNetRecordCfg(){
		int i;
		delete DiskInfo;
		for(i=0;i<8;i++){
			delete RecTime[i];
		}
	}
	Boolean_t parseJSON(JSONObject &jsdata){
	    JSONObject *jsroot= jsdata.getJSONObject("Rec.Conf");
		if(jsroot!=0){
			int value;
			if(jsroot->getInt("ViCh",ViCh)==0){
				if(jsroot->getInt("Vi",ViCh)==1){
					newProtocal=1;
				}
			}
			if(jsroot->getBoolean("Enable",Enable)==1){
				newProtocal=1;
			}
			jsroot->getInt("Mode",Mode);

			JSONObject *jsDiskInfo=jsroot->getJSONObject("DiskInfo");
			if(jsDiskInfo){
				jsDiskInfo->getInt("Free",value);
				DiskInfo->Free=value;
				jsDiskInfo->getInt("Total",value);
				DiskInfo->Total=value;
				jsDiskInfo->getString("Path",DiskInfo->Path);

				jsDiskInfo->getBoolean("isValid",DiskInfo->isValid);

				jsDiskInfo->getInt("Type",DiskInfo->Type);

				delete jsDiskInfo;
			}
			jsroot->getInt("RecMins",value);
			RecMins=value;
			JSONArray*jsaRecMinsOption=jsroot->getJSONArray("RecMinsOption");
			if(jsaRecMinsOption){
				int rl=jsaRecMinsOption->getLength();
				RecMinsOptionNum=rl;
				rl=rl>32?32:rl;
				for(int i=0;i<rl;i++){
					jsaRecMinsOption->getInt(i,value);
					RecMinsOption[i]=value;
				}

				delete jsaRecMinsOption;
			}
			if(newProtocal==1){
				jsroot->getInt("Ch",VeCh);
			}else{
				jsroot->getInt("VeCh",VeCh);
				
			}
			jsroot->getBoolean("AutoDel",AutoDel);
			jsroot->getInt("PackageType",PackageType);
			jsroot->getInt("ReserveSize",ReserveSize);

			JSONArray*jsaRecTime=jsroot->getJSONArray("RecTime");
			if(jsaRecTime){
				int i;
				for(i=0;i<jsaRecTime->getLength();i++){
					JSONObject*jsRt=jsaRecTime->getJSONObject(i);
					if(jsRt){
						if(newProtocal ==1){
							int day=0;
							if(jsRt->getInt("Day",day)==1){
								if(day<7){
									int j;
									RecTime_st *tm = RecTime[day];
									tm->Day = day;
									jsRt->getInt("PeriodMaxCnt",tm->PeriodMaxCnt);
									tm->Enable = 0;
									JSONArray*jsPeriod = jsRt->getJSONArray("Period");
									if(jsPeriod){
										tm->Enable = jsPeriod->getLength()>0;
										for(j=0;j<tm->PeriodMaxCnt&&j<jsPeriod->getLength();j++){
											JSONObject *jsper = jsPeriod->getJSONObject(j);
											if(jsper){
												IPCNetPeriod_st*per = new IPCNetPeriod_st();
												jsper->getInt("Start", per->Start);
												jsper->getInt("End", per->End);
												tm->Period.push_back(per);
												delete jsper;
											}
										}
										delete jsPeriod;
									}
								}
							}
						}else{
							jsRt->getInt("En",RecTime[i]->En);
							jsRt->getString("St1",RecTime[i]->St1);
							jsRt->getString("Ed1",RecTime[i]->Ed1);
							jsRt->getString("St2",RecTime[i]->St2);
							jsRt->getString("Ed2",RecTime[i]->Ed2);
						}
						delete jsRt;
					}
				}
				delete jsaRecTime;
			}

			delete jsroot;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;

		JSONObject jresult;
		if(newProtocal==1){
			jresult.put("Vi", ViCh);
			jresult.put("Ch", VeCh);
		}else{
			jresult.put("ViCh", ViCh);
			jresult.put("VeCh", VeCh);
		}
		jresult.put("Mode", Mode);
		jresult.put("AutoDel", AutoDel);
		jresult.put("PackageType", PackageType);
		jresult.put("ReserveSize", ReserveSize);
		jresult.put("RecMins", RecMins);
		JSONObject jsDiskInfo;
		//no need
		//jresult.put("DiskInfo",jsDiskInfo);
		JSONArray jsaRecMinsOption;
		//no need
		//jresult.put("RecMinsOption",jsaRecMinsOption);

		JSONArray jsaRecTime;
		int i;
		for(i=0;i<8;i++){
			JSONObject jsRt;
			if(newProtocal==1){
				if(RecTime[i]->Enable==1){
					jsRt.put("Day", i);
					JSONArray jsPeriod;
					int j=0;
					for(list<IPCNetPeriod_st*>::iterator it= RecTime[i]->Period.begin(); it!=RecTime[i]->Period.end(); it++){
						IPCNetPeriod_st *rfi = *it;
						JSONObject jsPer;
						jsPer.put("Start", rfi->Start);
						jsPer.put("End", rfi->End);
						jsPeriod.put(j++, jsPer);
					}
					jsRt.put("Period", jsPeriod);
				}
			}else{
				jsRt.put("En",RecTime[i]->En);
				jsRt.put("St1",RecTime[i]->St1);
				jsRt.put("Ed1",RecTime[i]->Ed1);
				jsRt.put("St2",RecTime[i]->St2);
				jsRt.put("Ed2",RecTime[i]->Ed2);
			}
			jsaRecTime.put(i,jsRt);
		}
		jresult.put("RecTime",jsaRecTime);
				
		jsroot.put("Rec.Conf", jresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetRecordCfg_st;

typedef struct IPCNetEthConfig{
	Boolean_t DhcpEnble;
	String IP;
	String Netmask;
	String Getway;
	String DNS1;
	String DNS2;
	Boolean_t parseJSON(JSONObject &jsdata){

		JSONObject *jsroot = jsdata.getJSONObject("NetWork.Eth");
		if(jsroot){
			jsroot->getBoolean("DhcpEnble",DhcpEnble);
			jsroot->getString("IP",IP);
			jsroot->getString("Netmask",Netmask);
			jsroot->getString("Getway",Getway);
			jsroot->getString("DNS1",DNS1);
			jsroot->getString("DNS2",DNS2);

			delete jsroot;
			return true;
		}
		return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsethnetwork;// = new JSONObject();
		jsethnetwork.put("DhcpEnble", DhcpEnble);
		jsethnetwork.put("IP", IP);
		jsethnetwork.put("Netmask", Netmask);
		jsethnetwork.put("Getway", Getway);
		jsethnetwork.put("DNS1", DNS1);
		jsethnetwork.put("DNS2", DNS2);
		jsroot.put("NetWork.Eth", jsethnetwork);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetEthConfig_st;
typedef struct IPCNetWirelessConfig{
	Boolean_t WirelessEnable;
	int WirelessStatus;
	String SsidSetMode;
	String EncType;
	String SSID;
	String Password;
	Boolean_t DhcpEnble;
	String IP;
	String Netmask;
	String Getway;
	Boolean_t parseJSON(JSONObject &jsdata){
	   
		JSONObject *jsroot= jsdata.getJSONObject("NetWork.Wireless");
		if(jsroot){
			Boolean_t wirelessenale;
			jsroot->getBoolean("WirelessEnable",wirelessenale);
			WirelessEnable=wirelessenale;
			jsroot->getInt("WirelessStatus",WirelessStatus);
			jsroot->getString("EncType",EncType);
			jsroot->getString("SSID",SSID);
			jsroot->getString("Password",Password);

			Boolean_t dhcpenale;
			jsroot->getBoolean("DhcpEnble",dhcpenale);
			DhcpEnble=dhcpenale;
			jsroot->getString("IP",IP);
			jsroot->getString("Netmask",Netmask);
			jsroot->getString("Getway",Getway);

			jsroot->getString("SsidSetMode",SsidSetMode);

			delete jsroot;
			return true;
		}
		return false;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		jsresult.put("WirelessEnable", WirelessEnable);
		jsresult.put("WirelessStatus", WirelessStatus);
		jsresult.put("SsidSetMode", SsidSetMode);
		jsresult.put("EncType", EncType);
		jsresult.put("SSID", SSID);
		jsresult.put("Password", Password);
		jsresult.put("DhcpEnble", DhcpEnble);
		jsresult.put("IP", IP);
		jsresult.put("Netmask", Netmask);
		jsresult.put("Getway", Getway);
		jsroot.put("NetWork.Wireless", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetWirelessConfig_st;
typedef enum IPCNET_MOBILE_STATUS{
	IPCNET_MOBILE_MODULE_NOT_SUPPORT = 0,//��֧��
	IPCNET_MOBILE_MODULE_UNINITIALIZED,//δ��ʼ��
	IPCNET_MOBILE_MODULE_SEEKING_DEV,//������Ѱ�豸
    IPCNET_MOBILE_MODULE_DEV_NO_FOUND,//δ��⵽�ƶ�����ģ��
	IPCNET_MOBILE_MODULE_POWER_OFF,//�ƶ�ģ���ѹػ�
	IPCNET_MOBILE_MODULE_DEV_FOUND,//5//��⵽�ƶ�ģ��
	IPCNET_MOBILE_MODULE_DETECTING_SIM_CARD,//���ڼ��SIM��
	IPCNET_MOBILE_MODULE_NO_SIM_CARD,//��SIM��
	IPCNET_MOBILE_MODULE_SIM_CARD_DETECTED,//��⵽SIM��
	IPCNET_MOBILE_MODULE_NO_SIGNAL,//���ź�
	IPCNET_MOBILE_MODULE_SIGNAL_DETECTED,//10//���ź�
	IPCNET_MOBILE_MODULE_NOT_CONNECT,//δ��������
	IPCNET_MOBILE_MODULE_DAILING,//12//������
    IPCNET_MOBILE_MODULE_DAIL_FAILED,//����ʧ��
    IPCNET_MOBILE_MODULE_DAIL_SUCCESS,//���ųɹ�
    IPCNET_MOBILE_MODULE_DOING_DHCP,//15//���ڻ�ȡIP
    IPCNET_MOBILE_MODULE_DHCP_FAILED,//get IP failed//��ȡIPʧ��
	IPCNET_MOBILE_MODULE_NETWORK_READY,//17 got IP, ready to use it//IP������ȷ
	IPCNET_MOBILE_MODULE_USING_NETWORK,//added into route path//����·��ѡ����ȷ������ʹ���ƶ�����
	IPCNET_MOBILE_MODULE_OFFLINE,//����
}IPCNET_MOBILE_STATUS_et;
typedef struct IPCNetMobileNetworkInfo{
	int protocal;//0,1,2...

	//protocal == 0
	Boolean_t enable;	//ʹ��3gģ�飬0-����Ч��1-��Ч
	int type;		// 3Gģ�����ͣ�0-����evdo,1-��ͨwcdma
	String ip;	// 3Gģ���ȡ��IP��ַ
	String vpn;
	String name;

	//protocal == 1
	Boolean_t AutoAPN;
    String APN;
    String Account;
    String Passwd;

    int Status;//IPCNET_MOBILE_STATUS_et
    String NetType;//mobile network supplier and network type,for example:CMNET-TD-LTE,UNICOM-WCDMA
    int RSSI;//percent rate

    String IP;    // 3Gģ���ȡ��IP��ַ
    String Netmask;
    String Gateway;
    String DNS1;
    String DNS2;
	IPCNetMobileNetworkInfo(){
		protocal=1;
		AutoAPN=true;
	}
	Boolean_t parseJSON(JSONObject &jsdata){
	    
		JSONObject *jsroot= jsdata.getJSONObject("Net.Mobile");
		if(jsroot){
			int ret = jsroot->getInt("type",type);
			Boolean_t bv;
			if(ret == 1){
				protocal = 0;
				jsroot->getBoolean("enable",bv);
				enable = bv;
				jsroot->getString("ip",ip);
				jsroot->getString("vpn",vpn);
				jsroot->getString("name",name);
			}else{
				ret = jsroot->getBoolean("AutoAPN",bv);
				if(ret == 1){
					protocal = 1;
					AutoAPN = bv;
					jsroot->getString("APN",APN);
					jsroot->getString("Account",Account);
					jsroot->getString("Passwd",Passwd);
					jsroot->getInt("Status",Status);
					jsroot->getString("NetType",NetType);
					jsroot->getInt("RSSI",RSSI);
					jsroot->getString("IP",IP);
					jsroot->getString("Netmask",Netmask);
					jsroot->getString("Gateway",Gateway);
					jsroot->getString("DNS1",DNS1);
					jsroot->getString("DNS2",DNS2);
				}
			}
			delete jsroot;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		if(protocal == 1){
			jsresult.put("AutoAPN", AutoAPN);
			jsresult.put("APN", APN);
			jsresult.put("Account", Account);
			jsresult.put("Passwd", Passwd);
		}else if(protocal == 0){//old protocal
			jsresult.put("type", type);
			jsresult.put("enable", enable);
			jsresult.put("ip", ip);
			jsresult.put("name", name);
			jsresult.put("vpn", vpn);
		}
		jsroot.put("Net.Mobile", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetMobileNetworkInfo_st;
typedef struct IPCNetWifiApItem{
	/* IPCNetWifiApItem(){
		SSID=0;
		EncType=0;
	}
	~IPCNetWifiApItem(){
		if(SSID){
			delete SSID;
		}
		if(EncType){
			delete EncType;
		}
	}
	char* SSID;
	char* EncType; */
	String SSID;
	String EncType;
	int RSSI;
}IPCNetWifiApItem_st;
typedef struct IPCNetWifiAplist{
	IPCNetWifiApItem_st **ApItem;// = new IPCNetWifiApItem[1];
	int num;
	IPCNetWifiAplist(){
		ApItem=0;
		num=0;
	}
	~IPCNetWifiAplist(){
		if(ApItem){
            NSLog(@"222222222222222222222222222222222");
			for(int i=0;i<num;i++){
				delete ApItem[i];
			}
			delete[] ApItem;
		}
	}
	Boolean_t parseJSON(JSONObject &jsdata){
	    
            NSLog(@"AplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplistAplist");
			JSONObject *jsroot= jsdata.getJSONObject("NetWork.WirelessSearch");
			if(jsroot){
				JSONArray *Aplist = jsroot->getJSONArray("Aplist");
				if(Aplist){
					int apcount = Aplist->getLength();
					num=apcount;
					//Log.d(TAG,"ap num:" + apcount);
					ApItem = new IPCNetWifiApItem_st*[apcount];

					for(int i=0;i<apcount;i++){
						ApItem[i] = new IPCNetWifiApItem_st;
						JSONObject *ap = Aplist->getJSONObject(i);
						if(ap){
							//IPCNetWifiApItem_st *apitem = new IPCNetWifiApItem();
							ap->getString("SSID",ApItem[i]->SSID);
							ap->getString("EncType",ApItem[i]->EncType);
							ap->getInt("RSSI",ApItem[i]->RSSI);
							//ApItem[i] = apitem;
							delete ap;
						}
					}
					delete Aplist;
				}
				delete jsroot;
			}
		
	    return true;
	}
	int toJSONString(String&str){
		str="";
		return 0;
	}
}IPCNetWifiAplist_st;

typedef struct IPCNetOsdConf_st{
	Boolean_t Enable;       //�Ƿ�����
	int DisplayMode;  //�����뱳���Ƿ�ɫ��0-����ɫ��1-��ɫ
	int Xcord;        //x����0-704
	int Ycord;        //y����0-576
}IPCNetOsdConf_st;

typedef struct IPCNetOsdName_st{
	String NameText;
	IPCNetOsdConf_st *NameConf;
	IPCNetOsdName_st(){
		NameText="";
		NameConf = new IPCNetOsdConf_st();
	}
	~IPCNetOsdName_st(){
		delete NameConf;
	}
}IPCNetOsdName_st;

typedef enum{
	OSD_FUNC_TYPE_DATETIME,
	OSD_FUNC_TYPE_BITRATE,
	OSD_FUNC_TYPE_SIGNAL,
	OSD_FUNC_TYPE_DEV_NAME,
	OSD_FUNC_TYPE_BAT_CAPACITY,
	OSD_FUNC_TYPE_CHARGE_FLAG,
	OSD_FUNC_TYPE_REC_FLAG,
	OSD_FUNC_TYPE_STRING,
	OSD_FUNC_TYPE_BUTT,
}OSD_FUNC_TYPE_et;
typedef struct  //ͨ��ʱ����ʾ������Ϣ
{
    Boolean_t Enable;       //�Ƿ�����
    int Id;//osd id, 0:���OSD���Զ�����ID��>0:����OSD
    OSD_FUNC_TYPE_et Type;//Time, Bitrate, Signal...
    int DisplayMode;  //��ʾ�ĸ�ʽ����2016/08/ ����2016-08��
    int X;        //x����0-704
    int Y;        //y����0-576
    
	//�ַ���ֵ��������Ͳ���Ҫ�������
    String Str;//ֻ�����û��Զ���OSD �� �豸�� ����Ч
}IPCNetOsdElementCfg_st;

const inline static char *get_osd_type_string(OSD_FUNC_TYPE_et type)
{
	if(type == OSD_FUNC_TYPE_DATETIME){
		return "Time";
	}else if(type == OSD_FUNC_TYPE_BITRATE){
		return "Bitrate";
	}else if(type == OSD_FUNC_TYPE_SIGNAL){
		return "Signal";
	}else if(type == OSD_FUNC_TYPE_BAT_CAPACITY){
		return "BatCapacity";
	}else if(type == OSD_FUNC_TYPE_CHARGE_FLAG){
		return "ChargeFlag";
	}else if(type == OSD_FUNC_TYPE_REC_FLAG){
		return "RecFlag";
	}else if(type == OSD_FUNC_TYPE_DEV_NAME){
		return "DevName";
	}else if(type == OSD_FUNC_TYPE_STRING){
		return "UserStr";
	}
	return NULL;
}
inline static OSD_FUNC_TYPE_et get_osd_string_type(const char*type)
{
	if(strcmp(type, "Time")==0){
		return OSD_FUNC_TYPE_DATETIME;
	}else if(strcmp(type, "Bitrate")==0){
		return OSD_FUNC_TYPE_BITRATE;
	}else if(strcmp(type, "Signal")==0){
		return OSD_FUNC_TYPE_SIGNAL;
	}else if(strcmp(type, "BatCapacity")==0){
		return OSD_FUNC_TYPE_BAT_CAPACITY;
	}else if(strcmp(type, "ChargeFlag")==0){
		return OSD_FUNC_TYPE_CHARGE_FLAG;
	}else if(strcmp(type, "RecFlag")==0){
		return OSD_FUNC_TYPE_REC_FLAG;
	}else if(strcmp(type, "DevName")==0){
		return OSD_FUNC_TYPE_DEV_NAME;
	}else if(strcmp(type, "UserStr")==0){
		return OSD_FUNC_TYPE_STRING;
	}
	return OSD_FUNC_TYPE_BUTT;
}

typedef struct IPCNetOsdCfg_st{
	//��Ҫ�ָ�OSD���õ�ʱ������SetDefault=1������SetDefault=0��������������Ч
	Boolean_t SetDefault;//�¾ɰ汾����Ч
	int Vich;//�¾ɰ汾����Ч

	int NewProtocol;//ֻ������Э�黹����Э��

//new protocol/��Э��
	Boolean_t Enable;
	list<IPCNetOsdElementCfg_st*> OsdCfg;
	int UserDefMaxNum;
	list<String> OsdOption;

//old protocol/��Э�飬��app�ԽӲ�������Э����
	IPCNetOsdName_st *OsdNameInfo;
	IPCNetOsdConf_st *OsdDateInfo;
	IPCNetOsdConf_st *OsdRateInfo;
//---------------- old protocol/��Э����� --------------------

	IPCNetOsdCfg_st(){
		NewProtocol=0;
		OsdCfg.clear();
		OsdNameInfo = new IPCNetOsdName_st();
		OsdDateInfo = new IPCNetOsdConf_st();
		OsdRateInfo = new IPCNetOsdConf_st();
	}
	~IPCNetOsdCfg_st(){
		delete OsdNameInfo;
		delete OsdDateInfo;
		delete OsdRateInfo;
		for(list<IPCNetOsdElementCfg_st*>::iterator it= OsdCfg.begin(); it!=OsdCfg.end(); ){
			IPCNetOsdElementCfg_st *rfi = *it;
			it++;
			free(rfi);
		}
		OsdCfg.clear();
	}
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot = jsdata.getJSONObject("OsdCfg.info");
		if(jsroot){
			jsroot->getBoolean("SetDefault",SetDefault);
			jsroot->getInt("Vich",Vich);

			jsroot->getBoolean("Enable",Enable);
			jsroot->getInt("UserDefMaxNum",UserDefMaxNum);

			JSONArray *jsOsdCfg = jsroot->getJSONArray("OsdCfg");
			if(jsOsdCfg){
				NewProtocol = 1;//��Э��
				int num = jsOsdCfg->getLength();
				int i;
				for(i=0;i<num;i++){
					JSONObject *jscfg = jsOsdCfg->getJSONObject(i);
					if(jscfg){
						IPCNetOsdElementCfg_st *element = new IPCNetOsdElementCfg_st();
						String typestr;
						jscfg->getBoolean("Enable",element->Enable);
						jscfg->getString("Type", typestr);
						element->Type = get_osd_string_type(typestr.c_str());
						jscfg->getInt("Id",element->Id);
						jscfg->getInt("DisplayMode",element->DisplayMode);
						if(element->Type == OSD_FUNC_TYPE_DEV_NAME || element->Type == OSD_FUNC_TYPE_STRING)
						jscfg->getString("Str", element->Str);
						jscfg->getInt("X",element->X);
						jscfg->getInt("Y",element->Y);
						OsdCfg.push_back(element);
						delete jscfg;
					}
				}
				delete jsOsdCfg;
			}
			JSONArray *jsOsdOption = jsroot->getJSONArray("OsdOption");
			if(jsOsdOption){
				int num = jsOsdOption->getLength();
				int i;
				for(i=0;i<num;i++){
					String typestr;
					jsOsdOption->getString(i, typestr);
					OsdOption.push_back(typestr);
				}
				delete jsOsdOption;
			}
			
			if(NewProtocol == 0){
				JSONObject *jsOsdNameInfo = jsroot->getJSONObject("OsdNameInfo");
				if(jsOsdNameInfo){
					jsOsdNameInfo->getString("NameText",OsdNameInfo->NameText);

					JSONObject *jsOsdNameInfo_NameConf = jsOsdNameInfo->getJSONObject("NameConf");
					if(jsOsdNameInfo_NameConf){
						jsOsdNameInfo_NameConf->getBoolean("Enable",OsdNameInfo->NameConf->Enable);       //�Ƿ�����
						jsOsdNameInfo_NameConf->getInt("DisplayMode",OsdNameInfo->NameConf->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
						jsOsdNameInfo_NameConf->getInt("Xcord",OsdNameInfo->NameConf->Xcord);        //x����0-704
						jsOsdNameInfo_NameConf->getInt("Ycord",OsdNameInfo->NameConf->Ycord);
						delete jsOsdNameInfo_NameConf;
					}
					delete jsOsdNameInfo;
				}
				    
				JSONObject *jsOsdDateInfo = jsroot->getJSONObject("OsdDateInfo");
				if(jsOsdDateInfo){
					jsOsdDateInfo->getBoolean("Enable",OsdDateInfo->Enable);       //�Ƿ�����
					jsOsdDateInfo->getInt("DisplayMode",OsdDateInfo->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
					jsOsdDateInfo->getInt("Xcord",OsdDateInfo->Xcord);        //x����0-704
					jsOsdDateInfo->getInt("Ycord",OsdDateInfo->Ycord);
					delete jsOsdDateInfo;
				}
					
				JSONObject *jsOsdRateInfo = jsroot->getJSONObject("OsdRateInfo");
				if(jsOsdRateInfo){
					jsOsdRateInfo->getBoolean("Enable",OsdRateInfo->Enable);       //�Ƿ�����
					jsOsdRateInfo->getInt("DisplayMode",OsdRateInfo->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
					jsOsdRateInfo->getInt("Xcord",OsdRateInfo->Xcord);        //x����0-704
					jsOsdRateInfo->getInt("Ycord",OsdRateInfo->Ycord);
					delete jsOsdRateInfo;
				}
			}

			delete jsroot;
		}else{
			return false;
		}

	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		jsresult.put("Vich", Vich);
		jsresult.put("SetDefault",SetDefault);
		
		if(NewProtocol==1){
			if(SetDefault==0){
				jsresult.put("Enable",Enable);
				
				int i=0;
				JSONArray jsOsdCfg;
				for(list<IPCNetOsdElementCfg_st*>::iterator it= OsdCfg.begin(); it!=OsdCfg.end(); it ++){
					IPCNetOsdElementCfg_st *rfi = *it;
					JSONObject jselement;
					jselement.put("Enable",rfi->Enable);
					const char*type = get_osd_type_string(rfi->Type);
					if(type)
					jselement.put("Type", type);
					jselement.put("Id",rfi->Id);
					jselement.put("DisplayMode",rfi->DisplayMode);
					if(rfi->Type == OSD_FUNC_TYPE_DEV_NAME || rfi->Type == OSD_FUNC_TYPE_STRING){
						jselement.put("Str",rfi->Str);
					}
					jselement.put("X",rfi->X);
					jselement.put("Y",rfi->Y);
					jsOsdCfg.put(i, jselement);
					i++;
				}
				jsresult.put("OsdCfg",jsOsdCfg);

				jsroot.put("OsdCfg.info", jsresult);
			}
		}else{
			//old protocol
			JSONObject jsOsdNameInfo;// = new JSONObject();

			jsOsdNameInfo.put("NameText",OsdNameInfo->NameText);
			
			JSONObject jsOsdNameInfo_NameConf;// = new JSONObject();
			jsOsdNameInfo_NameConf.put("Enable",OsdNameInfo->NameConf->Enable);       //�Ƿ�����
			jsOsdNameInfo_NameConf.put("DisplayMode",OsdNameInfo->NameConf->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
			jsOsdNameInfo_NameConf.put("Xcord",OsdNameInfo->NameConf->Xcord);        //x����0-704
			jsOsdNameInfo_NameConf.put("Ycord",OsdNameInfo->NameConf->Ycord);
			jsOsdNameInfo.put("NameConf",jsOsdNameInfo_NameConf);
				
			jsresult.put("OsdNameInfo",jsOsdNameInfo);
				
			JSONObject jsOsdDateInfo;// = new JSONObject();
			jsOsdDateInfo.put("Enable",OsdDateInfo->Enable);       //�Ƿ�����
			jsOsdDateInfo.put("DisplayMode",OsdDateInfo->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
			jsOsdDateInfo.put("Xcord",OsdDateInfo->Xcord);        //x����0-704
			jsOsdDateInfo.put("Ycord",OsdDateInfo->Ycord);
			jsresult.put("OsdDateInfo",jsOsdDateInfo);
				
			JSONObject jsOsdRateInfo;// = new JSONObject();
			jsOsdRateInfo.put("Enable",OsdRateInfo->Enable);       //�Ƿ�����
			jsOsdRateInfo.put("DisplayMode",OsdRateInfo->DisplayMode);  //�����뱳���Ƿ�ɫ��0-�����٣�1-��ɫ
			jsOsdRateInfo.put("Xcord",OsdRateInfo->Xcord);        //x����0-704
			jsOsdRateInfo.put("Ycord",OsdRateInfo->Ycord);
			jsresult.put("OsdRateInfo",jsOsdRateInfo);
		}
		jsroot.put("OsdCfg.info", jsresult);

		jsroot.toString(str);
		return str.length();
	}

	int getOsdElementCfg(OSD_FUNC_TYPE_et type, int id, IPCNetOsdElementCfg_st *prfi){
		for(list<IPCNetOsdElementCfg_st*>::iterator it= OsdCfg.begin(); it!=OsdCfg.end(); it ++){
			IPCNetOsdElementCfg_st *rfi = *it;
			if(rfi->Type == type){
				//�û��Զ����ַ���OSD���ܻ��ж�������Ի���Ҫ�ж�ID
				if(type == OSD_FUNC_TYPE_STRING && rfi->Id!=id){
					continue;
				}
				prfi->DisplayMode=rfi->DisplayMode;
				prfi->Enable=rfi->Enable;
				prfi->Id=rfi->Id;
				prfi->Str=rfi->Str;
				prfi->Type = rfi->Type;
				prfi->X = rfi->X;
				prfi->Y = rfi->Y;
				return 1;
			}
		}
		return 0;
	}
	int putOsdElementCfg(IPCNetOsdElementCfg_st *rfi){
		//IPCNetOsdElementCfg_st *prfi=0;
		for(list<IPCNetOsdElementCfg_st*>::iterator it= OsdCfg.begin(); it!=OsdCfg.end(); it ++){
			IPCNetOsdElementCfg_st *prfi = *it;
			if(rfi->Type == prfi->Type){
				//�û��Զ����ַ���OSD���ܻ��ж�������Ի���Ҫ�ж�ID
				if(prfi->Type == OSD_FUNC_TYPE_STRING && rfi->Id!=prfi->Id){
					continue;
				}
				prfi->DisplayMode=rfi->DisplayMode;
				prfi->Enable=rfi->Enable;
				prfi->Id=rfi->Id;
				prfi->Str=rfi->Str;
				prfi->Type = rfi->Type;
				prfi->X = rfi->X;
				prfi->Y = rfi->Y;
				return 0;
			}
		}

		OsdCfg.push_back(rfi);
		return 0;
	}
}IPCNetOsdCfg_st;

typedef struct
{
	int Vich;
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;
		jsresult.put("Vich",Vich);

		jsroot.put("OsdGetCfg.info", jsresult);

		jsroot.toString(str);
		return str.length();
	}
}IPCNetGetOsdCfg_st;

typedef struct
{
	int Witdh;
	int Height;
}IPCNetVideoResolutionOpt_st;
#ifdef _WIN32
typedef struct IPCNetVideoEncode{
	IPCNetVideoEncode(){
		VideoResolutionOpt=0;
		OpionEncode=0;
		ProfileTypeOption=0;
		VideoResolutionOptNum=0;
		OpionEncodeNum=0;
	}
	~IPCNetVideoEncode(){
		if(VideoResolutionOpt){
			for(int i=0;i<VideoResolutionOptNum;i++){
				delete VideoResolutionOpt[i];
			}
			delete[] VideoResolutionOpt;
		}
		if(OpionEncode){
			for(int i=0;i<OpionEncodeNum;i++){
				delete OpionEncode[i];
			}
			delete[] OpionEncode;
		}
		if(ProfileTypeOption){
			for(int i=0;i<ProfileTypeOptionNum;i++){
				delete ProfileTypeOption[i];
			}
			delete[] ProfileTypeOption;
		}
	}
	int EncCh;
	String Encode;
	String **OpionEncode;
	int OpionEncodeNum;
	
	int Witdh;
	int Height;
	IPCNetVideoResolutionOpt_st **VideoResolutionOpt;
	int VideoResolutionOptNum;
	
	int IFrame;
	int MaxIFrame;
	int MinIFrame;
	
	int FrameRate;
	int MaxFrameRate;
	int MinFrameRate;

    int RateCtrl; // CBR:1���ɱ�����,0:VBR�ɱ�����
    int Bitrate;  //���� 16K-20M BIT/SΪ��λ
	int PicQuantity;// 0-5,VBR��,ͼ������,ֵԽ������Խ��,CBR��,���ʵĲ�����Χ,

	String ProfileType;
	String **ProfileTypeOption;
	int ProfileTypeOptionNum;
}IPCNetVideoEncode_st;
typedef struct IPCNetVideoEncodeCfg{
	int ViCh;
	int VideoEncodeNum;
	IPCNetVideoEncode_st **VideoEncode;
	IPCNetVideoEncodeCfg(){
		ViCh=0;
		VideoEncode=0;
		VideoEncodeNum=0;
	}
	~IPCNetVideoEncodeCfg(){
		if(VideoEncode){
			for(int i=0;i<VideoEncodeNum;i++){
				delete VideoEncode[i];
			}
			delete[] VideoEncode;
			VideoEncode=0;
		}
	}
	Boolean_t parseJSON(JSONObject &jsdata){
	    
		JSONObject *jsroot= jsdata.getJSONObject("AVEnc.VideoEncode");
		if(jsroot){
			jsroot->getInt("ViCh",ViCh);
			jsroot->getInt("VideoEncodeNum",VideoEncodeNum);
			JSONArray*jaVideoEncode=jsroot->getJSONArray("VideoEncode");
			if(jaVideoEncode){
				VideoEncodeNum=jaVideoEncode->getLength();
				VideoEncode=new IPCNetVideoEncode_st*[VideoEncodeNum];
				for(int i=0;i<VideoEncodeNum;i++){
					VideoEncode[i]=new IPCNetVideoEncode_st();
					JSONObject *jsve=jaVideoEncode->getJSONObject(i);
					if(jsve){
						jsve->getInt("EncCh",VideoEncode[i]->EncCh);
						jsve->getString("Encode",VideoEncode[i]->Encode);
						//Log("%s:%d\n",__FUNCTION__,__LINE__);
						JSONArray*jaoe=jsve->getJSONArray("OpionEncode");
						//Log("%s:%d\n",__FUNCTION__,__LINE__);
						if(jaoe){
							VideoEncode[i]->OpionEncodeNum=jaoe->getLength();
							VideoEncode[i]->OpionEncode=new String*[VideoEncode[i]->OpionEncodeNum];
							//Log("%s:%d\n",__FUNCTION__,__LINE__);
							for(int j=0;j<VideoEncode[i]->OpionEncodeNum;j++){
								VideoEncode[i]->OpionEncode[j]=new String;
								jaoe->getString(j,*VideoEncode[i]->OpionEncode[j]);
							}
							delete jaoe;
						}
						if(jsve->getInt("Witdh",VideoEncode[i]->Witdh)==false){
							jsve->getInt("Width",VideoEncode[i]->Witdh);
						}
						jsve->getInt("Height",VideoEncode[i]->Height);
						JSONArray*javro=jsve->getJSONArray("VideoResolutionOpt");
						if(javro){
							VideoEncode[i]->VideoResolutionOptNum=javro->getLength();
							VideoEncode[i]->VideoResolutionOpt=new IPCNetVideoResolutionOpt_st*[VideoEncode[i]->VideoResolutionOptNum];
							for(int j=0;j<VideoEncode[i]->VideoResolutionOptNum;j++){
								VideoEncode[i]->VideoResolutionOpt[j]=new IPCNetVideoResolutionOpt_st;
								JSONObject *jsvro=javro->getJSONObject(j);
								if(jsvro){
									if(jsvro->getInt("Witdh",VideoEncode[i]->VideoResolutionOpt[j]->Witdh)==0){
										jsvro->getInt("Width",VideoEncode[i]->VideoResolutionOpt[j]->Witdh);
									}
									jsvro->getInt("Height",VideoEncode[i]->VideoResolutionOpt[j]->Height);
								}
							}
							delete javro;
						}
						jsve->getInt("IFrame",VideoEncode[i]->IFrame);
						jsve->getInt("MaxIFrame",VideoEncode[i]->MaxIFrame);
						jsve->getInt("MinIFrame",VideoEncode[i]->MinIFrame);
						jsve->getInt("FrameRate",VideoEncode[i]->FrameRate);
						jsve->getInt("MaxFrameRate",VideoEncode[i]->MaxFrameRate);
						jsve->getInt("MinFrameRate",VideoEncode[i]->MinFrameRate);
						jsve->getInt("RateCtrl",VideoEncode[i]->RateCtrl);
						jsve->getInt("Bitrate",VideoEncode[i]->Bitrate);
						jsve->getInt("PicQuantity",VideoEncode[i]->PicQuantity);

						delete jsve;
					}
				}
				delete jaVideoEncode;
			}

			delete jsroot;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;
		
			JSONObject jsresult;
			jsresult.put("ViCh", ViCh);
			jsresult.put("VideoEncodeNum", VideoEncodeNum);
			if(VideoEncode==0){
				VideoEncode=new IPCNetVideoEncode_st*[VideoEncodeNum];
				for(int i=0;i<VideoEncodeNum;i++){
					VideoEncode[i]=new IPCNetVideoEncode_st;
				}
			}
			JSONArray jaVideoEncode;
			for(int i=0;i<VideoEncodeNum;i++){
				JSONObject jsVideoEncode;
				jsVideoEncode.put("EncCh",VideoEncode[i]->EncCh);
				jsVideoEncode.put("Encode",VideoEncode[i]->Encode);
				if(VideoEncode[i]->OpionEncode==0){
					VideoEncode[i]->OpionEncode=new String*[VideoEncode[i]->OpionEncodeNum];
					for(int k=0;k<VideoEncode[i]->OpionEncodeNum;k++){
						VideoEncode[i]->OpionEncode[k]=new String;
					}
				}
				JSONArray jaEncCh;
				for(int j=0;j<VideoEncode[i]->OpionEncodeNum;j++){
					jaEncCh.put(j,*VideoEncode[i]->OpionEncode[j]);
				}
				jsVideoEncode.put("OpionEncode",jaEncCh);
				jsVideoEncode.put("Witdh",VideoEncode[i]->Witdh);
				jsVideoEncode.put("Width",VideoEncode[i]->Witdh);
				jsVideoEncode.put("Height",VideoEncode[i]->Height);
				if(VideoEncode[i]->VideoResolutionOpt==0){
					VideoEncode[i]->VideoResolutionOpt=new IPCNetVideoResolutionOpt_st*[VideoEncode[i]->VideoResolutionOptNum];
					for(int k=0;k<VideoEncode[i]->VideoResolutionOptNum;k++){
						VideoEncode[i]->VideoResolutionOpt[k]=new IPCNetVideoResolutionOpt_st;
					}
				}
				JSONArray jaVideoResolutionOpt;
				for(int j=0;j<VideoEncode[i]->VideoResolutionOptNum;j++){
					JSONObject jsvro;
					jsvro.put("Witdh",VideoEncode[i]->VideoResolutionOpt[j]->Witdh);
					jsvro.put("Width",VideoEncode[i]->VideoResolutionOpt[j]->Witdh);
					jsvro.put("Height",VideoEncode[i]->VideoResolutionOpt[j]->Height);
					jaVideoResolutionOpt.put(j,jsvro);
				}
				jsVideoEncode.put("VideoResolutionOpt",jaVideoResolutionOpt);
				jsVideoEncode.put("IFrame",VideoEncode[i]->IFrame);
				jsVideoEncode.put("MaxIFrame",VideoEncode[i]->MaxIFrame);
				jsVideoEncode.put("MinIFrame",VideoEncode[i]->MinIFrame);
				jsVideoEncode.put("FrameRate",VideoEncode[i]->FrameRate);
				jsVideoEncode.put("MaxFrameRate",VideoEncode[i]->MaxFrameRate);
				jsVideoEncode.put("MinFrameRate",VideoEncode[i]->MinFrameRate);
				jsVideoEncode.put("RateCtrl",VideoEncode[i]->RateCtrl);
				jsVideoEncode.put("Bitrate",VideoEncode[i]->Bitrate);
				jsVideoEncode.put("PicQuantity",VideoEncode[i]->PicQuantity);

				jaVideoEncode.put(i,jsVideoEncode);
			}
			jsresult.put("VideoEncode", jaVideoEncode);
		jsroot.put("AVEnc.VideoEncode", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetVideoEncodeCfg_st;
#else
typedef struct IPCNetVideoEncode{
	IPCNetVideoEncode(){
		VideoResolutionOpt.clear();
		OpionEncode.clear();
		ProfileTypeOption.clear();
		VideoResolutionOptNum=0;
		OpionEncodeNum=0;
	}
	~IPCNetVideoEncode(){
		VideoResolutionOpt.clear();
		OpionEncode.clear();
		ProfileTypeOption.clear();

		for(list<IPCNetVideoResolutionOpt_st*>::iterator it= VideoResolutionOpt.begin(); it!=VideoResolutionOpt.end(); ){
			IPCNetVideoResolutionOpt_st *rfi = *it;
			it++;
			free(rfi);
		}
		VideoResolutionOpt.clear();
	}
	int EncCh;
	String Encode;
	list<String> OpionEncode;
	int OpionEncodeNum;
	
	int Witdh;
	int Height;
	list<IPCNetVideoResolutionOpt_st*> VideoResolutionOpt;
	int VideoResolutionOptNum;
	IPCNetVideoResolutionOpt_st*getVideoResolutionOpt(int index){
		int i=0;
		for(list<IPCNetVideoResolutionOpt_st*>::iterator it= VideoResolutionOpt.begin(); it!=VideoResolutionOpt.end();i++,it++ ){
			IPCNetVideoResolutionOpt_st *rfi = *it;
			if(i == index)
				return rfi;
		}
		return NULL;
	}

	int IFrame;
	int MaxIFrame;
	int MinIFrame;
	
	int FrameRate;
	int MaxFrameRate;
	int MinFrameRate;

    int RateCtrl; // CBR:1���ɱ�����,0:VBR�ɱ�����
    int Bitrate;  //���� 16K-20M BIT/SΪ��λ
	int PicQuantity;// 0-5,VBR��,ͼ������,ֵԽ������Խ��,CBR��,���ʵĲ�����Χ,

	String ProfileType;
	list<String> ProfileTypeOption;
	int ProfileTypeOptionNum;
}IPCNetVideoEncode_st;
typedef struct IPCNetVideoEncodeCfg{
	int ViCh;
	int VideoEncodeNum;
	list<IPCNetVideoEncode_st*> VideoEncode;
	IPCNetVideoEncode_st*getVideoEncode(int index){
		int i=0;
		for(list<IPCNetVideoEncode_st*>::iterator it= VideoEncode.begin(); it!=VideoEncode.end();i++,it++ ){
			IPCNetVideoEncode_st *rfi = *it;
			if(i == index)
				return rfi;
		}
		return NULL;
	}
	IPCNetVideoEncodeCfg(){
		ViCh=0;
		VideoEncode.clear();
		VideoEncodeNum=0;
	}
	~IPCNetVideoEncodeCfg(){
		for(list<IPCNetVideoEncode_st*>::iterator it= VideoEncode.begin(); it!=VideoEncode.end(); ){
			IPCNetVideoEncode_st *rfi = *it;
			it++;
			free(rfi);
		}
		VideoEncode.clear();
	}
	Boolean_t parseJSON(JSONObject &jsdata){
	    
		JSONObject *jsroot= jsdata.getJSONObject("AVEnc.VideoEncode");
		if(jsroot){
			jsroot->getInt("ViCh",ViCh);
			jsroot->getInt("VideoEncodeNum",VideoEncodeNum);
			JSONArray*jaVideoEncode=jsroot->getJSONArray("VideoEncode");
			if(jaVideoEncode){
				VideoEncodeNum=jaVideoEncode->getLength();
				VideoEncode.clear();
				for(int i=0;i<VideoEncodeNum;i++){
					IPCNetVideoEncode_st *venc=new IPCNetVideoEncode_st();
					JSONObject *jsve=jaVideoEncode->getJSONObject(i);
					if(jsve){
						jsve->getInt("EncCh",venc->EncCh);
						jsve->getString("Encode",venc->Encode);
						//Log("%s:%d\n",__FUNCTION__,__LINE__);
						JSONArray*jaoe=jsve->getJSONArray("OpionEncode");
						//Log("%s:%d\n",__FUNCTION__,__LINE__);
						if(jaoe){
							venc->OpionEncodeNum=jaoe->getLength();
							venc->OpionEncode.clear();
							//Log("%s:%d\n",__FUNCTION__,__LINE__);
							for(int j=0;j<venc->OpionEncodeNum;j++){
								String encname;
								jaoe->getString(j,encname);
								venc->OpionEncode.push_back(encname);
							}
							delete jaoe;
						}
						if(jsve->getInt("Witdh",venc->Witdh)==false){
							jsve->getInt("Width",venc->Witdh);
						}
						jsve->getInt("Height",venc->Height);
						JSONArray*javro=jsve->getJSONArray("VideoResolutionOpt");
						if(javro){
							venc->VideoResolutionOptNum=javro->getLength();
							venc->VideoResolutionOpt.clear();
							for(int j=0;j<venc->VideoResolutionOptNum;j++){
								IPCNetVideoResolutionOpt_st *resl=new IPCNetVideoResolutionOpt_st();
								JSONObject *jsvro=javro->getJSONObject(j);
								if(jsvro){
									int val;
									if(jsvro->getInt("Witdh",resl->Witdh)==0){
										jsvro->getInt("Width",resl->Witdh);
									}
									jsvro->getInt("Height",resl->Height);
								}
								venc->VideoResolutionOpt.push_back(resl);
							}
							delete javro;
						}
						jsve->getInt("IFrame",venc->IFrame);
						jsve->getInt("MaxIFrame",venc->MaxIFrame);
						jsve->getInt("MinIFrame",venc->MinIFrame);
						jsve->getInt("FrameRate",venc->FrameRate);
						jsve->getInt("MaxFrameRate",venc->MaxFrameRate);
						jsve->getInt("MinFrameRate",venc->MinFrameRate);
						jsve->getInt("RateCtrl",venc->RateCtrl);
						jsve->getInt("Bitrate",venc->Bitrate);
						jsve->getInt("PicQuantity",venc->PicQuantity);
						
						VideoEncode.push_back(venc);
						delete jsve;
					}else{
						delete venc;
					}
				}
				delete jaVideoEncode;
			}

			delete jsroot;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;
		
			JSONObject jsresult;
			jsresult.put("ViCh", ViCh);
			jsresult.put("VideoEncodeNum", VideoEncodeNum);
			JSONArray jaVideoEncode;
			int i=0;
			for(list<IPCNetVideoEncode_st*>::iterator it= VideoEncode.begin(); it!=VideoEncode.end(); ){
				IPCNetVideoEncode_st *venc = *it;
				JSONObject jsVideoEncode;
				jsVideoEncode.put("EncCh",venc->EncCh);
				jsVideoEncode.put("Encode",venc->Encode);
				
				jsVideoEncode.put("Witdh",venc->Witdh);
				jsVideoEncode.put("Width",venc->Witdh);
				jsVideoEncode.put("Height",venc->Height);
				
				JSONArray jaVideoResolutionOpt;
				int j=0;
				for(list<IPCNetVideoResolutionOpt_st*>::iterator it= venc->VideoResolutionOpt.begin(); it!=venc->VideoResolutionOpt.end(); ){
					IPCNetVideoResolutionOpt_st *resl = *it;
					JSONObject jsvro;
					jsvro.put("Witdh", resl->Witdh);
					jsvro.put("Width", resl->Witdh);
					jsvro.put("Height", resl->Height);
					jaVideoResolutionOpt.put(j,jsvro);
					j++;
				}
				jsVideoEncode.put("VideoResolutionOpt",jaVideoResolutionOpt);
				jsVideoEncode.put("IFrame",venc->IFrame);
				jsVideoEncode.put("MaxIFrame",venc->MaxIFrame);
				jsVideoEncode.put("MinIFrame",venc->MinIFrame);
				jsVideoEncode.put("FrameRate",venc->FrameRate);
				jsVideoEncode.put("MaxFrameRate",venc->MaxFrameRate);
				jsVideoEncode.put("MinFrameRate",venc->MinFrameRate);
				jsVideoEncode.put("RateCtrl",venc->RateCtrl);
				jsVideoEncode.put("Bitrate",venc->Bitrate);
				jsVideoEncode.put("PicQuantity",venc->PicQuantity);

				jaVideoEncode.put(i,jsVideoEncode);
				i++;
			}
			jsresult.put("VideoEncode", jaVideoEncode);
		jsroot.put("AVEnc.VideoEncode", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetVideoEncodeCfg_st;
#endif

//{"IspPicColor.info":{"Type":2,"SwitchLevel":0,"SwitchTime":1,"TimerOpera":0,"Start":{"Hour":0,"Min":0,"Sec":0},"End":{"Hour":0,"Min":0,"Sec":0}},"ret":0}
typedef struct
{
	int Type;	//��ת�����ͣ�0��ɫ��1�ڰ�

	//�Զ��ڰ�-��ɫת����Ч
	int SwitchLevel;  //�л������ȣ�0-�ͣ�1-�У�2-��
	int SwitchTime;	//�л�ʱ�䣬��λs

	//���²������ڶ�ʱ��ת����Ч
	int TimerOpera;	//�趨ʱ���ڵĲ�����0-��ɫģʽ��1-�ڰ�ģʽ
	IPCNetTime_st Start;
	IPCNetTime_st End;

	Boolean_t parseJSON(JSONObject &jsdata){
	    
		JSONObject *jsroot= jsdata.getJSONObject("IspPicColor.info");
		if(jsroot){
			jsroot->getInt("Type",Type);
			jsroot->getInt("SwitchLevel",SwitchLevel);
			jsroot->getInt("SwitchTime",SwitchTime);

			jsroot->getInt("TimerOpera",TimerOpera);

			JSONObject *jsstart=jsroot->getJSONObject("Start");
			if(jsstart){
				jsstart->getInt("Hour",Start.Hour);
				jsstart->getInt("Min",Start.Min);
				jsstart->getInt("Sec",Start.Sec);
				delete jsstart;
			}

			JSONObject *jsend=jsroot->getJSONObject("End");
			if(jsend){
				jsend->getInt("Hour",Start.Hour);
				jsend->getInt("Min",Start.Min);
				jsend->getInt("Sec",Start.Sec);
				delete jsend;
			}

			delete jsroot;
		}

		return true;
	}

	int toJSONString(String&str){
		JSONObject jsroot;
		JSONObject jsresult;
		jsresult.put("Type",Type);
		jsresult.put("SwitchLevel",SwitchLevel);
		jsresult.put("SwitchTime",SwitchTime);
		jsresult.put("TimerOpera",TimerOpera);

		JSONObject jsstart;
		jsstart.put("Hour",Start.Hour);
		jsstart.put("Min",Start.Min);
		jsstart.put("Sec",Start.Sec);
		jsresult.put("Start",jsstart);

		JSONObject jsend;
		jsend.put("Hour",Start.Hour);
		jsend.put("Min",Start.Min);
		jsend.put("Sec",Start.Sec);
		jsresult.put("End",jsend);

		jsroot.put("IspPicColor.info", jsresult);

		jsroot.toString(str);
		return str.length();
	}
}IPCNetPicColorInfo_st;

typedef struct IPCNetTimePeriod{
	IPCNetTime_st Start;
	IPCNetTime_st End;
}IPCNetTimePeriod_st;
typedef struct//����ʱ���
IPCNetDefendPeriodInfo{
	IPCNetDefendPeriodInfo(){
		memset(TimePeriod,0,sizeof(TimePeriod));
	}
	~IPCNetDefendPeriodInfo(){
	}
	int  Flag;
	IPCNetTimePeriod_st *TimePeriod[2];
//		public int TimePeriodCount;
}IPCNetDefendPeriodInfo_st;
typedef struct IPCNetVideoMoveInfo{
	IPCNetVideoMoveInfo()
	{
		MdEnable=0;
		Sensitive=0;
		memset(Area, 0, sizeof(Area));//16x12, Z scan
		AreaCount=0;
	}
	~IPCNetVideoMoveInfo(){
	}
	int  MdEnable;
	int  Sensitive;  
//		public int  Columns;
//		public int  Rows;
	int  Area[256];//16x12, Z scan
	int  AreaCount;
}IPCNetVideoMoveInfo_st;
typedef struct{
	int   Delay;
	int   EmailEnable;
}JianleAlarmIoOutPutInfo_st;
typedef struct{
	int RecordTime;
	int FtpEnable;
	int EmailEnable;
}JianleAlarmRecInfo_st;
typedef struct{
	int PushEnable;
	int PictureNum;
	int Sec;
	int Msec;
	int FtpEnable;
	int EmailEnable;
	int CloudEnable;
	Boolean_t parseJSON(JSONObject &jsdata){
		jsdata.getInt("PushEnable",PushEnable);
		jsdata.getInt("PictureNum",PictureNum);
		jsdata.getInt("Sec",Sec);
		jsdata.getInt("Msec",Msec);
		jsdata.getInt("FtpEnable",FtpEnable);
	    jsdata.getInt("EmailEnable",EmailEnable);
	    jsdata.getInt("CloudEnable",CloudEnable);
	    return true;
	}
}IPCNetAlarmSnapInfo_st;
typedef struct{
	int Delay;
	int EmailEnable;
	int AlarmLevel;
}IPCNetAlarmIoOutputInfo_st;
typedef struct{
	int RecEnable;
	int RecordTime;
	int FtpEnable;
	int EmailEnable;
	int CloudEnable;
	Boolean_t parseJSON(JSONObject &jsdata){
	    jsdata.getInt("EmailEnable",EmailEnable);
		jsdata.getInt("RecordTime",RecordTime);
		jsdata.getInt("FtpEnable",FtpEnable);
		jsdata.getInt("CloudEnable",CloudEnable);
		jsdata.getInt("RecEnable",RecEnable);
	    return true;
	}
}IPCNetAlarmRecordInfo_st;

typedef struct {
	int PresetId;
	String PresetName;
}IPCNetAlarmPresetInfo_st;
typedef struct{
	IPCNetAlarmIoOutputInfo_st IoOutputInfo;
	IPCNetAlarmRecordInfo_st RecordInfo;
	IPCNetAlarmSnapInfo_st SnapInfo;
	IPCNetAlarmPresetInfo_st PresetInfo;
}IPCNetAlarmLinkagePolicyInfo_st;
typedef struct{
    int  Col;//16
    int  Row;//12
    int  BitMask[6];//һ�� T_U32 ����
}IPCNetMdArea_st;
typedef struct{
    int Vi;
    int Sensitive;
    IPCNetMdArea_st Area;
}IPCNetMoveDetCfg_st;
typedef struct IPCNetTimerCfg{
    IPCNetTimerCfg(){
        PeriodMaxCnt = 5;
        Enable = false;
    }
    Boolean_t Enable;
    int Day;//0:Everyday 1:Monday 2:Tuesday
    list<IPCNetPeriod_st*> Period;
    int PeriodMaxCnt;
}IPCNetTimerCfg_st;
typedef struct //�ƶ������������
{
    Boolean_t Local;//save into SDCard/TFCard
    Boolean_t FTP;
    Boolean_t Email;
    Boolean_t Cloud;
    Boolean_t P2P;   //�ϴ�����ͼƬ
}IPCNetUploadCfg_st;
typedef struct //����ץ��
{
    Boolean_t Enable;
    int PicNum;//1~10 pieces
    int Interval;//5~2000 ms

    IPCNetUploadCfg_st UploadCfg;
}IPCNetAlarmSnapCfg_st;
typedef struct //����¼��
{
    Boolean_t Enable;
    int RecTime;//5~60s
    int PreRecTime;//0~15s

    IPCNetUploadCfg_st UploadCfg;
}IPCNetAlarmRecordCfg_st;
typedef struct //�澯����IO��Ϣ
{
    Boolean_t Enable;
    int AlarmLevel;     //0-��⵽�͵�ƽ������1-�ߵ�ƽ����
    int Delay;//0~60s
}IPCNetAlarmIOCfg_st;
typedef struct IPCNetAlarmTriggerOperation{
    IPCNetAlarmSnapCfg_st SnapCfg;
    IPCNetAlarmRecordCfg_st RecCfg;
    IPCNetAlarmIOCfg_st IOCfg;
    IPCNetAlarmPresetInfo_st PresetInfo;
}IPCNetAlarmTriggerOperation_st;
typedef struct IPCNETMoveAlarmCfg{
	int new_protocal;
	//-------------------------- new protocal ---------------------------
	Boolean_t Enable;
	String Type;
	IPCNetMoveDetCfg_st md;
	IPCNetTimerCfg_st *Week2[8];//Week
	IPCNetAlarmTriggerOperation_st Operation;

	//-------------------------- old protocal ---------------------------
	int ViCh;
	IPCNetDefendPeriodInfo_st *Week[8];//Everyday,Weekday,Monday,Tuesday...
	IPCNetVideoMoveInfo_st MoveInfo;
	IPCNetAlarmLinkagePolicyInfo_st PolicyInfo;
	
	IPCNETMoveAlarmCfg(){
		new_protocal=0;
		memset(Week,0,sizeof(Week));
	}
	~IPCNETMoveAlarmCfg(){
	}
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("Alarm");
		if(jsroot){
			new_protocal=1;
			jsroot->getBoolean("Enable",Enable);
			jsroot->getString("Type",Type);
			for(int i=0;i<8;i++){
				//Week2[i] = new IPCNetTimerCfg_st();
				Week2[i] = 0;
			}
			JSONArray *jsWeek = jsroot->getJSONArray("Week");
			if(jsWeek){
				for(int i=0;i<jsWeek->getLength();i++){
					JSONObject *jsIPCNetTimerCfg = jsWeek->getJSONObject(i);
					if(jsIPCNetTimerCfg){
						int day=0;
						jsIPCNetTimerCfg->getInt("Day", day);
						if(day>7){
							Log("day is %d which is bigger then 7", day);
							continue;
						}
						if(Week2[day])
							delete Week2[day];
						Week2[day] = new IPCNetTimerCfg_st();

						IPCNetTimerCfg_st* wday = Week2[day];
						wday->Day = day;
						jsIPCNetTimerCfg->getBoolean("Enable", wday->Enable);
						jsIPCNetTimerCfg->getInt("PeriodMaxCnt", wday->PeriodMaxCnt);
						JSONArray *jsPeriod = jsIPCNetTimerCfg->getJSONArray("Period");
						if(jsPeriod){
							int j=0;
							for(j=0;j<wday->PeriodMaxCnt&& j<jsPeriod->getLength();j++){
								JSONObject*jsper = jsPeriod->getJSONObject(j);
								if(jsper){
									IPCNetPeriod_st*per = new IPCNetPeriod_st();
									jsper->getInt("Start", per->Start);
									jsper->getInt("End", per->End);
									wday->Period.push_back(per);
									delete jsper;
								}
							}
							delete jsPeriod;
						}
					//Log("line:%d\n",__LINE__);
	//						Week[i].TimePeriodCount = jsIPCNetDefendPeriodInfo_st.getInt("TimePeriodCount");
						delete jsIPCNetTimerCfg;
					}
				}
				delete jsWeek;
			}
				
			JSONObject *jsMoveInfo = jsroot->getJSONObject("Src.md");
			if(jsMoveInfo){
				jsMoveInfo->getInt("Vi", md.Vi);
				jsMoveInfo->getInt("Sensitive", md.Sensitive);
				JSONObject *jsArea = jsMoveInfo->getJSONObject("Area");
				if(jsArea){
					jsArea->getInt("Col", md.Area.Col);
					jsArea->getInt("Row", md.Area.Row);
					JSONArray*jsBitMask = jsArea->getJSONArray("BitMask");
					if(jsBitMask){
						for(int i=0;i<jsBitMask->getLength()&&i<sizeof(md.Area.BitMask)/sizeof(md.Area.BitMask[0]);i++){
							jsBitMask->getInt(i, md.Area.BitMask[i]);
						}
						delete jsBitMask;
					}
					delete jsArea;
				}
				delete jsMoveInfo;
			}
				
			JSONObject *jsOperation = jsroot->getJSONObject("Operation");
			if(jsOperation){
				JSONObject *jsSnapInfo = jsOperation->getJSONObject("SnapCfg");
				if(jsSnapInfo){
					jsSnapInfo->getBoolean("Enable", Operation.SnapCfg.Enable);
					jsSnapInfo->getInt("PicNum", Operation.SnapCfg.PicNum);
					jsSnapInfo->getInt("Interval", Operation.SnapCfg.Interval);
					JSONObject*jsUploadCfg = jsSnapInfo->getJSONObject("UploadCfg");
					if(jsUploadCfg){
						jsUploadCfg->getBoolean("Local", Operation.SnapCfg.UploadCfg.Local);
						jsUploadCfg->getBoolean("FTP", Operation.SnapCfg.UploadCfg.FTP);
						jsUploadCfg->getBoolean("Email", Operation.SnapCfg.UploadCfg.Email);
						jsUploadCfg->getBoolean("Cloud", Operation.SnapCfg.UploadCfg.Cloud);
						jsUploadCfg->getBoolean("P2P", Operation.SnapCfg.UploadCfg.P2P);
						delete jsUploadCfg;
					}
					delete jsSnapInfo;
				}

				JSONObject *jsIoOutputInfo = jsOperation->getJSONObject("IOCfg");
				if(jsIoOutputInfo){
					jsIoOutputInfo->getBoolean("Enable", Operation.IOCfg.Enable);
					jsIoOutputInfo->getInt("Delay", Operation.IOCfg.Delay);
					jsIoOutputInfo->getInt("AlarmLevel",Operation.IOCfg.AlarmLevel);
					delete jsIoOutputInfo;
				}
					
				JSONObject *jsRecordInfo = jsOperation->getJSONObject("RecCfg");
				if(jsRecordInfo){
					jsSnapInfo->getBoolean("Enable", Operation.RecCfg.Enable);
					jsSnapInfo->getInt("RecTime", Operation.RecCfg.RecTime);
					jsSnapInfo->getInt("PreRecTime", Operation.RecCfg.PreRecTime);
					JSONObject*jsUploadCfg = jsSnapInfo->getJSONObject("UploadCfg");
					if(jsUploadCfg){
						jsUploadCfg->getBoolean("Local", Operation.RecCfg.UploadCfg.Local);
						jsUploadCfg->getBoolean("FTP", Operation.RecCfg.UploadCfg.FTP);
						jsUploadCfg->getBoolean("Email", Operation.RecCfg.UploadCfg.Email);
						jsUploadCfg->getBoolean("Cloud", Operation.RecCfg.UploadCfg.Cloud);
						jsUploadCfg->getBoolean("P2P", Operation.RecCfg.UploadCfg.P2P);
						delete jsUploadCfg;
					}
					delete jsRecordInfo;
				}
					
				JSONObject *jsPresetInfo = jsOperation->getJSONObject("PresetInfo");
				if(jsPresetInfo){
					jsPresetInfo->getInt("PresetId",PolicyInfo.PresetInfo.PresetId);
					jsPresetInfo->getString("PresetName",PolicyInfo.PresetInfo.PresetName);
					delete jsPresetInfo;
				}
					
				delete jsOperation;
			}
			delete jsroot;
		}else{
			return parseJSON_Old(jsdata);
		}
		return true;
	}
	Boolean_t parseJSON_Old(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("Alarm.MoveAlarm");
		if(jsroot){
			new_protocal=0;
			jsroot->getInt("ViCh",ViCh);
			JSONArray *jsWeek = jsroot->getJSONArray("Week");
			if(jsWeek){
				for(int i=0;i<jsWeek->getLength()&&i<8;i++){
					JSONObject *jsIPCNetDefendPeriodInfo_st = jsWeek->getJSONObject(i);
					if(jsIPCNetDefendPeriodInfo_st){
						Week[i] = new IPCNetDefendPeriodInfo_st();
						jsIPCNetDefendPeriodInfo_st->getInt("Flag",Week[i]->Flag);
							
						JSONArray *jsTimePeriod = jsIPCNetDefendPeriodInfo_st->getJSONArray("TimePeriod");
						if(jsTimePeriod){
							for(int j=0;j<jsTimePeriod->getLength()&&j<2;j++){
								JSONObject *jsIPCNetTimePeriod_st = jsTimePeriod->getJSONObject(j);
								if(jsIPCNetTimePeriod_st){
									Week[i]->TimePeriod[j] = new IPCNetTimePeriod_st();
									JSONObject *jsEnd = jsIPCNetTimePeriod_st->getJSONObject("End");
									if(jsEnd){
										jsEnd->getInt("Hour",Week[i]->TimePeriod[j]->End.Hour);
										jsEnd->getInt("Min",Week[i]->TimePeriod[j]->End.Min);
										jsEnd->getInt("Sec",Week[i]->TimePeriod[j]->End.Sec);
										delete jsEnd;
									}
										
									JSONObject *jsStart = jsIPCNetTimePeriod_st->getJSONObject("Start");
									if(jsStart){
										jsStart->getInt("Hour",Week[i]->TimePeriod[j]->Start.Hour);
										jsStart->getInt("Min",Week[i]->TimePeriod[j]->Start.Min);
										jsStart->getInt("Sec",Week[i]->TimePeriod[j]->Start.Sec);
										delete jsStart;
									}
									delete jsIPCNetTimePeriod_st;
								}
							}
							delete jsTimePeriod;
						}
					//Log("line:%d\n",__LINE__);
	//						Week[i].TimePeriodCount = jsIPCNetDefendPeriodInfo_st.getInt("TimePeriodCount");
						delete jsIPCNetDefendPeriodInfo_st;
					}
				}
				delete jsWeek;
			}
				
			JSONObject *jsMoveInfo = jsroot->getJSONObject("MoveInfo");
			if(jsMoveInfo){
//					MoveInfo.AreaCount = jsMoveInfo.getInt("AreaCount");
				jsMoveInfo->getInt("MdEnable",MoveInfo.MdEnable);
				jsMoveInfo->getInt("Sensitive",MoveInfo.Sensitive);
//					MoveInfo.Columns = jsMoveInfo.getInt("Columns");
//					MoveInfo.Rows = jsMoveInfo.getInt("Rows");
				JSONArray *jsArea = jsMoveInfo->getJSONArray("Area");
				if(jsArea){
					for(int i=0;i<jsArea->getLength()&&i<256;i++){
						jsArea->getInt(i,MoveInfo.Area[i]);
					}
					delete jsArea;
				}
				delete jsMoveInfo;
			}
				
			JSONObject *jsPolicyInfo = jsroot->getJSONObject("PolicyInfo");
			if(jsPolicyInfo){
				JSONObject *jsIoOutputInfo = jsPolicyInfo->getJSONObject("IoOutputInfo");
				if(jsIoOutputInfo){
					jsIoOutputInfo->getInt("Delay",PolicyInfo.IoOutputInfo.Delay);
					jsIoOutputInfo->getInt("EmailEnable",PolicyInfo.IoOutputInfo.EmailEnable);
					delete jsIoOutputInfo;
				}
					
				JSONObject *jsRecordInfo = jsPolicyInfo->getJSONObject("RecordInfo");
				if(jsRecordInfo){
					PolicyInfo.RecordInfo.parseJSON(*jsRecordInfo);
					delete jsRecordInfo;
				}
//					PolicyInfo.RecordInfo.EmailEnable = jsRecordInfo.getInt("EmailEnable");
//					PolicyInfo.RecordInfo.RecordTime = jsRecordInfo.getInt("RecordTime");
//					PolicyInfo.RecordInfo.FtpEnable = jsRecordInfo.getInt("FtpEnable");
//					PolicyInfo.RecordInfo.CloudEnable = jsRecordInfo.getInt("CloudEnable");
//					PolicyInfo.RecordInfo.RecEnable = jsRecordInfo.getInt("RecEnable");
					
				JSONObject *jsSnapInfo = jsPolicyInfo->getJSONObject("SnapInfo");
				if(jsSnapInfo){
					PolicyInfo.SnapInfo.parseJSON(*jsSnapInfo);
					delete jsSnapInfo;
				}
//					PolicyInfo.SnapInfo.EmailEnable = jsSnapInfo.getInt("EmailEnable");
//					PolicyInfo.SnapInfo.PictureNum = jsSnapInfo.getInt("PictureNum");
//					PolicyInfo.SnapInfo.Sec = jsSnapInfo.getInt("Sec");
//					PolicyInfo.SnapInfo.Msec = jsSnapInfo.getInt("Msec");
//					PolicyInfo.SnapInfo.FtpEnable = jsSnapInfo.getInt("FtpEnable");
//					PolicyInfo.SnapInfo.CloudEnable = jsSnapInfo.getInt("CloudEnable");
					
				JSONObject *jsPresetInfo = jsPolicyInfo->getJSONObject("PresetInfo");
				if(jsPresetInfo){
					jsPresetInfo->getInt("PresetId",PolicyInfo.PresetInfo.PresetId);
					jsPresetInfo->getString("PresetName",PolicyInfo.PresetInfo.PresetName);
					delete jsPresetInfo;
				}
					
				delete jsPolicyInfo;
			}
			delete jsroot;
		}
	    return true;
	}
	int toJSONString(String&str){
		if(new_protocal == 0){
			return toJSONString_Old(str);
		}
	    JSONObject jsresult;

			JSONObject jsroot;
			jsroot.put("Enable",Enable);
			jsroot.put("Type",Type);
				
			JSONArray jsWeek;
			int k=0;
			for(int i=0;i<8;i++){
				JSONObject jsTimerCfg;
				if(Week2[i]){
					IPCNetTimerCfg_st*wday = Week2[i];
					//jsTimerCfg.put("Enable", wday->Enable);
					jsTimerCfg.put("Day", wday->Day);
					if(wday->Period.size()==0)
						continue;
					
					JSONArray jsTimePeriod;
					int j=0;
					for(list<IPCNetPeriod_st*>::iterator it= wday->Period.begin(); it!=wday->Period.end(); it++){
						IPCNetPeriod_st*rfi = *it;
						JSONObject jsIPCNetPeriod_st;
						jsIPCNetPeriod_st.put("Start", rfi->Start);
						jsIPCNetPeriod_st.put("End", rfi->End);
						jsTimePeriod.put(j++, jsIPCNetPeriod_st);
					}
					jsTimerCfg.put("Period", jsTimePeriod);

					jsWeek.put(k++, jsTimerCfg);
				}
			}
			jsroot.put("Week", jsWeek);
			
			JSONObject jsMoveInfo;
			jsMoveInfo.put("Vi",md.Vi);
			jsMoveInfo.put("Sensitive",md.Sensitive);
			JSONObject jsArea;
			jsArea.put("Col", md.Area.Col);
            jsArea.put("Row", md.Area.Row);
			JSONArray jaBitMask;
			for(int i=0;i<sizeof(md.Area.BitMask)/sizeof(md.Area.BitMask[0]);i++){
				jaBitMask.put(i, md.Area.BitMask[i]);
			}
			jsArea.put("BitMask", jaBitMask);
			jsMoveInfo.put("Area",jsArea);
			
			jsroot.put("Src.md",jsMoveInfo);
				
			JSONObject jsOperation;

                JSONObject jsSnapCfg;
                jsSnapCfg.put("Enable", Operation.SnapCfg.Enable);
                jsSnapCfg.put("PicNum", Operation.SnapCfg.PicNum);
                jsSnapCfg.put("Interval", Operation.SnapCfg.Interval);
                JSONObject jsUploadCfg;
                jsUploadCfg.put("Local", Operation.SnapCfg.UploadCfg.Local);
                jsUploadCfg.put("FTP", Operation.SnapCfg.UploadCfg.FTP);
                jsUploadCfg.put("Email", Operation.SnapCfg.UploadCfg.Email);
                jsUploadCfg.put("Cloud", Operation.SnapCfg.UploadCfg.Cloud);
                jsUploadCfg.put("P2P", Operation.SnapCfg.UploadCfg.P2P);
                jsSnapCfg.put("UploadCfg", jsUploadCfg);
                jsOperation.put("SnapCfg", jsSnapCfg);

                JSONObject jsRecCfg;
                jsRecCfg.put("Enable", Operation.RecCfg.Enable);
                jsRecCfg.put("RecTime", Operation.RecCfg.RecTime);
                jsRecCfg.put("PreRecTime", Operation.RecCfg.PreRecTime);
                jsUploadCfg;
                jsUploadCfg.put("Local", Operation.RecCfg.UploadCfg.Local);
                jsUploadCfg.put("FTP", Operation.RecCfg.UploadCfg.FTP);
                jsUploadCfg.put("Email", Operation.RecCfg.UploadCfg.Email);
                jsUploadCfg.put("Cloud", Operation.RecCfg.UploadCfg.Cloud);
                jsUploadCfg.put("P2P", Operation.RecCfg.UploadCfg.P2P);
                jsRecCfg.put("UploadCfg", jsUploadCfg);
                jsOperation.put("RecCfg", jsRecCfg);

                JSONObject jsIOCfg;
                jsIOCfg.put("Enable", Operation.IOCfg.Enable);
                jsIOCfg.put("Delay", Operation.IOCfg.Delay);
                jsIOCfg.put("AlarmLevel", Operation.IOCfg.AlarmLevel);
                jsOperation.put("IOCfg", jsIOCfg);

                JSONObject jsPresetInfo;
                jsPresetInfo.put("PresetId", Operation.PresetInfo.PresetId);
                jsPresetInfo.put("PresetName", Operation.PresetInfo.PresetName);
                jsOperation.put("PresetInfo", jsPresetInfo);

                jsroot.put("Operation", jsOperation);
				
			jsresult.put("Alarm", jsroot);
			
		jsresult.toString(str);
		return str.length();
	}
	int toJSONString_Old(String&str){
	    JSONObject jsresult;

			JSONObject jsroot;
			jsroot.put("ViCh",ViCh);
				
			JSONArray jsWeek;
			for(int i=0;i<8;i++){
				JSONObject jsIPCNetDefendPeriodInfo_st;
				if(Week[i]){
					jsIPCNetDefendPeriodInfo_st.put("Flag",Week[i]->Flag);
					
					JSONArray jsTimePeriod;
					for(int j=0;j<2;j++){
						JSONObject jsIPCNetTimePeriod_st;
						
						JSONObject jsEnd;
						if(Week[i]->TimePeriod[j]){
							jsEnd.put("Hour",Week[i]->TimePeriod[j]->End.Hour);
							jsEnd.put("Min",Week[i]->TimePeriod[j]->End.Min);
							jsEnd.put("Sec",Week[i]->TimePeriod[j]->End.Sec);
						}
						jsIPCNetTimePeriod_st.put("End", jsEnd);
						
						JSONObject jsStart;
						if(Week[i]->TimePeriod[j]){
							jsStart.put("Hour",Week[i]->TimePeriod[j]->Start.Hour);
							jsStart.put("Min",Week[i]->TimePeriod[j]->Start.Min);
							jsStart.put("Sec",Week[i]->TimePeriod[j]->Start.Sec);
						}
						jsIPCNetTimePeriod_st.put("Start", jsStart);

						jsTimePeriod.put(j,jsIPCNetTimePeriod_st);
					}
					jsIPCNetDefendPeriodInfo_st.put("TimePeriod", jsTimePeriod);
//					jsIPCNetDefendPeriodInfo_st.put("TimePeriodCount",Week[i].TimePeriodCount);
				}
				jsWeek.put(i,jsIPCNetDefendPeriodInfo_st);
			}
			jsroot.put("Week", jsWeek);
				
			JSONObject jsMoveInfo;
//				jsMoveInfo.put("AreaCount",MoveInfo.AreaCount);
			jsMoveInfo.put("MdEnable",MoveInfo.MdEnable);
			jsMoveInfo.put("Sensitive",MoveInfo.Sensitive);
//				jsMoveInfo.put("Columns",MoveInfo.Columns);
//				jsMoveInfo.put("Rows",MoveInfo.Rows);
			JSONArray jsArea;
			for(int i=0;i<256;i++){
				jsArea.put(i,MoveInfo.Area[i]);
			}
			jsMoveInfo.put("Area",jsArea);
				
			jsroot.put("MoveInfo",jsMoveInfo);
				
			JSONObject jsPolicyInfo;
				
			JSONObject jsIoOutputInfo;
			jsIoOutputInfo.put("Delay",PolicyInfo.IoOutputInfo.Delay);
			jsIoOutputInfo.put("EmailEnable",PolicyInfo.IoOutputInfo.EmailEnable);
			jsPolicyInfo.put("IoOutputInfo",jsIoOutputInfo);
				
			JSONObject jsRecordInfo;
			jsRecordInfo.put("EmailEnable",PolicyInfo.RecordInfo.EmailEnable);
			jsRecordInfo.put("RecordTime",PolicyInfo.RecordInfo.RecordTime);
			jsRecordInfo.put("FtpEnable",PolicyInfo.RecordInfo.FtpEnable);
			jsRecordInfo.put("CloudEnable",PolicyInfo.RecordInfo.CloudEnable);
			jsRecordInfo.put("RecEnable",PolicyInfo.RecordInfo.RecEnable);
			jsPolicyInfo.put("RecordInfo",jsRecordInfo);
				
			JSONObject jsSnapInfo;
			jsSnapInfo.put("EmailEnable",PolicyInfo.SnapInfo.EmailEnable);
			jsSnapInfo.put("PictureNum",PolicyInfo.SnapInfo.PictureNum);
			jsSnapInfo.put("Sec",PolicyInfo.SnapInfo.Sec);
			jsSnapInfo.put("Msec",PolicyInfo.SnapInfo.Msec);
			jsSnapInfo.put("FtpEnable",PolicyInfo.SnapInfo.FtpEnable);
			jsSnapInfo.put("CloudEnable",PolicyInfo.SnapInfo.CloudEnable);
			jsPolicyInfo.put("SnapInfo",jsSnapInfo);
				
			JSONObject jsPresetInfo;
			jsPresetInfo.put("PresetId",PolicyInfo.PresetInfo.PresetId);
			jsPresetInfo.put("PresetName",PolicyInfo.PresetInfo.PresetName);
			jsPolicyInfo.put("PresetInfo",jsPresetInfo);

			jsroot.put("PolicyInfo",jsPolicyInfo);
				
			jsresult.put("Alarm.MoveAlarm", jsroot);
			
		jsresult.toString(str);
		return str.length();
	}
}IPCNETMoveAlarmCfg_st;


typedef struct
{
    T_S32 Index;
    T_S32 Mode;     //0-input,1-output,2-adc,3-dac,4-pwd
    T_S32 Val;
	T_S32 Tr;
	T_S32 Gate;
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("GPIO");
		if(jsroot){
			jsroot->getInt("Index",Index);
			jsroot->getInt("Mode",Mode);
			jsroot->getInt("Val",Val);
			jsroot->getInt("Tr",Tr);
			jsroot->getInt("Gate",Gate);
			delete jsroot;
		}
		return true;
	}
	int toJSONString(String&str){
		JSONObject gpioSettingWrapper;// = new JSONObject();

		JSONObject gpioSetting;// = new JSONObject();
		gpioSetting.put("Index", Index);
		gpioSetting.put("Mode", Mode);
		gpioSetting.put("Val", Val);
		gpioSetting.put("Tr", Tr);
		gpioSetting.put("Gate", Gate);

		gpioSettingWrapper.put("GPIO", gpioSetting);


		gpioSettingWrapper.toString(str);

		return str.length();
	}
}IPCNetGpioInfo_st;

typedef struct
{
    T_S32 Index;
	Boolean_t parseJSON(JSONObject &jsdata){
		JSONObject *jsroot= jsdata.getJSONObject("GPIO");
		if(jsroot){
			jsroot->getInt("Index",Index);
			delete jsroot;
		}
		return true;
	}
	int toJSONString(String&str){
		JSONObject gpioSettingWrapper;// = new JSONObject();

		JSONObject gpioSetting;// = new JSONObject();
		gpioSetting.put("Index", Index);

		gpioSettingWrapper.put("GPIO", gpioSetting);


		gpioSettingWrapper.toString(str);
		return str.length();
	}
}IPCNetGetGpioInfo_st;

typedef struct {
    int num;
    int total;
    int used;

    Boolean_t parseJSON(JSONObject &jsdata) {
        
            JSONObject *jsroot = jsdata.getJSONObject("li");
            if (jsroot) {
                jsroot->getInt("n",num);//��ǰĿ¼�ļ�����
                jsroot->getInt("t",total);//���̿ռ�������
                jsroot->getInt("u",used);//������ʹ�ÿռ�
				delete jsroot;
            }
        
        return true;
    }

}RemoteDirListInfo_t;

struct RemoteDirInfo;
#define DT_FILE 8
#define DT_FOLDER 4
typedef struct RemoteFileInfo{
	RemoteFileInfo(){
		size=0;
		mRemoteFileInfo=0;
	}
    int type;//file:8 folder:4
    String name;
	String path;
    unsigned long long size;

	//for directory
	struct RemoteDirInfo*mRemoteFileInfo;
}RemoteFileInfo_t;

typedef struct RemoteDirInfo{
    int type;
    String name;
	String path;
	RemoteDirInfo(){
		mParent=0;
		mRemoteFileInfoList.clear();
	}
	~RemoteDirInfo(){
		for(list<RemoteFileInfo_t*>::iterator it= mRemoteFileInfoList.begin(); it!=mRemoteFileInfoList.end(); it ++){
            RemoteFileInfo_t*rfi = *it;
			if(rfi){
				delete rfi;
			}
        }
		mRemoteFileInfoList.clear();
	}
	struct RemoteDirInfo*mParent;
	list<RemoteFileInfo_t*>mRemoteFileInfoList;
	RemoteFileInfo*GetRemoteFileInfo(int index){
		int i=0;
		for(list<RemoteFileInfo_t*>::iterator it= mRemoteFileInfoList.begin(); it!=mRemoteFileInfoList.end(); it++,i++){
            RemoteFileInfo_t*rfi = *it;
			if(i==index){
				return rfi;
			}
        }
		return 0;
	}
	int RemoveRemoteFileInfo(int index){
		int i=0;
		for(list<RemoteFileInfo_t*>::iterator it= mRemoteFileInfoList.begin(); it!=mRemoteFileInfoList.end(); it++,i++){
            RemoteFileInfo_t*rfi = *it;
			if(i==index){
				mRemoteFileInfoList.remove(rfi);
				return 1;
			}
        }
		return 0;
	}

    Boolean_t parseJSON(JSONObject &jsdata) {
        
            JSONObject *jsroot = jsdata.getJSONObject("dir");
            if (jsroot) {
                jsroot->getString("n",name);
                jsroot->getInt("t",type);
                JSONArray*jfilelist=jsroot->getJSONArray("l");
				if(jfilelist){
					for(int i=0;i<jfilelist->getLength();i++){
						JSONObject*jfile=jfilelist->getJSONObject(i);
						if(jfile){
							RemoteFileInfo_t*rfi=new RemoteFileInfo_t;
							char cpath[1024]={0};
							int low=0,high=0;
							jfile->getString("n",rfi->name);
							sprintf(cpath,"%s/%s",path.c_str(),rfi->name.c_str());
							rfi->path=cpath;
							jfile->getInt("t",rfi->type);
							if(rfi->type==8){
								jfile->getInt("sl",low);
								jfile->getInt("sh",high);
								//Log("low:%d high:%d\n",low,high);
							}
							rfi->size=((unsigned int)low)|(((unsigned long long)high)<<32);

							mRemoteFileInfoList.push_back(rfi);
						}
					}
				}
            }
        
        return true;
    }

}RemoteDirInfo_t;

typedef enum{
	REC_TYPE_NORMAL = 0,
	REC_TYPE_MOTION_DETECT,
	REC_TYPE_OBJECT_DETECT,
	REC_TYPE_SOUND_DETECT,
	REC_TYPE_CRY_DETECT,
	REC_TYPE_HUMAN_SHAPE_DETECT,
	REC_TYPE_FACE_DETECT
}REC_TYPE_et;
	
#define REC_FILE_MOTION_DETECT_SIGNATURE "md"
#define REC_FILE_OBJECT_DETECT_SIGNATURE "od"
#define REC_FILE_SOUND_DETECT_SIGNATURE "snd"
#define REC_FILE_CRY_DETECT_SIGNATURE "cd"
#define REC_FILE_HUMAN_SHAPE_DETECT_SIGNATURE "hsd"
#define REC_FILE_FACE_DETECT_SIGNATURE "fd"

typedef struct RecordPeriod{
    int start;
	int end;
	REC_TYPE_et type;
}RecordPeriod_t;

typedef struct RecordDatePeriod{
	int vi;
	int date;//20200223 ��ʾ 2020��2��23��
    list<RecordPeriod_t*>mNormalRecordPeriodList;
	list<RecordPeriod_t*>mMoveDetectRecordPeriodList;
	list<RecordPeriod_t*>mObjectDetectRecordPeriodList;
	list<RecordPeriod_t*>mSoundDetectRecordPeriodList;
	list<RecordPeriod_t*>mCryDetectRecordPeriodList;
	list<RecordPeriod_t*>mHumanShapeDetectRecordPeriodList;
	list<RecordPeriod_t*>mFaceDetectRecordPeriodList;
	void cleanList(){
		while(mNormalRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mNormalRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mNormalRecordPeriodList.remove(rfi);
			delete rfi;
		}
		while(mMoveDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mMoveDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mMoveDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
		while(mObjectDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mObjectDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mObjectDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
		while(mSoundDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mSoundDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mSoundDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
		while(mCryDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mCryDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mCryDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
		while(mHumanShapeDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mHumanShapeDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mHumanShapeDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
		while(mFaceDetectRecordPeriodList.size()>0){
			list<RecordPeriod_t*>::iterator it= mFaceDetectRecordPeriodList.begin();
			RecordPeriod_t*rfi = *it;
			mFaceDetectRecordPeriodList.remove(rfi);
			delete(rfi);
		}
	}
	Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("RecInfo");
        if (jsroot) {
			jsroot->getInt("vi",vi);
			jsroot->getInt("date",date);
			JSONArray *japerriod = jsroot->getJSONArray("period");
            if(japerriod){
				for(int i=0;i<japerriod->getLength();i++){
					JSONObject *jperiod = japerriod->getJSONObject(i);
					int start = 0;
					int end = 0;
					int type = 0;
					int ret=1;
					ret = jperiod->getInt("start", start);
					ret &= jperiod->getInt("end", end);
					ret &= jperiod->getInt("type", type);
					if(ret==0){
						Log("RecordDatePeriod:parseJSON:%d parse error!\n", __LINE__);
						delete jperiod;
						continue;
					}
					RecordPeriod_t*prp=new RecordPeriod_t;
					prp->type = (REC_TYPE_et)type;
					prp->start = start;
					prp->end = end;
					int found=0;
					switch(type){
					case REC_TYPE_NORMAL:
						for(list<RecordPeriod_t*>::iterator it= mNormalRecordPeriodList.begin(); it!=mNormalRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mNormalRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_MOTION_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mMoveDetectRecordPeriodList.begin(); it!=mMoveDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mMoveDetectRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_OBJECT_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mObjectDetectRecordPeriodList.begin(); it!=mObjectDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mObjectDetectRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_SOUND_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mSoundDetectRecordPeriodList.begin(); it!=mSoundDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mSoundDetectRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_CRY_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mCryDetectRecordPeriodList.begin(); it!=mCryDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mCryDetectRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_HUMAN_SHAPE_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mHumanShapeDetectRecordPeriodList.begin(); it!=mHumanShapeDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mHumanShapeDetectRecordPeriodList.push_back(prp);
					break;
					case REC_TYPE_FACE_DETECT:
						for(list<RecordPeriod_t*>::iterator it= mFaceDetectRecordPeriodList.begin(); it!=mFaceDetectRecordPeriodList.end(); it++){
							RecordPeriod_t*rfi = *it;
							if(rfi->start<=start && rfi->end>=end && rfi->type==type){
								found=1;
								break;
							}
						}
						if(found==1){
							free(prp);
						}else
						mFaceDetectRecordPeriodList.push_back(prp);
					break;
					}
					delete jperiod;
				}
				delete japerriod;
			}
			delete jsroot;
        }
        
        return true;
    }
}RecordDatePeriod_t;

typedef struct IPCPtzCtrlMsg{
	int Vi;
	int Ch;
    int CtrlCmd;    //��������
    int Speed;      //�ٶ�
    int RunTimes;    //Ѳ��������Ѳ���������ʹ��
    int Position;    //�����λʹ��
	IPCPtzCtrlMsg(){
		Vi=0;
		Ch = 1;
	}
    Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("PtzCtrlMsg.info");
        if (jsroot) {
			jsroot->getInt("Vi",Vi);
			jsroot->getInt("Ch",Ch);
            jsroot->getInt("CtrlCmd",CtrlCmd);
            jsroot->getInt("Speed",Speed);
            jsroot->getInt("RunTimes",RunTimes);
            jsroot->getInt("Position",Position);
			delete jsroot;
        }
        
        return true;
    }

    int toJSONString(String&str){
        JSONObject jsroot;// = new JSONObject();

        JSONObject jsethnetwork;// = new JSONObject();
		jsethnetwork.put("Vi", Vi);
		jsethnetwork.put("ViCh", Ch);
		jsethnetwork.put("Ch", Ch);
        jsethnetwork.put("CtrlCmd", CtrlCmd);
        jsethnetwork.put("Speed", Speed);
        jsethnetwork.put("Position", Position);
        jsethnetwork.put("RunTimes", RunTimes);
        jsroot.put("PtzCtrlMsg.info", jsethnetwork);

		jsroot.toString(str);
        return str.length();
    }
}IPCPtzCtrlMsg_st;

typedef struct IPCNetManualExpInfo{
    int MeLineEnable;//�ֶ����ÿ���
	int MeLineEnum;	//shutter_list����

	int MeAgEnable;	//ģ������ʹ�ܿ���
	int MeAgVal;		//ģ����������//0x400~0xFFFFFFFF
	ValueRange_t MeAgRange;
	
	int MeDgEnable;	//������������ʹ�ܿ���
	int MeDgVal;		//������������//0x400~0xFFFFFFFF
	ValueRange_t MeDgRange;

	int MeIspDgEnable;	//������������ʹ�ܿ���
	int MeIspDgVal;		//������������//0x400~0xFFFFFFFF
	ValueRange_t MeIspDgRange;

	int MeExpGainEn;
	int MeExpGainVal;
	ValueRange_t MeExpGainRange;

	int *ShutterList;
	int ShutterListCount;
	IPCNetManualExpInfo(){
		ShutterList=0;
		ShutterListCount=0;
	}
	~IPCNetManualExpInfo(){
		if(ShutterList){
			delete[] ShutterList;
			ShutterList=0;
			ShutterListCount=0;
		}
	}

    Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("IspExpMan.info");
        if (jsroot) {
            jsroot->getInt("MeLineEnable",MeLineEnable);
            jsroot->getInt("MeLineEnum",MeLineEnum);

            jsroot->getInt("MeAgEnable",MeAgEnable);
            jsroot->getInt("MeAgVal",MeAgVal);
			JSONObject *jsvalrange = jsroot->getJSONObject("MeAgRange");
			if(jsvalrange){
				jsvalrange->getInt("Start", MeAgRange.Start);
				jsvalrange->getInt("End", MeAgRange.End);
				delete jsvalrange;
			}else{
				MeAgRange.Start = 0;
				MeAgRange.End = 0;
			}

			jsroot->getInt("MeDgEnable",MeDgEnable);
			jsroot->getInt("MeDgVal",MeDgVal);
			jsvalrange = jsroot->getJSONObject("MeDgRange");
			if(jsvalrange){
				jsvalrange->getInt("Start", MeDgRange.Start);
				jsvalrange->getInt("End", MeDgRange.End);
				delete jsvalrange;
			}else{
				MeDgRange.Start = 0;
				MeDgRange.End = 0;
			}

			jsroot->getInt("MeIspDgEnable",MeIspDgEnable);
			jsroot->getInt("MeIspDgVal",MeIspDgVal);
			jsvalrange = jsroot->getJSONObject("MeIspDgRange");
			if(jsvalrange){
				jsvalrange->getInt("Start", MeIspDgRange.Start);
				jsvalrange->getInt("End", MeIspDgRange.End);
				delete jsvalrange;
			}else{
				MeIspDgRange.Start = 0;
				MeIspDgRange.End = 0;
			}

			jsroot->getInt("MeExpGainEn",MeExpGainEn);
			jsroot->getInt("MeExpGainVal",MeExpGainVal);
			jsvalrange = jsroot->getJSONObject("MeExpGainRange");
			if(jsvalrange){
				jsvalrange->getInt("Start", MeExpGainRange.Start);
				jsvalrange->getInt("End", MeExpGainRange.End);
				delete jsvalrange;
			}else{
				MeExpGainRange.Start = 0;
				MeExpGainRange.End = 0;
			}

			JSONArray*jaShutterList=jsroot->getJSONArray("ShutterList");
			if(jaShutterList){
				ShutterListCount=jaShutterList->getLength();
				ShutterList=new int[ShutterListCount];
				for(int i=0;i<ShutterListCount;i++){
					jaShutterList->getInt(i,ShutterList[i]);
				}
				delete jaShutterList;
			}
			delete jsroot;
        }
        
        return true;
    }

    int toJSONString(String&str){
        JSONObject jsroot;// = new JSONObject();

        JSONObject jsethnetwork;// = new JSONObject();
        jsethnetwork.put("MeLineEnable", MeLineEnable==1?1:0);
        jsethnetwork.put("MeLineEnum", MeLineEnum);

        jsethnetwork.put("MeAgEnable", MeAgEnable==1?1:0);
        jsethnetwork.put("MeAgVal", MeAgVal);

		jsethnetwork.put("MeDgEnable", MeDgEnable==1?1:0);
        jsethnetwork.put("MeDgVal", MeDgVal);

		jsethnetwork.put("MeIspDgEnable", MeIspDgEnable==1?1:0);
        jsethnetwork.put("MeIspDgVal", MeIspDgVal);

		jsethnetwork.put("MeExpGainEn", MeExpGainEn==1?1:0);
        jsethnetwork.put("MeExpGainVal", MeExpGainVal);

		JSONArray jaShutterList;
		for(int i=0;i<ShutterListCount;i++){
			jaShutterList.put(i,ShutterList[i]);
		}
		jsethnetwork.put("ShutterList", jaShutterList);

        jsroot.put("IspExpMan.info", jsethnetwork);

		jsroot.toString(str);
        return str.length();
    }
}IPCNetManualExpInfo_st;

typedef struct IPCNetAutoExpInfo{
    int compansation;	//���� //0x0~0xFF
	int AgMin;//0x400~0xFFFFFFFF
	int AgMax;//0x400~0xFFFFFFFF
	int DgMin;//0x400~0xFFFFFFFF
	int DgMax;//0x400~0xFFFFFFFF
	int ExpoType;	//֡�����ȡ��������	
	
    Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("IspExpAuto.info");
        if (jsroot) {
            jsroot->getInt("compansation",compansation);
            jsroot->getInt("AgMin",AgMin);
            jsroot->getInt("AgMax",AgMax);
			
            jsroot->getInt("DgMin",DgMin);
			jsroot->getInt("DgMax",DgMax);

			jsroot->getInt("ExpoType",ExpoType);
			delete jsroot;
        }
        
        return true;
    }

    int toJSONString(String&str){
        JSONObject jsroot;// = new JSONObject();

        JSONObject jsethnetwork;// = new JSONObject();
        jsethnetwork.put("compansation", compansation);

        jsethnetwork.put("AgMin", AgMin);
        jsethnetwork.put("AgMax", AgMax);

        jsethnetwork.put("DgMin", DgMin);
		jsethnetwork.put("DgMax", DgMax);

        jsethnetwork.put("ExpoType", ExpoType);

        jsroot.put("IspExpAuto.info", jsethnetwork);

		jsroot.toString(str);
        return str.length();
    }
}IPCNetAutoExp_st;

typedef struct IPCNetExpType{
    int type;//0:auto exposure  1:manual exposure
	
    Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("IspExpType.info");
        if (jsroot) {
            jsroot->getInt("type",type);
			delete jsroot;
        }
        
        return true;
    }

    int toJSONString(String&str){
        JSONObject jsroot;// = new JSONObject();

        JSONObject jsethnetwork;// = new JSONObject();
        jsethnetwork.put("type", type);

        jsroot.put("IspExpType.info", jsethnetwork);

		jsroot.toString(str);
        return str.length();
    }
}IPCNetExpType_st;

typedef struct IPCNetWiFiAPInfo{
	Boolean_t Enable;
	Boolean_t DHCP;
	String EncType;

	Boolean_t HideSSID;
	int MaxNumSta;

	Boolean_t UseCustom;//0:use Ssid to set as AP's SSID,  1:use Prefix,Dot and Subfix to build SSID

	//if UseCustom is 1,  SSID will be  [Prefix][Dot][Subfix]
	//Prefix=TP-LINK   Dot=_   SufixMode=1   SufixUuidPos=0    SufixLen=5   device's UUID = ABCD000000EDFGH, then the AP'SSID is TP-LINK_EDFGH
	String Prefix;
	String Dot;
	Boolean_t SufixMode;// 0:from start, 1:from end
	int SufixUuidPos;
	int SufixLen;

	String Ssid;
	String Pwd;

	String IP;
	String Netmask;
	String Getway;
	Boolean_t parseJSON(JSONObject &jsdata){
	   
		JSONObject *jsroot= jsdata.getJSONObject("NetWork.WiFiAP");
		if(jsroot){
			jsroot->getBoolean("Enable",Enable);
			jsroot->getBoolean("DHCP",DHCP);
			jsroot->getString("EncType",EncType);
			jsroot->getBoolean("UseCustom",UseCustom);

			jsroot->getInt("MaxNumSta",MaxNumSta);
			jsroot->getBoolean("HideSSID",HideSSID);

			jsroot->getString("Prefix",Prefix);
			jsroot->getString("Dot",Dot);
			//jsroot->getInt("SufixMode",SufixMode);
			jsroot->getBoolean("SufixMode",SufixMode);
			jsroot->getInt("SufixUuidPos",SufixUuidPos);
			jsroot->getInt("SufixLen",SufixLen);

			jsroot->getString("Ssid",Ssid);
			jsroot->getString("Pwd",Pwd);

			jsroot->getString("IP",IP);
			jsroot->getString("Netmask",Netmask);
			jsroot->getString("Getway",Getway);

			delete jsroot;
		}else{
			return false;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		jsresult.put("Enable", Enable);
		jsresult.put("DHCP", DHCP);
		jsresult.put("EncType", EncType);
		jsresult.put("UseCustom",UseCustom);

		jsresult.put("MaxNumSta", MaxNumSta);
		jsresult.put("HideSSID",HideSSID);

		jsresult.put("Prefix", Prefix);
		jsresult.put("Dot", Dot);
		jsresult.put("SufixMode", SufixMode);
		jsresult.put("SufixUuidPos", SufixUuidPos);
		jsresult.put("SufixLen", SufixLen);

		jsresult.put("Ssid", Ssid);
		jsresult.put("Pwd", Pwd);

		jsresult.put("IP", IP);
		jsresult.put("Netmask", Netmask);
		jsresult.put("Getway", Getway);
		jsroot.put("NetWork.WiFiAP", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetWiFiAPInfo_t;

typedef struct IPCNetWiredNetworkStrategy{
    Boolean_t RouteToAP;
}IPCNetWiredNetworkStrategy_st;

typedef struct IPCNetWiFiNetworkStrategy{
    Boolean_t ForceToAP;//ǿ���л���AP
    Boolean_t RouteToWiredNetwork;//·�ɵ���������
}IPCNetWiFiNetworkStrategy_st;

typedef struct IPCNetMobileNetworkStrategy{
    Boolean_t RouteToWiredNetwork;//·�ɵ���������
    Boolean_t RouteToAP;
}IPCNetMobileNetworkStrategy_st;

#define MAX_PRIO_NUM 5
typedef struct IPCNetNetworkStrategy{
    String CurNetwork;

	int PrioSeqNum;
    String PrioSeq[MAX_PRIO_NUM];//Wired,WiFi,Mobile

    Boolean_t NotNetworkAP;

    IPCNetWiredNetworkStrategy_st WiredNetworkStrategy;
    IPCNetWiFiNetworkStrategy_st WiFiNetworkStrategy;
    IPCNetMobileNetworkStrategy_st MobileNetworkStrategy;

	IPCNetNetworkStrategy(){
		PrioSeqNum=0;
	}
    Boolean_t parseJSON(JSONObject &jsdata) {
        //try {
            JSONObject *jsroot = jsdata.getJSONObject("NetworkStrategy");
            if (jsroot != NULL) {
                jsroot->getBoolean("NotNetworkAP", NotNetworkAP);
                jsroot->getString("CurNetwork", CurNetwork);
                JSONArray *jaPrioSeq = jsroot->getJSONArray("PrioSeq");
				if(jaPrioSeq!=NULL){
					PrioSeqNum = jaPrioSeq->getLength();
					PrioSeqNum = PrioSeqNum>MAX_PRIO_NUM?MAX_PRIO_NUM:PrioSeqNum;
					for(int i=0;i<PrioSeqNum;i++){
						jaPrioSeq->getString(i, PrioSeq[i]);
					}
					delete jaPrioSeq;
				}
                JSONObject *jsob = jsroot->getJSONObject("WiredNetworkStrategy");
				if(jsob!=NULL){
					jsob->getBoolean("RouteToAP", WiredNetworkStrategy.RouteToAP);
					delete jsob;
				}

                jsob = jsroot->getJSONObject("WiFiNetworkStrategy");
				if(jsob!=NULL){
					jsob->getBoolean("ForceToAP", WiFiNetworkStrategy.ForceToAP);
					jsob->getBoolean("RouteToWiredNetwork", WiFiNetworkStrategy.RouteToWiredNetwork);
					delete jsob;
				}

                jsob = jsroot->getJSONObject("MobileNetworkStrategy");
				if(jsob!=NULL){
					jsob->getBoolean("RouteToAP", MobileNetworkStrategy.RouteToAP);
					jsob->getBoolean("RouteToWiredNetwork", MobileNetworkStrategy.RouteToWiredNetwork);
					delete jsob;
				}
            }
        //} catch (JSONException e) {
        //    e.printStackTrace();
        //    return false;
        //}
        return 1;
    }

    int toJSONString(String&str) {
        JSONObject jsroot;
        //try {
            JSONObject jsethnetwork;
            jsethnetwork.put("NotNetworkAP", NotNetworkAP);
            jsethnetwork.put("CurNetwork", CurNetwork);
            if(PrioSeqNum>0 && PrioSeqNum<MAX_PRIO_NUM){
                JSONArray jaPrioSeq;
                for(int i=0;i<PrioSeqNum;i++){
                    jaPrioSeq.put(i, PrioSeq[i]);
                }
                jsethnetwork.put("PrioSeq", jaPrioSeq);
            }else{
                Log("PrioSeq is null");
                return 0;
            }

            JSONObject jsob;
            jsob.put("RouteToAP", WiredNetworkStrategy.RouteToAP);
            jsethnetwork.put("WiredNetworkStrategy", jsob);

            JSONObject jsob1;
            jsob1.put("ForceToAP", WiFiNetworkStrategy.ForceToAP);
            jsob1.put("RouteToWiredNetwork", WiFiNetworkStrategy.RouteToWiredNetwork);
            jsethnetwork.put("WiFiNetworkStrategy", jsob1);

            JSONObject jsob2;
            jsob2.put("RouteToAP", MobileNetworkStrategy.RouteToAP);
            jsob2.put("RouteToWiredNetwork", MobileNetworkStrategy.RouteToWiredNetwork);
            jsethnetwork.put("MobileNetworkStrategy", jsob2);

            jsroot.put("NetworkStrategy", jsethnetwork);
        //} catch (JSONException e) {
        //    e.printStackTrace();
        //    return null;
        //}
			jsroot.toString(str);
		return str.length();
    }
}IPCNetNetworkStrategy_st;

typedef struct IPCNetRemoteFileOperation{
	//"{\"rfop\":{\"si\":" + sensorIndex + ",\"t\":\"" + uuid + "\",\"p\":\"" + path + "\",\"op\":" + op + "}}";
	int sensorIndex;
	String uuid;
	String path;
	int op;//operation
	int speed;
	int stm;

	Boolean_t parseJSON(JSONObject &jsdata){
	   
		JSONObject *jsroot= jsdata.getJSONObject("rfop");
		if(jsroot){
			jsroot->getInt("si",sensorIndex);
			jsroot->getString("t",uuid);
			jsroot->getString("p",path);
			jsroot->getInt("op",op);
			jsroot->getInt("speed",speed);
			delete jsroot;
		}else{
			return false;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		jsresult.put("si", sensorIndex);
		jsresult.put("t", uuid);
		jsresult.put("p", path);
		jsresult.put("op", op);
		if(op==AV_RECO_OP_RIGHT_REQ || op==AV_RECO_OP_LEFT_REQ)
			jsresult.put("speed",speed);
		if(op==AV_RECO_OP_SEEK_REQ)
			jsresult.put("stm",stm);

		jsroot.put("rfop", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetRemoteFileOperation_t;

typedef struct
{
	Boolean_t b2DDenoiseEn;
	int u2DDenoiseType;//0:auto, 1:manual
	int u2DDenoiseStrength;

	Boolean_t b3DDenoiseEn;//no used
	int u3DDenoiseType;//0:auto, 1:manual,  no used
	int s3DGlobalStrength;
	int s3DSFStrength;
	int s3DTFStrength;
	Boolean_t parseJSON(JSONObject &jsdata){
	   
		JSONObject *jsroot= jsdata.getJSONObject("IspDenoise.info");
		if(jsroot){
			jsroot->getBoolean("b2DDenoiseEn",b2DDenoiseEn);
			jsroot->getInt("u2DDenoiseType",u2DDenoiseType);
			jsroot->getInt("u2DDenoiseStrength",u2DDenoiseStrength);

			jsroot->getBoolean("b3DDenoiseEn",b3DDenoiseEn);
			jsroot->getInt("u3DDenoiseType",u3DDenoiseType);
			jsroot->getInt("s3DGlobalStrength",s3DGlobalStrength);
			jsroot->getInt("s3DSFStrength",s3DSFStrength);
			jsroot->getInt("s3DTFStrength",s3DTFStrength);

			delete jsroot;
		}else{
			return false;
		}
		
	    return true;
	}
	int toJSONString(String&str){
		JSONObject jsroot;// = new JSONObject();
		
		JSONObject jsresult;// = new JSONObject();
		jsresult.put("b2DDenoiseEn", b2DDenoiseEn);
		jsresult.put("u2DDenoiseType", u2DDenoiseType);
		jsresult.put("u2DDenoiseStrength", u2DDenoiseStrength);

		jsresult.put("b3DDenoiseEn", b3DDenoiseEn);
		jsresult.put("u3DDenoiseType", u3DDenoiseType);
		jsresult.put("s3DGlobalStrength", s3DGlobalStrength);
		jsresult.put("s3DSFStrength", s3DSFStrength);
		jsresult.put("s3DTFStrength", s3DTFStrength);

		jsroot.put("IspDenoise.info", jsresult);
		
		jsroot.toString(str);
		return str.length();
	}
}IPCNetDeNoiseInfo_st;

typedef struct IPCNetInputAudioCfg
{
	Boolean_t Mute;//����

	String Enc;
	list<String> EncList;
	
	String Src;
	list<String> SrcList;
	
	int SampleFreq;
	list<int> SampleFreqList;

	int Bitrate;
	int BitrateMin;
	int BitrateMax;

	int Chnl;//0:mono 1:stereo
	int ChnlMax;

	int Vol;
	IPCNetInputAudioCfg(){
		EncList.clear();
		SrcList.clear();
		SampleFreqList.clear();
	}
	~IPCNetInputAudioCfg(){
		EncList.clear();
		SrcList.clear();
		SampleFreqList.clear();
	}
}IPCNetInputAudioCfg_st;
typedef struct IPCNetOutputAudioCfg
{
	Boolean_t Mute;

	String Dec;
	list<String> DecList;
	T_S32 Vol;
	IPCNetOutputAudioCfg(){
		DecList.clear();
	}
	~IPCNetOutputAudioCfg(){
		DecList.clear();
	}
}IPCNetOutputAudioCfg_st;
typedef struct IPCNetAudioCfg{
    int AiCh;
	Boolean_t AecEnable;//��������
	Boolean_t AecSupported;
	IPCNetInputAudioCfg_st AudioInCfg;
	IPCNetOutputAudioCfg_st AudioOutCfg;
	
    Boolean_t parseJSON(JSONObject &jsdata) {
        JSONObject *jsroot = jsdata.getJSONObject("AudioCfg");
        if (jsroot) {
			int i;
            jsroot->getInt("AiCh",AiCh);
			jsroot->getBoolean("AecEnable",AecEnable);
			jsroot->getBoolean("AecSupported",AecSupported);
			JSONObject *jsAudioInCfg = jsdata.getJSONObject("AudioInCfg");
			if(jsAudioInCfg){
				jsAudioInCfg->getBoolean("Mute", AudioInCfg.Mute);

				jsAudioInCfg->getString("Enc", AudioInCfg.Enc);
				AudioInCfg.EncList.clear();
				JSONArray*jsEncList = jsAudioInCfg->getJSONArray("EncList");
				if(jsEncList){
					int num = jsEncList->getLength();
					for(i=0;i<num;i++){
						String strenc;
						if(jsEncList->getString(i, strenc)){
							AudioInCfg.EncList.push_back(strenc);
						}
					}
					delete jsEncList;
				}

				jsAudioInCfg->getString("Src", AudioInCfg.Src);
				AudioInCfg.SrcList.clear();
				JSONArray*jsSrcList = jsAudioInCfg->getJSONArray("SrcList");
				if(jsSrcList){
					int num = jsSrcList->getLength();
					for(i=0;i<num;i++){
						String strenc;
						if(jsSrcList->getString(i, strenc)){
							AudioInCfg.SrcList.push_back(strenc);
						}
					}
					delete jsSrcList;
				}

				jsAudioInCfg->getInt("SampleFreq", AudioInCfg.SampleFreq);
				AudioInCfg.SampleFreqList.clear();
				JSONArray*jsSampleFreqList = jsAudioInCfg->getJSONArray("SampleFreqList");
				if(jsSampleFreqList){
					int num = jsSampleFreqList->getLength();
					for(i=0;i<num;i++){
						int sampleRate=0;
						if(jsSampleFreqList->getInt(i, sampleRate)){
							AudioInCfg.SampleFreqList.push_back(sampleRate);
						}
					}
					delete jsSampleFreqList;
				}

				jsAudioInCfg->getInt("Bitrate", AudioInCfg.Bitrate);
				jsAudioInCfg->getInt("BitrateMin", AudioInCfg.BitrateMin);
				jsAudioInCfg->getInt("BitrateMax", AudioInCfg.BitrateMax);

				jsAudioInCfg->getInt("Chnl", AudioInCfg.Chnl);
				jsAudioInCfg->getInt("ChnlMax", AudioInCfg.ChnlMax);

				jsAudioInCfg->getInt("Vol", AudioInCfg.Vol);

				delete jsAudioInCfg;
			}
			JSONObject *jsAudioOutCfg = jsdata.getJSONObject("AudioOutCfg");
			if(jsAudioOutCfg){
				jsAudioOutCfg->getBoolean("Mute", AudioOutCfg.Mute);
				jsAudioOutCfg->getString("Dec", AudioOutCfg.Dec);
				AudioOutCfg.DecList.clear();
				JSONArray*jsDecList = jsAudioInCfg->getJSONArray("DecList");
				if(jsDecList){
					int num = jsDecList->getLength();
					for(i=0;i<num;i++){
						String strenc;
						if(jsDecList->getString(i, strenc)){
							AudioOutCfg.DecList.push_back(strenc);
						}
					}
					delete jsDecList;
				}
				delete jsAudioOutCfg;
			}

			delete jsroot;
        }
        
        return true;
    }

    int toJSONString(String&str){
        JSONObject jsroot;// = new JSONObject();

        JSONObject jsAudioCfg;// = new JSONObject();
        jsAudioCfg.put("AiCh", AiCh);
		jsAudioCfg.put("AecEnable", AecEnable);

		//-------------------------
		JSONObject jsAudioInCfg;
		jsAudioInCfg.put("Mute", AudioInCfg.Mute);
		jsAudioInCfg.put("Enc", AudioInCfg.Enc);
		jsAudioInCfg.put("Src", AudioInCfg.Src);
		jsAudioInCfg.put("SampleFreq", AudioInCfg.SampleFreq);
		jsAudioInCfg.put("Bitrate", AudioInCfg.Bitrate);
		jsAudioInCfg.put("Chnl", AudioInCfg.Chnl);
		jsAudioInCfg.put("Vol", AudioInCfg.Vol);
		jsAudioCfg.put("AudioInCfg", jsAudioInCfg);
		//-------------------------
		JSONObject jsAudioOutCfg;
		jsAudioOutCfg.put("Mute", AudioOutCfg.Mute);
		jsAudioOutCfg.put("Dec", AudioOutCfg.Dec);
		jsAudioOutCfg.put("Vol", AudioOutCfg.Vol);
		jsAudioCfg.put("AudioOutCfg", jsAudioOutCfg);

        jsroot.put("AudioCfg", jsAudioCfg);

		jsroot.toString(str);
        return str.length();
    }
}IPCNetAudioCfg_st;

#endif

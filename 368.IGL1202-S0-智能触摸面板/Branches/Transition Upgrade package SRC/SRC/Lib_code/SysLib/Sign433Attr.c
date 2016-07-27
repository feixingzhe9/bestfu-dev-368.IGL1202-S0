/***************************Copyright BestFu ***********************************
**  文    件：  Sign433Attr.c
**  功    能：  433信号强度测试属性接口层(被测设备)
**  编    译：  Keil uVision5 V4.72
**  版    本：  V1.0
**  编    写：  Seven
**  创建日期：  2014.10.08
**  修改日期：  2014.10.22
**  说    明：  
*******************************************************************************/
#include "Sign433.h"
#include "Sign433Attr.h"
#include "MsgPackage.h"
#include "UserData.h"
#include "SI4432.h"
#include "Thread.h"

//	{0xB0, LEVEL_0, Set_Sign433_StartSendFrame_Attr , Get_Sign433_StartSendFrame_Attr	},    //启动发送测试
//  {0xB1, LEVEL_0, Set_Sign433_StartRecFrame_Attr  , Get_Sign433_StartRecFrame_Attr    },    //启动接收测试
//	{0xB2, LEVEL_0, Set_Sign433_RecFrameStream_Attr	, NULL					            },    //接收测试数据帧流
//  //{0XB3,0XB4 } 预留
//  {0xBF, LEVEL_0, Set_Sign433_TestState_Attr		, Get_Sign433_TestState_Attr		},    //中断测试

#define STATE_IDLE           0       //空闲状态
#define STATE_SEND_TEST      1       //从机发送状态
#define STATE_REC_TEST       2       //从机接收状态

/*******************************************************************************
**函    数： Set_Sign433_StartSendFrame_Attr()
**功    能： （接收主机测试命令）并启动一次发送信号测量
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xB0   
********************************************************************************/
MsgResult_t Set_Sign433_StartSendFrame_Attr(UnitPara_t *pData)
{
    if( Sign433_State != STATE_IDLE )    return CMD_EXE_ERR;
    else Sign433_State = STATE_SEND_TEST;
    
    gSign433Comm.MasterID              = *(u32*)&pData->data[0]; 
    gSign433Comm.SlaveID               = *(u32*)&pData->data[4];
    gSign433Comm.TestPkgInfo.Number    = pData->data[8];    
    gSign433Comm.TestPkgInfo.Length    = pData->data[9];
    gSign433Comm.TestPkgInfo.TimeSpace = *(u16*)&pData->data[10];
       
    Sign433_SendTestFrameStream();//启动信号发送测试
    
    return COMPLETE;
}
/*******************************************************************************
**函    数： Get_Sign433_MasterAddr
**功    能： 获取测试主机的地址
**参    数： 无
**返    回： 测试主机address
**说    明： 无
********************************************************************************/
u32 Get_Sign433_MasterAddr(void)
{
	return (*(u32*)&gSign433Comm) ;
}
/*******************************************************************************
**函    数： Get_Sign433_StartSendFrame_Attr()
**功    能： 读取发送信号测试状态
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xB0   
********************************************************************************/
MsgResult_t Get_Sign433_StartSendFrame_Attr(UnitPara_t *pData, u8 *rlen, u8 *rpara)
{
    *rlen = 13;
    
    *(u32*)&rpara[0] = gSign433Comm.MasterID ;
    *(u32*)&rpara[4] = gSign433Comm.SlaveID  ;
    rpara[8]         = gSign433Comm.TestPkgInfo.Number ;
    rpara[9]         = gSign433Comm.TestPkgInfo.Length ;
    *(u16*)&rpara[10]= gSign433Comm.TestPkgInfo.TimeSpace ;
    rpara[12]        = Sign433_State ;  //当前测试状态
    
    return COMPLETE;
}

/*******************************************************************************
**函    数： Set_Sign433_StartRecFrame_Attr()
**功    能： （接收主机测试命令）并启动一次 接收信号测量
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xB1  
********************************************************************************/
MsgResult_t Set_Sign433_StartRecFrame_Attr(UnitPara_t *pData)
{
    u8 *pRSSI = NULL;
    if(Sign433_State != STATE_SEND_TEST)    return CMD_EXE_ERR;
    else Sign433_State = STATE_REC_TEST;
    
    gSign433Comm.MasterID              = *(u32*)&pData->data[0]; 
    gSign433Comm.SlaveID               = *(u32*)&pData->data[4]; //gSysData.deviceID;
    gSign433Comm.TestPkgInfo.Number    = pData->data[8];    
    gSign433Comm.TestPkgInfo.Length    = pData->data[9];
    gSign433Comm.TestPkgInfo.TimeSpace = *(u16*)&pData->data[10];
    
    //清接收RSSI数组
	SetRecTestStatus(1);
	pRSSI=GetRSSIPara();
	memset(pRSSI, 0, gSign433Comm.TestPkgInfo.Number+1);

    return COMPLETE;
}

/*******************************************************************************
**函    数： Get_Sign433_StartRecFrame_Attr()
**功    能： 读取接收测试参数
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xB1   
********************************************************************************/
MsgResult_t Get_Sign433_StartRecFrame_Attr(UnitPara_t *pData, u8 *rlen, u8 *rpara)
{
    *rlen = 13;
    
    *(u32*)&rpara[0] = gSign433Comm.MasterID ;
    *(u32*)&rpara[4] = gSign433Comm.SlaveID  ;
    rpara[8]         = gSign433Comm.TestPkgInfo.Number ;
    rpara[9]         = gSign433Comm.TestPkgInfo.Length ;
    *(u16*)&rpara[10]= gSign433Comm.TestPkgInfo.TimeSpace ;
    rpara[12]        = Sign433_State ;  //当前测试状态
    
    return COMPLETE;
}

/*******************************************************************************
**函    数： Set_Sign433_RecFrameStream_Attr()
**功    能： 接收测试数据流
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xB2
********************************************************************************/
MsgResult_t Set_Sign433_RecFrameStream_Attr(UnitPara_t *pData)
{
    //接收完成 开启线程进行统计
    if((pData->data[0] == 0XFF)&&(Sign433_State==STATE_REC_TEST))      //结束帧
    {
        Thread_Login(ONCEDELAY, 0, 50, &Sign433_SendTestReport);
        Sign433_State = STATE_IDLE;       
    }
    return COMPLETE;
}


/*******************************************************************************
**函    数： Set_Sign433_TestState_Attr()
**功    能： 设置测试状态--中断当前测试
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xBF
********************************************************************************/
MsgResult_t Set_Sign433_TestState_Attr(UnitPara_t *pData)
{
    Sign433_State = STATE_IDLE;
    return COMPLETE;
}


/*******************************************************************************
**函    数： Get_Sign433_TestState_Attr()
**功    能： 读取测试状态
**参    数： *pData      --输入参数
**返    回： COMPLETE
**说    明： 命令号：0xBF
********************************************************************************/
MsgResult_t Get_Sign433_TestState_Attr(UnitPara_t *pData, u8 *rlen, u8 *rpara)
{
    *rlen = 1;
    rpara[0] = Sign433_State;
    return COMPLETE;
}
    
/***************************Copyright BestFu **********************************/    

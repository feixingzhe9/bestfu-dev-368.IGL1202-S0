/***************************Copyright BestFu ***********************************
**  文    件:   KeyExeAttr.c
**  功    能：  <<属性层>>摁键属性层接口
**  编    译：  Keil uVision5 V5.10
**  版    本：  V1.0.0
**  编    写：  Seven
**  创建日期：  2014/08/21
**  修改日期：  2014/08/21
**  说    明：
**  V1.0
    >> 摁键状态 : 0==无摁键   1==短摁键   2==长按键
*******************************************************************************/
#include "Unitcfg.h"
#include "KeyExeAttr.h" 
#include "BatteryExeAttr.h"
#include "ADC.h"
#include "Key.h"
#include "Battery.h"
#include "Thread.h"
#include "LowPower.h"
#include "ShowLED.h"
#include "USART2.h"
#include "ShakeMotor.h"
#include "OLED.h"
#include "74HC595.h"
#include "iwdg.h"
#include "EEPROM.h"
#include "LowPower.h"
#include "TouchPadPic.h"

//Private Macro definition 
#define  ADDR_PASSWORD     (0x4000)

//Private variable define
u8 first_key = 0;


/*属性读写的接口列表*/
const AttrExe_st KeyAttrTab[] =
{
    {0x01, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},      
    {0x02, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x03, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},      
    {0x04, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x05, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x06, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0}, 
    {0x07, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x08, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x09, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x0A, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x0B, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},       
    {0x0C, LEVEL_1, NULL    			, Get_TouchKey_Attr      	,0},    

	{0x11, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},    
	{0x12, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x13, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x14, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x15, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x16, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x17, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x18, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x19, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x1a, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x1b, LEVEL_1, Set_TouchKey_Attr	, Get_TouchKeyStatus_Attr 	,0},  
	{0x1c, LEVEL_1, Set_TouchKey_Attr 	, Get_TouchKeyStatus_Attr 	,0},   	
	
    {0x30, LEVEL_0, Set_Password_Attr	, Get_Password_Attr 	  	,0},   
    {0xC8, LEVEL_1, NULL    			, Get_PowerPercent_Attr   	,0},    //固定属性  获取电池电量
    {0xC9, LEVEL_1, NULL    			, Get_ChargeState_Attr    	,0},    //固定属性  获取电池充电状态(充电锂电池才有)  
};

/*******************************************************************************
函 数 名:  u8 Key_UnitAttrNum(void)
功能说明:  获取按键单元属性命令的个数
参    数:  无
返 回 值:  返回按键单元属性命令的个数
*******************************************************************************/
u8 Key_UnitAttrNum(void)
{
	return (BF_DIM(KeyAttrTab));
}

/*******************************************************************************
函 数 名:  void KeyLowPowerHandle(void)
功能说明:  面板上电低功耗处理
参    数:  无
返 回 值:  无
*******************************************************************************/
void KeyLowPowerHandle(void)
{ 	
	if(0xFF == (first_key = Key_FirstScan()))
	{
		Standby_Mode();
	}
}

/*******************************************************************************
**函    数： KeyInit
**功    能： 初始化
**参    数： unitID      --单元号
**返    回： void
*******************************************************************************/
void KeyInit(u8 unitID)
{
    u8 i;
	Battery_Init();
    Init_OLED();
    _74HC595_Init();
    ShowLED_OpenAll();
    
    if(1 == Battery_GetPercent(&gPowerPercent))
    {
        if(gPowerPercent <= 8)   //电量小于8%时自动提示用户充电，3s以后休眠
        {
            OLED_ShowPicAt(36,2,56,32,PicPower);
            Thread_Login(ONCEDELAY, 0,3000,&Standby_Mode);
            for(;;);       
        }
    }
    
    EEPROM_Read(ADDR_PASSWORD, 4, &gPassword[0]);
    if((gPassword[0]>6)||(gPassword[1]>6)||(gPassword[2]>6)||(gPassword[3]>6))
    {
        gPassword[0] = 0;
        gPassword[1] = 0;
        gPassword[2] = 0;
        gPassword[3] = 0;
    }
    if((gPassword[0]==0)||(gPassword[1]==0)||(gPassword[2]==0)||(gPassword[3]==0))
    {
        gPswFlag = 0;       //无密码
    }
    else gPswFlag = 1;      //有密码
        
    Thread_Login(FOREVER, 0, 5 , &Key_Handle);           //5ms 按键
    Thread_Login(FOREVER, 0, 100, &LowPower_CheckTime);   //100ms*100 = 10s  睡眠 
    Thread_Login(FOREVER, 0, 200 ,&Battery_Show);    
    
    Get_CurrentKeyState(&gKeyPrevState);
    if((gKeyPrevState.KeyValue > MAX_TOUCH_KEY)||(!gKeyPrevState.KeyValue))
    {
        gKeyPrevState.KeyValue = first_key;
    }
	if((gKeyPrevState.KeyType > KEY_LONG)||(KEY_NONE == gKeyPrevState.KeyType))
	{
		gKeyPrevState.KeyType = KEY_SHORT;
	}
	gKeyCh[gKeyPrevState.KeyValue].Status = gKeyPrevState.KeyType;
	for(i = 1;i < MAX_TOUCH_KEY;i++)
	{
		if(gKeyPrevState.KeyStatusVal[i] > 1)
		{
			gKeyPrevState.KeyStatusVal[i] = SW_OFF;
		}
		gKeyStatus[i].Status = gKeyPrevState.KeyStatusVal[i];
	}
	switch(gKeyPrevState.KeyType)
	{
		case KEY_SHORT:
		{
			if(SW_ON == gKeyStatus[gKeyPrevState.KeyValue].Status)
			{
				OLED_ShowHalfPicAt(4,PicTab[gKeyPrevState.KeyValue]);
			}
			else
			{
				OLED_ShowHalfPicAt(4,PicTab[gKeyPrevState.KeyValue + 32]);
			}
		}break;
		case KEY_LONG:
		{
			OLED_ShowHalfPicAt(4,PicTab[gKeyPrevState.KeyValue + 16]);
		}break;
		default:break;
	}
    Battery_Show_State();
    
    Upload(1);
}

/*******************************************************************************
**函    数： KeyEepromInit
**功    能： 所属 eeprom 初始化
**参    数： unitID      --单元号
**返    回： void
*******************************************************************************/
void KeyEepromInit(u8 unitID)
{
    unitID = unitID;
    //取消密码
    gPassword[0] = 0;
    gPassword[1] = 0;
    gPassword[2] = 0;
    gPassword[3] = 0;
    EEPROM_Write(ADDR_PASSWORD, 4, &gPassword[0]);
    
    gKeyPrevState.KeyType  = KEY_NONE;
    gKeyPrevState.KeyValue = 0xFF;
	memset(gKeyPrevState.KeyStatusVal,0,MAX_TOUCH_KEY);
    EEPROM_Write(ADDR_KEY_CURRENT_STATE,sizeof(KeySta_t),(u8*)&gKeyPrevState);
}

/*******************************************************************************
**函    数： Get_TouchKey_Attr()
**功    能： 获取触摸摁键值
**参    数： *pData      --输入参数
             *rLen       --返回参数长度
             *rData      --返回参数存放地址
**返    回： TRUE/FALSE
********************************************************************************/
MsgResult_t Get_TouchKey_Attr(UnitPara_t *pData, u8 *rLen, u8 *rData)
{
    u8 ch = pData->cmd;
    
    *rLen    = 1;
    rData[0] = gKeyCh[ch].Status;
    
    return COMPLETE;
}

/*******************************************************************************
**函    数:  MsgResult_t Set_TouchKey_Attr(UnitPara_t *pData)
**功    能： 设置触摸按键状态
**参    数： *pData      --输入参数
             *rLen       --返回参数长度
             *rData      --返回参数存放地址
**返    回： TRUE/FALSE
********************************************************************************/
MsgResult_t Set_TouchKey_Attr(UnitPara_t *pData)
{
    u8 ch = pData->cmd - 0x10;
	
	if(pData->len>1)
	{
		return PARA_LEN_ERR;
	}	
	
	gKeyStatus[ch].Status = (KeySWStatus_e)pData->data[0];
	
    return COMPLETE;
}

/*******************************************************************************
**函    数： Get_TouchKeyStatus_Attr()
**功    能： 获取触摸按键状态
**参    数： *pData      --输入参数
             *rLen       --返回参数长度
             *rData      --返回参数存放地址
**返    回： TRUE/FALSE
********************************************************************************/
MsgResult_t Get_TouchKeyStatus_Attr(UnitPara_t *pData, u8 *rLen, u8 *rData)
{
    u8 ch = pData->cmd - 0x10;
    
    *rLen    = 1;
    rData[0] = gKeyStatus[ch].Status;
    
    return COMPLETE;
}

/*******************************************************************************
**功    能： 设置用户密码
**参    数： *pData      --输入参数
             *rLen       --返回参数长度
             *rData      --返回参数存放地址
**返    回： TRUE/FALSE
********************************************************************************/
MsgResult_t Set_Password_Attr(UnitPara_t *pData)
{
    gPassword[0] = pData->data[0] - '0';
    gPassword[1] = pData->data[1] - '0';
    gPassword[2] = pData->data[2] - '0';
    gPassword[3] = pData->data[3] - '0';
    EEPROM_Write(ADDR_PASSWORD, 4, &gPassword[0]);
    
    return COMPLETE;
}
/*******************************************************************************
**功    能： 获取用户密码
**参    数： *pData      --输入参数
             *rLen       --返回参数长度
             *rData      --返回参数存放地址
**返    回： TRUE/FALSE
********************************************************************************/
MsgResult_t Get_Password_Attr(UnitPara_t *pData, u8 *rLen, u8 *rData)
{
    *rLen    = 4;
    rData[0] = gPassword[0]+'0';
    rData[1] = gPassword[1]+'0';
    rData[2] = gPassword[2]+'0';
    rData[3] = gPassword[3]+'0';
    
    return COMPLETE;
}

/*******************************************************************************
**函    数:  KeyChecking_Attr()
**功    能:  验证设备
**参    数:  void
**返    回:  void
********************************************************************************/
void KeyChecking_Attr(void)
{
     Thread_Login(MANY, 6, 200 , &ShowLED_CheckDevice);
}

/***************************Copyright BestFu **********************************/


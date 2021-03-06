/***************************Copyright BestFu ***********************************
**  文    件：  ShowLED.c
**  功    能：  <<逻辑层>> 玻璃面板（74HC595驱动LED灯）制作灯光闪烁效果
**  编    译：  Keil uVision5 V5.10
**  版    本：  V1.1
**  编    写：  Seven
**  创建日期：  2014.08.26
**  修改日期：  2014.08.27
**  说    明：  >>LED灯逻辑位置 与 物理位置 映射  最大支持16个灯
**              >>完成灯光圈左右渐灭渐亮效果
*******************************************************************************/
#include "ShowLED.h"
#include "74HC595.h"
#include "delay.h"
#include "LinkAll.h"

static u8 gSeat;       //全局变量  LED灯效果 传入参数
static u8 gStep;       //LED灯效果 防止重入 初始为0

const u8 MAX_SEAT = 13 ;                    //LED灯最大位置数
const u8 MIN_SEAT = 1  ;                    //LED灯最小位置数
const u16 DEFAULT_LIGHT_STATE = 0x0311;     //默认灯状态（无关灯熄灭）

//LED灯的位置映射表 最大16个灯  表位置0保留
//顺序灯 匹配的 实际灯位置
//                    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
u8 LedMapTab[17]= {0,11,13,15,10,12,14, 3, 6, 7, 5, 2, 1, 0, 0, 0, 0 };


/*******************************************************************************
**函    数： ShowLED_OpenAll
**功    能： 打开所有灯
**参    数： void
**返    回： void
*******************************************************************************/
void ShowLED_OpenAll(void)
{
    _74HC595_WriteData(DEFAULT_LIGHT_STATE);
}
/*******************************************************************************
**函    数： ShowLED_CloseAll
**功    能： 关闭所有灯
**参    数： void
**返    回： void
*******************************************************************************/
void ShowLED_CloseAll(void)
{
    _74HC595_WriteData(0xffff);
}
/*******************************************************************************
**函    数： ShowLED_CheckDevice
**功    能： 验证设备时的效果
**参    数： void
**返    回： void
*******************************************************************************/
void ShowLED_CheckDevice(void)
{
    static u8 a=0;

    if( (a++)%2 )   ShowLED_OpenAll();  
    else            ShowLED_CloseAll(); 
}
/*******************************************************************************
**函    数： ShowLED_LightON
**功    能： 点亮一个灯
**参    数： keyNum         -- 灯的位置  范围 1--13
**           lightState     -- 默认使用  DEFAULT_LIGHT_STATE    
**返    回： void
**说    明： 
*******************************************************************************/
void ShowLED_LightON(u8 keyNum , u16 lightState)
{
    lightState &= ~(1<<LedMapTab[keyNum]);
    _74HC595_WriteData(lightState);
}  


/*******************************************************************************
**函    数： ShowLED_LightOFF
**功    能： 熄灭一个灯
**参    数： keyNum         -- 灯的位置  范围 1--13
**           lightState     -- 默认使用  DEFAULT_LIGHT_STATE    
**返    回： void
**说    明： 
*******************************************************************************/
void ShowLED_LightOFF(u8 keyNum,u16 lightState)
{
    lightState |= (1<<LedMapTab[keyNum]);
    _74HC595_WriteData(lightState);
}    

/*******************************************************************************
**函    数： ShowLED_CycleLED
**功    能： 玻璃面板灯光圈左右渐灭渐亮效果
**参    数： void
**返    回： void
**说    明： 提供给ShowLED_StartCycleLED()调用
*******************************************************************************/
void ShowLED_CycleLED(void)
{
    static u16 lightState;          //LED灯状态保存  
    static u8  left_seat,right_seat,count;    
    
    if(0 == gStep)                   //灭主灯
    {
        lightState = DEFAULT_LIGHT_STATE;       //默认灯状态
        ShowLED_LightOFF(gSeat,lightState);
        left_seat  = gSeat;
        right_seat = gSeat;
        count = 1;
        gStep = 1;
    }
    else if(1 == gStep)              //左右渐灭效果
    {
        if(left_seat <= MIN_SEAT)   left_seat  = MAX_SEAT;
        else                        left_seat  = left_seat-1;
        if(right_seat >= MAX_SEAT)  right_seat = MIN_SEAT;
        else                        right_seat = right_seat+1;            
        
        lightState |= (1<<LedMapTab[left_seat])|(1<<LedMapTab[right_seat]); 
        _74HC595_WriteData(lightState); 
 
        if( ++count >= 7)    gStep = 2;
    }
    else if(2 == gStep)              //左右渐亮效果
    {
        lightState &= ~((1<<LedMapTab[left_seat])|(1<<LedMapTab[right_seat]));  
        _74HC595_WriteData(lightState); 
        
        if(right_seat <= MIN_SEAT)  right_seat = MAX_SEAT;
        else                        right_seat = right_seat-1;
        if(left_seat >= MAX_SEAT)   left_seat  = MIN_SEAT;
        else                        left_seat  = left_seat+1;
        
        if(--count <= 1)
        {
            gStep = 0;
        }
    }  
}

/*******************************************************************************
**函    数： ShowLED_StartCycleLED
**功    能： 启动灯光圈左右渐灭渐亮效果
**参    数： key   -- 输入按键值
**返    回： void
**说    明： 使用全局变量 gSeat 传入初始值，每隔70ms左右执行一次，执行13次完成
*******************************************************************************/
void ShowLED_StartCycleLED(u8 key)
{
    gStep = 0;
    gSeat = key;
    ShowLED_LightOFF(key,0x700);
    Thread_Login( MANY, 13, 70 , &ShowLED_CycleLED );  
}

/*******************************************************************************
**函    数： ShowLED_NormalLightLED
**功    能： 普通闪烁LED(齐总要求效果)
**参    数： key   -- 输入按键值
**返    回： void
**说    明： 按键触摸时，所有背景灯点亮，松开按键时，对应按键闪烁4下，然后全部熄灭
*******************************************************************************/
void ShowLED_ReverLED(void)
{
    if(++gStep%2) ShowLED_LightON(gSeat,DEFAULT_LIGHT_STATE);
    else      ShowLED_LightOFF(gSeat,DEFAULT_LIGHT_STATE);
}

//static u8 ledstate[17] ={0}; 
void ShowLED_FlashLED(u8 key)
{
    ShowLED_OpenAll(); 
    gStep = 0;
    gSeat = key;
	Thread_Login( MANY, 13, 100 , &ShowLED_ReverLED );  
//	ShowLED_CloseAll();
//	if((++ledstate[key])%2)
//	{
//		ShowLED_LightON(key ,DEFAULT_LIGHT_STATE);
//	}
//	else
//	{
//		ShowLED_LightOFF(key,DEFAULT_LIGHT_STATE);
//	}
}
/********************************* END FILE ***********************************/

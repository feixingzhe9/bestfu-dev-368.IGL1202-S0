/***************************Copyright BestFu ***********************************
**  ��    ����  Key.c
**  ��    �ܣ�  <<�߼���>> �������� 
**  ��    �룺  Keil uVision5 V5.10
**  ��    ����  V1.1
**  ��    д��  Seven
**  �������ڣ�  2014.08.20
**  �޸����ڣ�  2014.08.20
**  ˵    ����  
**  V1.1
    >> �̰���Ϊ�ͷ�ʱ��ִ�У�����ӳ�������Ӧ
*******************************************************************************/
#include "Key.h"
#include "LinkAll.h"
#include "delay.h"
#include "LowPower.h"
#include "WTC6216.h"
#include "USART1.h"
#include "MsgPackage.h"
#include "ShakeMotor.h"
#include "OLED.h"
#include "ShowLED.h"
#include "TouchPadPic.h"
#include "Queue.h"
#include "sys.h"
#include "Program.h"
#include "wdg.h"


/*��������ֵ*/
const u8 NONE_KEY=0xFF;       
//const u8 KEY6    =62;
//const u8 KEY5    =61;
//const u8 KEY4    =59;
//const u8 KEY3    =55;
//const u8 KEY2    =47;
//const u8 KEY1    =31;

/*��������ֵ--�ṩ�����Բ�ʹ��*/
KeyProp_t  KeyCh[MAX_TOUCH_KEY];        //KeyCh[0] ����

static u8  NewKey,OldKey,LstKey;
static u16 LongKeyCount;                //������������
const  u16 LONG_KEY_TIMES = 200;        //����������ʱ�� 200 *5ms = 1S

#define MAX_KEY_NUM 12
//����ӳ��� ���16������   ��λ��0����
//˳�򰴼� ƥ��� ʵ�ʰ���ֵ
//                             1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
const u8  KeyMapTab[17] = {0, 11, 7,15, 3,13, 5, 8, 4,10, 6, 2, 0, 0, 0, 0, 0};
//const u8  KeyMapTab[17] = {0,  1, 2, 3, 4, 5, 6, 8, 8, 9,10,11,12,13,14, 0, 0};

u8 gPassword[4];
u8 gPswFlag=1;
u8 InputPassword[4];
u8 PswBit=0;
Queue_t  gQueue;
static u8 FirstPassWord = 0;   
u8 gWukeUpForPassWord = 0;    
KeySta_t gPrevoiusKeyValue = {0,KEY_NONE};

extern u8 gSleepFlag;
/*******************************************************************************
**��    ���� Key_Init()
**��    �ܣ� ����ģ���ʼ��
**��    ���� void
**��    �أ� void
*******************************************************************************/
void Key_Init(void)
{
    WTC6216_Init();
    NewKey=NONE_KEY;
    OldKey=NONE_KEY;
    LstKey=NONE_KEY;
}
/*******************************************************************************
**��    ���� Key_Scan()
**��    �ܣ� ״̬����ʽɨ������
**��    ���� *keyFlag    ������־    0-�ް���  1-�̰���    2-������ 
**��    �أ� ����ֵ
**˵    ���� �ú��� ÿ�� 5~20ms ����һ��
*******************************************************************************/
u8 Key_Scan(u8 *keyFlag)
{
    u8 i;
    static u8 MidValidKey = NONE_KEY;                               //��Ч�����м䱣��ֵ

    *keyFlag = 0;
    NewKey = WTC6216_ReadKey();
    if(NewKey == OldKey)
    {
        if(NewKey==NONE_KEY)                                        //�ް��� �� �ͷŰ���    
        {   
            if((LstKey != NONE_KEY)&&(LongKeyCount<LONG_KEY_TIMES)) // �ͷŰ��� �� �ǳ�����
            {
                //if(LongKeyCount>2)  //���˳��̰��� �����ȿɵ�
                {
                    LstKey  = NONE_KEY;
                    LongKeyCount = 0;
                    *keyFlag =1;
                    return MidValidKey;                             //���ض̼��ͷ�
                }
            }
            else{                                                   
                LstKey = NONE_KEY;
                LongKeyCount = 0;
                return NONE_KEY;                    
            }
        }
        else if(NewKey==LstKey)                                     //��������
        {
            if(LongKeyCount++ == LONG_KEY_TIMES)
            {
                *keyFlag =2;
                return MidValidKey;                                 //���س���ȷ��
            }
        }
        else{                                                       //����
            LstKey = NewKey;
            for(i=1 ; i<=MAX_KEY_NUM ; i++)
            {
                if( KeyMapTab[i] == NewKey )  
                {
                    MidValidKey = i;
                    break;
                }
            }
            if( i > MAX_KEY_NUM)              MidValidKey = NONE_KEY;
            return NONE_KEY ;         
        }
    }
    else OldKey = NewKey;               //��������
    return NONE_KEY;
}

/*******************************************************************************
**��    ���� Key_FirstHandleScan()
**��    �ܣ� ״̬����ʽɨ������
**��    ���� *keyFlag    ������־    0-�ް���  1-�̰���    2-������ 
**��    �أ� ����ֵ
**˵    ���� �ú��� ÿ�� 5~20ms ����һ��
*******************************************************************************/
u8 Key_FirstHandleScan(u8 *keyFlag)
{
    u8 i;
    static u8 MidValidKey = NONE_KEY;                               //��Ч�����м䱣��ֵ
	*keyFlag = 0;
	NewKey = WTC6216_ReadKey();
    if(NewKey == OldKey)
    {
        if(NewKey==NONE_KEY)                                        //�ް��� �� �ͷŰ���    
        {   
            if(LstKey != NONE_KEY) // �ͷŰ��� 
            {
                if(LongKeyCount>4)  //���˳��̰��� �����ȿɵ�
                {               
                    LstKey  = NONE_KEY;
                    LongKeyCount = 0;
                    *keyFlag = KEY_LONG;
                    return MidValidKey;                             //���ض̼��ͷ�
                }
            }
            else{                                                   
                LstKey = NONE_KEY;
                LongKeyCount = 0;
                return NONE_KEY;                    
            }
        }
        else if(NewKey==LstKey)                                     //��������
        {
            LongKeyCount++ ;
        }
        else{                                                       //����
            LstKey = NewKey;
            for(i=1 ; i<=MAX_KEY_NUM ; i++)
            {
                if( KeyMapTab[i] == NewKey )  
                {
                    MidValidKey = i;
                    break;
                }
            }
            if( i > MAX_KEY_NUM)              MidValidKey = NONE_KEY;
            return NONE_KEY ;         
        }
    }
    else OldKey = NewKey;               //��������
    return NONE_KEY;
}


/*******************************************************************************
**��    ���� Key_Handle()
**��    �ܣ� ��������
**��    ���� void 
**��    �أ� void
**˵    ���� �ú��� ÿ�� 5~20ms ����һ��
*******************************************************************************/
void Key_Handle(void)
{
    u8 i,ch,key_flag;
    static u8 FirstFlag = 1;
    KeySta_t keyTemp;
    u8 res=0x00;
    CPU_SR_ALLOC();
//    TravelQueue(&gQueue);
    cpu_sr = CPU_SR_Save();
    res = Dequeue(&gQueue,&keyTemp);
    CPU_SR_Restore(cpu_sr);
//	ch = Key_Scan(&key_flag);
    if(res)
    {
        if(1 == FirstFlag)   
        {
            FirstFlag = 0;
            StandbyCountReset();
        }
        else
        {
            ch = keyTemp.KeyValue;
            key_flag = keyTemp.KeyType;
            if(gPswFlag)        //���뿪��
            {
                switch(FirstPassWord)
                {
                    case 0:
                    {
                        FirstPassWord = 1;
                        OLED_ClearScreen();
                        OLED_ShowString(2,0,"����������",0);
                        OLED_ShowString(6,2,"----",0);
                    }
                    break;
                    case 1:
                    {
                        if(ch <= 6)      //123456������Ч
                        {
                            StandbyCountReset();
                            if(gWukeUpForPassWord)
                            {
                                OLED_ShowString(1,0,"��������������",0);
                                OLED_ShowString(4,1,"�������",0);
                                OLED_ShowString(6,2,"----",0);
                                gWukeUpForPassWord = 0;
                                PswBit = 0;
                            }
                            OLED_ShowChar(6+PswBit,2,ch+'0',0);
                            InputPassword[PswBit] = ch;
                            if(PswBit++ >= 3)
                            {
                                PswBit=0;
                                if((gPassword[0] == InputPassword[0])&& \
                                   (gPassword[1] == InputPassword[1])&& \
                                   (gPassword[2] == InputPassword[2])&& \
                                   (gPassword[3] == InputPassword[3]) )
                                {
                                    gPswFlag = 0;
                                    gSleepFlag = 0;
                                    OLED_ClearScreen();
//                                    OLED_ShowString(4,1,"��ӭʹ��",0);
									if(KEY_SHORT == gPrevoiusKeyValue.KeyType)
									{
										OLED_ShowHalfPicAt(4,PicTab[gPrevoiusKeyValue.KeyValue]);
									}
									else
									{
										OLED_ShowHalfPicAt(4,PicTab[gPrevoiusKeyValue.KeyValue + 16]);
									}
                                }
                                else 
                                {
                                    OLED_ShowString(1,0,"��������������",0);
                                    OLED_ShowString(4,1,"�������",0);
                                    OLED_ShowString(6,2,"----",0);
                                }
                            }
                        }
                    }
                    break;
                    default:break;
                }
            }
            else if( ch != NONE_KEY)
            {
                /*����ϴ�״̬*/
                for(i=0;i<MAX_TOUCH_KEY;i++)
                {
                    KeyCh[i].Status = KEY_NONE; 
                } 
                gSleepFlag = 0;               
                gPrevoiusKeyValue.KeyType = key_flag;
                gPrevoiusKeyValue.KeyValue= ch;
    //                OLED_ClearScreen();
//                OLED_ShowHalfPicAt(4,PicTab[ch]);
    //                ShowLED_FlashLED(ch);
                StandbyCountReset();
                
                if(KEY_SHORT == key_flag)
                {
					OLED_ShowHalfPicAt(4,PicTab[ch]);                   
					KeyCh[ch].Status = KEY_SHORT; 
                    PropEventFifo(1, ch, SRCEVENT , KEY_SHORT);     //50ms          
                    Upload();                                       //2.5s//�ϱ�
                }
                else if(KEY_LONG == key_flag)
                {
                    OLED_ShowHalfPicAt(4,PicTab[ch + 16]);
					KeyCh[ch].Status = KEY_LONG;    
                    PropEventFifo(1, ch, SRCEVENT , KEY_LONG);        
                    Upload();                                       //�ϱ�
                }               
                #if KEY_SUPPORT_PRINTF
                printf("New Key = %d ,flag = %d \r\n",ch,key_flag);
                #endif
            }
        }
    }
}

/*******************************************************************************
**��    ��:  Key_FirstScan()
**��    ��:  ��������ɨ��
**��    ��:  void
**��    ��:  �״���Ч����ֵ 
*******************************************************************************/
u8 Key_FirstScan(void)
{
    u8 i;
    u8 first_key = NONE_KEY;
    u8 temp_key  = NONE_KEY;
    
    first_key = WTC6216_ReadKey();
    delay_us(200);
    if(first_key == WTC6216_ReadKey())
    {
        for(i=1 ; i<=MAX_KEY_NUM ; i++)
        {
            if( KeyMapTab[i] == first_key )  
            {
                temp_key = i;
                break;
            }
        }
        if( i > MAX_KEY_NUM)              temp_key = NONE_KEY;           
    }
    return temp_key;
}

/*******************************************************************************
**��    ��:  Key_FirstHandle()
**��    ��:  �״ΰ���������
**��    ��:  ����ֵ
**��    ��:  void
********************************************************************************/
#if 0
void Key_FirstHandle(u8 Key)
{
    if(gPswFlag)
    {
        OLED_ShowString(2,0,"����������",0);
        OLED_ShowString(6,2,"----",0);
    }
    else if( Key != NONE_KEY)
    {         
        //OLED_ClearScreen();
//        ShowLED_FlashLED(Key);           //��ͨ����Ч�� 
        ShowLED_OpenAll(); 
        OLED_ShowHalfPicAt(4,PicTab[Key]);
        KeyCh[Key].Status = KEY_SHORT; 
        PropEventFifo(1, Key, SRCEVENT , KEY_SHORT);
        Upload();   
    }
}
#endif
/*******************************************************************************
**��    ��:  void Save_CurrentKeyState(void)
**��    ��:  ���浱ǰ�İ���״̬
**��    ��:  ��
**��    ��:  void
********************************************************************************/
void Save_CurrentKeyState(void)       
{
    WriteDataToEEPROM(ADDR_KEY_CURRENT_STATE,sizeof(KeySta_t),(u8*)&gPrevoiusKeyValue);
}

/*******************************************************************************
**��    ��:  static void Get_CurrentKeyState(u8 *)
**��    ��:  ��ȡ�浱ǰ�İ���״̬
**��    ��:  ��
**��    ��:  void
********************************************************************************/
void Get_CurrentKeyState(KeySta_t * pKeyState)
{
    ReadDataFromEEPROM(ADDR_KEY_CURRENT_STATE,sizeof(KeySta_t),(u8*)pKeyState);
}

/*******************************************************************************
**��    ��:  u8 UserFlashDataCpy(u32 des_addr,u32 src_addr, u32 len)
**��    ��:  Flash�ڴ濽������
**��    ��:  des_addr:Ŀ���ַ;src_addr��Դ��ַ��len:��������
**��    ��:  TRUE/FALSE
********************************************************************************/
u8 UserFlashDataCpy(u32 des_addr,u32 src_addr, u32 len)
{
	u8 status = FALSE;
	u8 pic_temp[256] = {0};
	if(des_addr != src_addr)
	{
		StandbyCountReset();
		status = Program_Erase(des_addr,len);  
		if(TRUE == status)
		{
			while(len > 0)
			{
				Program_Read(src_addr,256,(u8*)pic_temp);
				status = Program_Write(des_addr,256,(u8*)pic_temp);
				if(TRUE != status)
				{
					break;
				}
				des_addr += 256;
				src_addr += 256;
				len -= 256;
				WDG_Feed();
			}
		}
	}
	return status;
}
/***************************Copyright BestFu **********************************/

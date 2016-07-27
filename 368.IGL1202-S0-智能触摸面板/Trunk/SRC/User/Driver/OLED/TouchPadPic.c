
#include "TouchPadPic.h"

const u8  PIC_NUM               = 12;                 //图片数量
const u16 PIC_SIZE              = 0x0200;             //512字节  每张图片占用空间大小
const u32 PIC_TAB_START_ADDR    = 0x08019000;         //100K 图片存储首地址
const u32 PIC_TAB_END_ADDR      = PIC_TAB_START_ADDR+PIC_SIZE*PIC_NUM; //100K 图片存储尾地址

//const 
const u32 *PicTab[49] =
{
    (const u32*)0,                                          //保留
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 0  ),      //图片1地址
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 1  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 2  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 3  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 4  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 5  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 6  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 7  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 8  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 9  ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 10 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 11 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 12 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 13 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 14 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 15 ),   	//16

    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 16 ),		//17
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 17 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 18 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 19 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 20 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 21 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 22 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 23 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 24 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 25 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 26 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 27 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 28 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 29 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 30 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 31 ),

    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 32 ),		//33
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 33 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 34 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 35 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 36 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 37 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 38 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 39 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 40 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 41 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 42 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 43 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 44 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 45 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 46 ),
    (const u32*)(PIC_TAB_START_ADDR + PIC_SIZE * 47 )	
};

//电池电量图标
//图片大小 23*16   占用空间 42字节
const u8 PicTab_Bat[] =
{
    0x00,0xFE,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0xFE,0xF8,0x70,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\电池00.bmp",0*/
    
    0x00,0xFE,0x02,0xFA,0xFA,0xFA,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0xFE,0xF8,0x70,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\电池01.bmp",0*/

    0x00,0xFE,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0xFE,0xF8,0x70,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\电池02.bmp",0*/

    0x00,0xFE,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0x02,
    0x02,0x02,0x02,0xFE,0xF8,0x70,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\电池03.bmp",0*/

    0x00,0xFE,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0xFA,
    0xFA,0xFA,0x02,0xFE,0xF8,0x70,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\电池04.bmp",0*/

    
    0x00,0x00,0x30,0x38,0xFC,0xE6,0x60,0x00,0x00,0x00,0x00,0x03,0x01,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\电池\充电符号.bmp",0*//*"C:\Users\admin\Desktop\电池\充电符号.bmp",0*/

};

const u8 PicPower[]={
/*--  调入了一幅图像：C:\Users\BestFu\Desktop\Power3.bmp  --*/
/*--  宽度x高度=56x32  --*/
0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
0x30,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0xFF,
0xFF,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFC,
0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCF,0xCF,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x1F,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x19,
0x19,0x19,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,
};

#if 0       //IGL1202-S0图片
const u8 ALL_PIC_S2[] __attribute__((at(0x08019000))) =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0x00,0xC0,0xC0,0x00,0xC0,0xC0,0x00,0xC0,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x1E,0x1F,0xFF,0xFE,0xFF,0x1F,0x1E,0x1F,0x07,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x9F,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x19,0xFF,0xFF,0xFF,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xC0,0x40,0x47,0x07,0x47,0xC0,0x40,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x07,0x07,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x00,0x00,0xFF,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xFF,0x00,0x00,0x00,0x48,0x4A,0x2B,0xE5,0xB5,0xAB,0xB5,0xA8,0xB4,0xE2,0x21,0x42,0x44,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x08,0x06,0x01,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x08,0x08,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0A,0x02,0x02,0x06,0x06,0x0B,0x0C,0x0A,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\13.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x80,0xF0,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC1,0xC3,0xC7,0xDE,0xD8,0xF0,0xFC,0xDF,0xC3,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0xFF,0xFF,0x23,0x23,0x23,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xE2,0xE2,0xE2,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x3F,0xFF,0xBF,0xBE,0xFC,0xFC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,
0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1E,0xFF,0xFF,0xBF,0xBF,0xFF,0x3F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0x40,0x40,0x40,0x40,0x40,0xC0,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x10,0xD7,0x55,0x55,0x5D,0x55,0x55,0xD7,0x10,0x42,0x21,0x10,0x8C,0x00,0x00,0x00,0x42,0x22,0xFA,0x16,0x20,0x7F,0x00,0x80,0x7E,0x80,0x00,0x7F,0x00,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x08,0x05,0x01,0x09,0x0F,0x01,0x01,0x05,0x08,0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x08,0x04,0x02,0x01,0x00,0x07,0x08,0x08,0x0E,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\12.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x7F,0xC1,0xC0,0x80,0xC0,0xC0,0x7C,0x7C,0xC0,0xC0,0x80,0xC0,0xC0,0x7C,
0x7C,0xC0,0xC0,0x80,0xC0,0xC0,0x7C,0x7C,0xC0,0xC0,0x80,0xC0,0xC1,0x7F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0xE0,0x70,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x70,0xE0,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x1E,0x3F,0x7F,0x7F,0x1E,0x1E,0x1E,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x07,0x1E,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0x1E,0x07,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x7F,0x7F,0x3F,0x1E,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x80,0x80,0x80,0xC0,0xC0,0x60,0x3F,0x1F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x3F,0x60,0xC0,0xC0,0x80,0x80,0x80,0xC0,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0xA0,0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,
0xA0,0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x20,0x20,0xE0,0x20,0x20,0x20,0x20,0x20,0xE0,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF8,0x0A,0x49,0x2C,0x7A,0xA8,0xA8,0x68,0x29,0x0A,0xF8,0x01,0x00,0x00,0x00,0x00,0x03,0x00,0xF4,0x12,0x11,
0x10,0xFE,0x10,0x11,0x12,0xF4,0x00,0x03,0x00,0x00,0x00,0x08,0x08,0x88,0x7F,0x08,0x08,0x08,0x08,0x08,0xFF,0x08,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x05,0x05,0x05,0x04,0x04,0x05,0x04,0x04,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,
0x00,0x07,0x00,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\03.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x03,0x87,0x8F,0x8F,0x8F,0x87,0x83,0x80,0xFC,0xFC,0xFC,0x00,0x00,0xFC,
0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x70,0x70,0x70,0x70,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x70,0x70,0x71,
0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x70,0x70,0x70,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x10,0x08,0xFE,0x01,0x00,0x82,0x62,0x1A,0xFF,0x1A,0x62,0x82,0x02,0x00,0x00,0x00,0x00,0x00,0x7F,0x55,0x55,0x55,0xD5,0x55,0x55,0x55,0x7F,0x00,0x00,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x00,0x00,0x0F,0x00,0x01,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x08,0x06,0x00,0x07,0x08,0x08,0x08,0x0B,0x08,0x0C,0x00,0x01,0x06,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\10.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xEC,0xCE,0x03,0x01,0x00,0x00,0x00,
0x00,0xF0,0xF8,0xF8,0xF8,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFF,0xFE,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x60,0x70,0xF9,0xFB,0xFB,0xF1,0x70,0xE0,0xC0,0x80,0x00,
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF0,0x70,0x38,0x38,0x38,0x1F,0x1F,0xFF,0xFF,0xFF,0x00,0x08,0x1F,0x0F,0x00,
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x0F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0x00,0x00,0xC0,0xC0,0xC0,
0xC0,0xC7,0xCF,0xCF,0xCF,0xCF,0xCF,0xDF,0xDF,0xDF,0xDF,0xDF,0xFF,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0xC0,0x40,0x40,0x40,0x40,0x40,0xC0,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x01,0x81,0xBD,0xA1,0xB5,0xA9,0xE9,0xA9,0xB5,0xA1,0xBD,0x81,0x01,0x00,0x00,0x00,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x00,0x0F,0x00,0x02,0x03,0x02,0x02,0x02,0x03,0x0A,0x08,0x0F,0x00,0x00,0x00,0x00,0x08,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\09.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x7F,0xC1,0xC0,0x80,0xC0,0xC0,0x7C,0x7C,0xC0,0xC0,0x80,0xC0,0xC0,0x7C,
0x7C,0xC0,0xC0,0x80,0xC0,0xC0,0x7C,0x7C,0xC0,0xC0,0x80,0xC0,0xC1,0x7F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0xE0,0x70,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x70,0xE0,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x7F,0x7F,0x3F,0x1E,0x0C,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x07,0x1E,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0x1E,0x07,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x0C,0x1E,0x3F,0x7F,0x7F,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x80,0x80,0x80,0xC0,0xC0,0x60,0x3F,0x1F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x3F,0x60,0xC0,0xC0,0x80,0x80,0x80,0xC0,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0xA0,0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0xA0,
0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xC0,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF8,0x0A,0x49,0x2C,0x7A,0xA8,0xA8,0x68,0x29,0x0A,0xF8,0x01,0x00,0x00,0x00,0x00,0x03,0x00,0xF4,0x12,0x11,0x10,
0xFE,0x10,0x11,0x12,0xF4,0x00,0x03,0x00,0x00,0x00,0x10,0x11,0x11,0x11,0x91,0x71,0x1F,0x71,0x91,0x11,0x11,0x11,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x05,0x05,0x05,0x04,0x04,0x05,0x04,0x04,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
0x07,0x00,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\04.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x60,0x20,0x20,0x30,0x30,0x30,
0x30,0x30,0x30,0x30,0x20,0x20,0x60,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0x1E,0x07,0x01,0x00,0x00,0x00,0x01,0xC7,0xFE,0xFC,0xDC,
0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x01,0x07,0x1E,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x3F,0xF0,0xC0,0x00,0x00,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xF8,0x01,0x0F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0xC0,0xF0,0x3F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x7C,0xF0,0x01,0x07,0x0F,0x1F,0x1F,0x3F,
0xBF,0xFF,0x00,0x10,0x1F,0x07,0x03,0xF0,0x7C,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x76,0x74,0x74,0x74,0x74,0x76,
0x77,0x74,0x74,0x74,0x74,0x74,0x76,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x0F,0x0F,
0x0F,0x0F,0x0F,0x07,0x43,0x43,0xC0,0x40,0x40,0x40,0x40,0x40,0xC0,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x08,0x94,0x92,0x91,0xF0,0x91,0x92,0x94,0x08,0x10,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\03\01.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x60,0x30,0xB0,0x98,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x30,0x30,0x60,0xE0,0xC0,0x80,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFE,0x0F,0x03,0x01,0x00,0x00,0x00,0x81,0xE3,0xFF,0xFE,0xFE,0x9C,
0x38,0xF0,0xE0,0x40,0x80,0xC0,0x60,0x30,0x19,0x0C,0xC6,0xFB,0xF1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x3F,0xF8,0xE0,0x80,0x00,0x00,0xFC,0xFF,0x7F,0xBF,0xDF,0x6F,0xB7,
0xD8,0xEC,0xF6,0xFB,0xFD,0xFE,0x00,0x00,0xC0,0xF8,0x7F,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC1,0x6F,0x36,0xD8,0xEC,0x06,0x0B,0x1D,0x3E,0xFF,0xFF,
0x7F,0x3F,0x1F,0x0F,0x03,0xE1,0xFC,0x3F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x3B,0x3B,0xBA,0xBA,0xBA,0xBA,0xBB,0xBB,
0xBA,0xBA,0xBA,0xBA,0xBA,0x3B,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x07,
0x07,0x07,0x07,0x03,0x01,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x08,0x94,0x92,0x91,0xF0,0x91,0x92,0x94,0x08,0x10,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x20,0x22,0x22,0x22,0x23,0xE2,0x3E,0xE2,0x23,0x22,0x22,0x22,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x01,0x02,0x04,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\03\02.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xF0,0xF8,0xF8,0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x03,0x03,
0x03,0x03,0x06,0x06,0x8C,0x9C,0xD8,0x70,0x60,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x0F,0x07,0x07,0x0F,0x0C,0x18,0x38,
0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,0x00,0x00,0xFC,0xFE,0x0E,0x0E,0x0E,0x06,0x07,0x07,0x07,0x07,0x07,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x7F,0xFF,0xFF,0x3F,0x1F,0x1F,0x0F,0x07,0x07,0x03,0x03,0x07,0x1E,0x18,0x30,0x30,0xE0,0xE0,0xF0,0xF0,0x38,0x1C,
0x0F,0xC7,0xC7,0xE3,0xE3,0xE3,0xE0,0xE0,0xFF,0x3F,0x00,0x00,0x60,0xF0,0xF8,0xF8,0xF8,0xF0,0xF0,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0x60,0xE0,0xC0,0xC0,0xC0,0x80,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,
0xF8,0xF8,0xF1,0x71,0x73,0x33,0x33,0x11,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x40,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x81,0x81,0x81,0x41,0x41,0x41,0x01,0x01,0x01,0x01,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x22,0x5E,0x83,0x62,0x1E,0x80,0x93,0x92,0xF2,0x92,0x92,0x93,0x80,0x00,0x00,0x00,0x00,0x1C,0x93,0x10,0x10,0x10,0xFE,0x10,0x10,0x90,0x10,0x10,0x10,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x04,0x03,0x00,0x01,0x0A,0x04,0x02,0x01,0x00,0x01,0x02,0x04,0x08,0x00,0x00,0x00,0x04,0x02,0x01,0x00,0x08,0x08,0x0F,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\11.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x00,0x00,0x00,0x80,0xC0,0xC0,0x00,
0x00,0x00,0x80,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x7F,0xF1,0xC0,0x00,0x00,0x1E,0x7F,0xF1,0xC0,0x00,
0x00,0x1E,0x7F,0xF1,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xE4,0xE6,0xE7,0xE1,0xE0,0xE0,0xE4,0xE6,0xE7,0xE1,0xE0,
0xE0,0xE4,0xE6,0xE7,0xE1,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x07,0x07,0x0E,0x1E,0xFC,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x70,0x30,0x38,0x3C,0x1E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0xC3,0x03,0x03,0x03,0x03,0x03,0xC3,0x03,0x03,0x03,0x03,
0x03,0x03,0x03,0x03,0xC3,0x03,0x01,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0xC0,0x40,0x4F,0x48,0x48,0xC8,0x08,0xC8,0x48,0x48,0x4F,0x40,0xC0,0x00,0x00,0x00,0x00,0x21,0x21,0x51,0x53,0x49,0x45,0xF3,0x45,0x49,0x53,0x51,0x21,0x21,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x0F,0x04,0x04,0x04,0x04,0x0F,0x00,0x0F,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x01,0x08,0x08,0x0F,0x00,0x00,0x01,0x02,0x04,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\05\06.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0xB8,0xB8,0xB8,0xB8,0xB8,0xB8,0xF8,0xF8,0x00,0x00,0xF8,0xF8,0xB8,0xB8,0xB8,0xB8,0xB8,0xB8,0xF8,
0xF8,0xC0,0xE0,0xF0,0xF0,0x78,0x38,0xBC,0x9E,0xDE,0x7C,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xFF,
0xFF,0x00,0x01,0x07,0x1E,0x3E,0xF3,0xF1,0xF9,0xF8,0xFC,0xFE,0xFF,0xFF,0xFC,0xF8,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xCF,0xCF,0xCF,0xCF,0xCF,0xCF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xCF,0xCF,0xCF,0xCF,0xCF,0xCF,0xFF,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1F,0x7F,0xF7,0xE3,0x71,0x71,0x38,0x3C,0x1F,0x1F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x80,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x81,0x81,0x01,0x01,0x01,0x01,0x41,0x81,0x01,0x00,0x00,0x01,0x01,0xC1,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x00,0xFE,0x00,0x00,0x7A,0xCC,0x48,0x48,0xCC,0x7A,0x00,0x00,0xFF,0x00,0x00,0x00,0x08,0x08,0xF9,0x00,0x84,0xA5,0xCD,0x95,0x87,0xF5,0x85,0x95,0x8C,0x00,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x00,0x0F,0x00,0x04,0x02,0x01,0x00,0x00,0x03,0x04,0x06,0x08,0x0F,0x00,0x00,0x00,0x00,0x00,0x07,0x02,0x00,0x08,0x04,0x02,0x01,0x00,0x02,0x0C,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\02.bmp",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,
0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC7,0xCF,0xFF,0xFF,
0xFF,0xCF,0xC7,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x0F,0x0F,0x0F,0xEF,0xEF,
0xEF,0x0F,0x0F,0x0F,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xF0,0xF0,0xF0,0xE0,0xCE,0x0E,0x0E,0x00,0x0E,0x0E,0x0E,0x00,
0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0xCE,0xE0,0xF0,0xF0,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xF0,0xF1,0xF3,0xFF,0xFF,0xFF,0xF3,0xF1,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xC0,0xE0,0xF0,0xF1,0xF3,0xFF,0xFF,0xFF,0xF3,0xF1,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x43,0x83,0x03,0x01,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xC1,0x03,0x03,0x03,0xC3,0x03,0x03,0x03,0xC3,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x80,0x00,0x00,
0x00,0x08,0x48,0x44,0x4A,0x49,0xC8,0x48,0x48,0x49,0x4A,0x44,0x48,0x08,0x00,0x00,0x00,0x00,0x43,0x49,0xC9,0xA5,0xAF,0x95,0x95,0x95,0xAD,0xAD,0xC5,0x41,0x43,0x00,
0x00,0x00,0x42,0x32,0xFF,0x12,0x20,0x7D,0x57,0x55,0xD5,0x55,0x57,0x7D,0x01,0x00,0x00,0x00,0x02,0x12,0x12,0xF2,0x12,0x12,0x02,0x02,0x7F,0x82,0x02,0x02,0x02,0x00,
0x00,0x00,0x00,0x04,0x06,0x05,0x04,0x04,0x04,0x05,0x06,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x09,0x09,0x05,0x03,0x01,0x03,0x05,0x09,0x09,0x00,0x00,0x00,0x04,0x04,0x04,0x07,0x02,0x02,0x02,0x00,0x00,0x01,0x02,0x04,0x0F,0x00,/*"C:\Users\admin\Desktop\OA接收文件\玻璃面板图片\02\01.bmp",0*/
};
#endif

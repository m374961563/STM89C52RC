#include <REGX52.H>

sbit RCK=P3^5;//并口输出
sbit SCK=P3^6;//移位
sbit SER=P3^4;//数据输入

/**
  * @brief  74HC595写入一个字节
  * @param  Byte 要写入的字节
  * @retval 无
  */
void _74HC595_WByre(unsigned char Byte)  //先送高位再送低位
{
	unsigned char i;
	//串口输入
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	//并口输出
	RCK=1;
	RCK=0;
}
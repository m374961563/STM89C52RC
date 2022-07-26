#include <REGX52.H>
#include "Delay.h"

//数码管显示缓存区第零位是占位置用的
unsigned char Nixie_Buf[9]={0,10,10,10,10,10,10,10,10};

//数码管段码表{0,1,2,3,4,5,6,7,8,9,不显示,-}
unsigned char Nixie_Table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};

/**
  * @brief  设置显示缓存区
  * @param  Location 要设置的位置，范围：1~8
  * @param  Number 要设置的数字，范围：段码表索引范围
  * @retval 无
  */
void Nixie_SetBuf(unsigned char Location,Number)
{
	Nixie_Buf[Location]=Number;
}

/**
  * @brief  数码管扫描显示
  * @param  Location 要显示的位置，范围：1~8
  * @param  Number 要显示的数字，范围：段码表索引范围
  * @retval 无
  */
void Nixie_Scan(unsigned char Location,Number)
{
	P0=0x00;//段码清0，消影
	switch(Location)//位码选择
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=Nixie_Table[Number];//段码选择
}

/**
  * @brief  数码管驱动函数，在中断中调用
  * @param  无
  * @retval 无
  */
void Nixie_Loop()
{
	static unsigned char i=1;//定义静态变量
	Nixie_Scan(i,Nixie_Buf[i]);
	i++;
	if(i>=9){i=1;}
}









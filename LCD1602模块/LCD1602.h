#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init();//LCD1602初始化函数
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char);//在LCD1602指定位置上显示一个字符
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String);//在LCD1602指定位置开始显示所给字符串
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);//在LCD1602指定位置开始显示所给数字
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);//在LCD1602指定位置开始以有符号十进制显示所给数字
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);//在LCD1602指定位置开始以十六进制显示所给数字
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);//在LCD1602指定位置开始以二进制显示所给数字


#endif

#ifndef __DS1302_H__
#define __DS1302_H__

//外部可调用时间数组，索引0~6分别为年、月、日、时、分、秒、星期，设置为有符号的便于<0的判断
extern char DS1302_Time[];

void DS1302_Init(void);
void DS1302_WByte(unsigned char Command,Data);
unsigned char DS1302_RByte(unsigned char Command);
void DS1302_STime(void);
void DS1302_RTime(void);
void TimeShow();//时间显示功能

#endif

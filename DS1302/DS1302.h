#ifndef __DS1302_H__
#define __DS1302_H__

//�ⲿ�ɵ���ʱ�����飬����0~6�ֱ�Ϊ�ꡢ�¡��ա�ʱ���֡��롢���ڣ�����Ϊ�з��ŵı���<0���ж�
extern char DS1302_Time[];

void DS1302_Init(void);
void DS1302_WByte(unsigned char Command,Data);
unsigned char DS1302_RByte(unsigned char Command);
void DS1302_STime(void);
void DS1302_RTime(void);
void TimeShow();//ʱ����ʾ����

#endif

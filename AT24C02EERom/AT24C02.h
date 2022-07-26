#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_WByte(unsigned char WordAddress,Data);//向AT24C02写入一个字节
unsigned char AT24C02_RByte(unsigned char WordAddress);//向AT24C02读取一个字节

#endif
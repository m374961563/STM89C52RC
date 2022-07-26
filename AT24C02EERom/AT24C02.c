#include <REGX52.H>
#include "IIC.h"

#define AT24C02_ADDRESS 0xA0 //AT24C02固定地址为1010，可配置地址为三位，最后一位写入为0，读取为1.

/**
    *  @brief   向AT24C02写入一个字节
    *  @param   WordAddress 要写入字节的地址
    *  @param   Data要写入的数据
    *  @retval  无
    */
void AT24C02_WByte(unsigned char WordAddress,Data)
{
    IIC_Start();
    IIC_WByte(AT24C02_ADDRESS);
    IIC_RAck();
    IIC_WByte(WordAddress);
    IIC_RAck();
    IIC_WByte(Data);
    IIC_RAck();
    IIC_Stop();
}
    
/**
    *  @brief   向AT24C02读取一个字节
    *  @param   WordAddress 要读出字节的地址
    *  @retval  读出数据
    */
unsigned char AT24C02_RByte(unsigned char WordAddress)
{
    unsigned char Data;
    IIC_Start();
    IIC_WByte(AT24C02_ADDRESS);
    IIC_RAck();
    IIC_WByte(WordAddress);
    IIC_RAck();
    IIC_Start();
    IIC_WByte(AT24C02_ADDRESS|0x01);//转化读取地址
    IIC_RAck();
    Data=IIC_RByte();
    IIC_SAck(1);
    IIC_Stop();
    return Data;
}


















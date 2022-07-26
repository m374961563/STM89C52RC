#include <REGX52.H>
#include "IIC.h"

#define AT24C02_ADDRESS 0xA0 //AT24C02�̶���ַΪ1010�������õ�ַΪ��λ�����һλд��Ϊ0����ȡΪ1.

/**
    *  @brief   ��AT24C02д��һ���ֽ�
    *  @param   WordAddress Ҫд���ֽڵĵ�ַ
    *  @param   DataҪд�������
    *  @retval  ��
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
    *  @brief   ��AT24C02��ȡһ���ֽ�
    *  @param   WordAddress Ҫ�����ֽڵĵ�ַ
    *  @retval  ��������
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
    IIC_WByte(AT24C02_ADDRESS|0x01);//ת����ȡ��ַ
    IIC_RAck();
    Data=IIC_RByte();
    IIC_SAck(1);
    IIC_Stop();
    return Data;
}


















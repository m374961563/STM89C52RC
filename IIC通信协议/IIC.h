#ifndef __IIC_H__
#define __IIC_H__

void IIC_Start();//IIC��ʼ
void IIC_Stop();//IICֹͣ
void IIC_WByte(unsigned char Byte);//IIC����һ���ֽ�
unsigned char IIC_RByte();//IIC����һ���ֽ�
void IIC_SAck(unsigned char AckBit);//IIC����Ӧ��
unsigned char IIC_RAck();//IIC����Ӧ��

#endif









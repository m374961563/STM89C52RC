#ifndef __IIC_H__
#define __IIC_H__

void IIC_Start();//IIC开始
void IIC_Stop();//IIC停止
void IIC_WByte(unsigned char Byte);//IIC发送一个字节
unsigned char IIC_RByte();//IIC接收一个字节
void IIC_SAck(unsigned char AckBit);//IIC发送应答
unsigned char IIC_RAck();//IIC接收应答

#endif









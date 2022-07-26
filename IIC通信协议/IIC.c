#include <REGX52.H>

sbit IIC_SCL=P2^1;//定义时钟引脚
sbit IIC_SDA=P2^0;//定义数据引脚

/**
    *  @brief   IIC开始
    *  @param   无
    *  @retval  无
    */
void IIC_Start()
{
    IIC_SDA=1;
    IIC_SCL=1;
    IIC_SDA=0;
    IIC_SCL=0;
}

/**
    *  @brief   IIC停止
    *  @param   无
    *  @retval  无
    */
void IIC_Stop()
{
    IIC_SDA=0;
    IIC_SCL=1;
    IIC_SDA=1;
}

/**
    *  @brief   IIC发送一个字节
    *  @param   Byte要发的字节
    *  @retval  无
    */
void IIC_WByte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        IIC_SDA=Byte&(0x80>>i);//先发高位
        IIC_SCL=1;
        IIC_SCL=0;
    }
}

/**
    *  @brief   IIC接收一个字节
    *  @param   无
    *  @retval  接收到的一个字节
    */
unsigned char IIC_RByte()
{
    unsigned char i,Byte=0x00;
    IIC_SDA=1;//主机在接收之前，需要释放SDA
    for(i=0;i<8;i++)
    {
        IIC_SCL=1;
        if(IIC_SDA){Byte|=(0x80>>i);}
        IIC_SCL=0;
    }
    return Byte;
}

/**
    *  @brief   IIC发送应答
    *  @param   AckBit应答位，0为应答，1为非应答
    *  @retval  无
    */
void IIC_SAck(unsigned char AckBit)
{
    IIC_SDA=AckBit;
    IIC_SCL=1;
    IIC_SCL=0;
}

/**
    *  @brief   IIC接收应答
    *  @param   无
    *  @retval  接收到的应答位，0为应答，1为非应答
    */
unsigned char IIC_RAck()
{
    unsigned char AckBit;
    IIC_SDA=1;
    IIC_SCL=1;
    AckBit=IIC_SDA;
    IIC_SCL=0;
    return AckBit;
}

























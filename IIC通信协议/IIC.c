#include <REGX52.H>

sbit IIC_SCL=P2^1;//����ʱ������
sbit IIC_SDA=P2^0;//������������

/**
    *  @brief   IIC��ʼ
    *  @param   ��
    *  @retval  ��
    */
void IIC_Start()
{
    IIC_SDA=1;
    IIC_SCL=1;
    IIC_SDA=0;
    IIC_SCL=0;
}

/**
    *  @brief   IICֹͣ
    *  @param   ��
    *  @retval  ��
    */
void IIC_Stop()
{
    IIC_SDA=0;
    IIC_SCL=1;
    IIC_SDA=1;
}

/**
    *  @brief   IIC����һ���ֽ�
    *  @param   ByteҪ�����ֽ�
    *  @retval  ��
    */
void IIC_WByte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        IIC_SDA=Byte&(0x80>>i);//�ȷ���λ
        IIC_SCL=1;
        IIC_SCL=0;
    }
}

/**
    *  @brief   IIC����һ���ֽ�
    *  @param   ��
    *  @retval  ���յ���һ���ֽ�
    */
unsigned char IIC_RByte()
{
    unsigned char i,Byte=0x00;
    IIC_SDA=1;//�����ڽ���֮ǰ����Ҫ�ͷ�SDA
    for(i=0;i<8;i++)
    {
        IIC_SCL=1;
        if(IIC_SDA){Byte|=(0x80>>i);}
        IIC_SCL=0;
    }
    return Byte;
}

/**
    *  @brief   IIC����Ӧ��
    *  @param   AckBitӦ��λ��0ΪӦ��1Ϊ��Ӧ��
    *  @retval  ��
    */
void IIC_SAck(unsigned char AckBit)
{
    IIC_SDA=AckBit;
    IIC_SCL=1;
    IIC_SCL=0;
}

/**
    *  @brief   IIC����Ӧ��
    *  @param   ��
    *  @retval  ���յ���Ӧ��λ��0ΪӦ��1Ϊ��Ӧ��
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

























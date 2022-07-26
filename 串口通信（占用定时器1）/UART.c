#include <REGX52.H>

/**
  * @brief  串口初始化，4800bps@11.0592MHz
  * @param  无
  * @retval 无
  */
void UART_Init()//4800bps@11.0592MHz
{
    SCON=0x50;//配置串行控制寄存器
    PCON &=0x7F;//波特率不倍速
    TMOD &=0x0F;//清除定时器1模式位
    TMOD |= 0x20;//设定定时器1为8位自动重装方式
    TL1=0xFA;//设定定时初值
    TH1=0xFA;//设定定时器重装值
    ET1= 0;//禁止定时器1中断
    TR1=1;//启动定时器1
    EA=1;
	ES=1;
}

/**
    *  @brief   串口发送一个字节数据
    *  @param   Byte 要发送的一个字节数据
    *  @retval  无
    */
void UART_SendByte(unsigned char Byte)
{
    SBUF=Byte;
    while(TI==0);
    TI=0;
}

/*串口中断函数模板
void UART_Routine() interrupt 4
{
    if(RI==1)//如果接收标志位为1，接收到了数据
    {
        **=SBUF;//读取数据
        RI=0;
    }
}
*/
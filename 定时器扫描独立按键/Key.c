#include <REGX52.H>

#define K_S1 0x01
#define K_S2 0x02
#define K_S3 0x04
#define K_S4 0x08

sbit K1=P3^1;//K1引脚
sbit K2=P3^0;//K2引脚
sbit K3=P3^2;//K3引脚
sbit K4=P3^3;//K4引脚

//键码保存
unsigned char Get_Key_NumBer;

/**
  * @brief  按键驱动函数，在中断中调用,一般10ms调用一次。
  * @param  无
  * @retval 无
  */
static unsigned char NowKey,LastKey;//按键状态
void Key_Loop()
{
    unsigned char Key_Number=0;
    //扫描按键
    if(!K1){Key_Number|=K_S1;}
    if(!K2){Key_Number|=K_S2;}
    if(!K3){Key_Number|=K_S3;}
    if(!K4){Key_Number|=K_S4;}
    //消抖及松手检测
    LastKey=NowKey;
    NowKey=Key_Number;//获取当前按键状态
    //当按键按下时间超过10ms,并且松手才输出按键键码
    if(LastKey>0&&NowKey==0)
    {
        LastKey=Get_Key_NumBer;
    }
}






























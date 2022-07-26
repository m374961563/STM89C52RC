#include <REGX52.H>

#define MK_S1    0x01
#define MK_S2    0x02
#define MK_S3    0x04
#define MK_S4    0x08
#define MK_S5    0x10
#define MK_S6    0x20
#define MK_S7    0x40
#define MK_S8    0x80
#define MK_S9    0x100
#define MK_S10   0x200
#define MK_S11   0x400
#define MK_S12   0x800
#define MK_S13   0x1000
#define MK_S14   0x2000
#define MK_S15   0x4000
#define MK_S16   0x8000

//键码保存
unsigned int Get_MatrixKey_Number;

sbit Hang1=P1^7;//定义P1^7为第1行
sbit Hang2=P1^6;//定义P1^6为第2行
sbit Hang3=P1^5;//定义P1^5为第3行
sbit Hang4=P1^4;//定义P1^4为第4行
sbit lie1=P1^3;//定义P1^3为第1列
sbit lie2=P1^2;//定义P1^3为第2列
sbit lie3=P1^1;//定义P1^3为第3列
sbit lie4=P1^0;//定义P1^3为第4列

/**
  * @brief  矩阵按键驱动函数，在中断中调用,一般10ms调用一次。
  * @param  无
  * @retval 无
  */
static unsigned char NowMKey,LastMKey;//按键状态
void MatrixKey_Loop()
{
	unsigned int MatrixKey_Number=0;
    //扫描按键
	//扫描第一行
	P1=0xff;
	Hang1=0;
	if(lie1==0){MatrixKey_Number|=MK_S1;}
	if(lie2==0){MatrixKey_Number|=MK_S2;}
	if(lie3==0){MatrixKey_Number|=MK_S3;}
	if(lie4==0){MatrixKey_Number|=MK_S4;}
	//扫描第二行
	P1=0xff;
	Hang2=0;
	if(lie1==0){MatrixKey_Number|=MK_S5;}
	if(lie2==0){MatrixKey_Number|=MK_S6;}
	if(lie3==0){MatrixKey_Number|=MK_S7;}
	if(lie4==0){MatrixKey_Number|=MK_S8;}
	//扫描第三行
	P1=0xff;
	Hang3=0;
	if(lie1==0){MatrixKey_Number|=MK_S9;}
	if(lie2==0){MatrixKey_Number|=MK_S10;}
	if(lie3==0){MatrixKey_Number|=MK_S11;}
	if(lie4==0){MatrixKey_Number|=MK_S12;}
	//扫描第四行
	P1=0xff;
	Hang4=0;
	if(lie1==0){MatrixKey_Number|=MK_S13;}
	if(lie2==0){MatrixKey_Number|=MK_S14;}
	if(lie3==0){MatrixKey_Number|=MK_S15;}
	if(lie4==0){MatrixKey_Number|=MK_S16;}
    //消抖及松手检测
    LastMKey=NowMKey;
    NowMKey=MatrixKey_Number;//获取当前按键状态
    //当按键按下时间超过10ms,并且松手才输出按键键码
    if(LastMKey>0&&NowMKey==0)
    {
        LastMKey=Get_MatrixKey_Number;
    }
}











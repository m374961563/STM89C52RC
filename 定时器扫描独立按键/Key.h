#ifndef __KEY_H__
#define __KEY_H__

//外部可调用变量
extern unsigned char Get_Key_NumBer;//获取矩阵按键键码
void Key_Loop()();//按键驱动函数，在中断中调用,一般10ms调用一次.


#endif

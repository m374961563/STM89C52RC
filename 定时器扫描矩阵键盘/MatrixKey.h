#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__

//外部可调用变量
extern unsigned int Get_MatrixKey_Number;
    
void MatrixKey_Loop();//矩阵按键驱动函数，在中断中调用,一般10ms调用一次.

#endif

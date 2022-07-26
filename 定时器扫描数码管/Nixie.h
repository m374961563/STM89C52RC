#ifndef __NIXIE_H__
#define __NIXIE_H__

void Nixie_SetBuf(unsigned char Location,Number);//设置显示缓存区
void Nixie_Scan(unsigned char Location,Number);//数码管扫描显示
void Nixie_Loop();//数码管驱动函数，在中断中调用

#endif

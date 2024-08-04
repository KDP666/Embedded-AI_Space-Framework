#ifndef __COMMON__
#define __COMMON__

/****** 通用函数库 ********/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> //读写设备，文件相关函数
#include <sys/ioctl.h>

/*****时间管理模块 ******/
// 需要打开驱动设备 timer_space 计时设备

/*
 * 描述：时间管理模块的设备初始化
 * 输入：无
 * 输出：时间管理设备fid
 */
extern int timer_init(void);
/*
 * 描述：校时函数，校正计时器时间
 * 输入：所要校正的时间/ms
 * 输出：校时是否成功标志
 */
extern int set_time_ms(unsigned long long time);
/*
 * 描述：获得距离校时时刻的ms数，未校时，时间原点为设备开机时刻
 * 输入：所要校正的时间/ms
 * 输出：校时是否成功标志
 */
extern unsigned long long get_time_ms(void);
/*
 * 描述：延时函数
 * 输入：所要延迟的时间/ms
 * 输出：无
 */
extern void delay_ms(unsigned long ms);

#endif //__COMMON__

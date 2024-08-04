#ifndef __PROC__
#define __PROC__

// 声明入口函数- int(*)(void)
int task_1(void);

/*
 * 描述：进程入口函数，init.cpp主函数调用task函数
 * 		在项目中一定要对task函数指针赋值！
 * 参数：无
 * 返回：int型，成功返回1,失败返回非1
 *
 * int (*task)(void);
 */
#define __proc_entry__ task_1 //指定入口函数

#endif //__PROC__

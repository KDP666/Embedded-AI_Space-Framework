#include "common.hpp"
#include "proc.hpp"

using namespace std;

int (*task)(void) = __proc_entry__;

/*
 * 主程序入口
 * 描述：对程序线程进行初始化
 * 参数：线程运行cpu核心等
 * 返回：无
 */

int main(int argc, const char** argv){
	cpu_set_t cpuset;
	int cpu_bind;
	pthread_t thread;
	pid_t pid = getpid(); //获得线程pid
	int task_ret;

	cout<<"Space Linux Init Begin!"<<endl;

	/*********************** 输入参数检测 ***************************/
	if (argc < 2){
		cout<<"Init Error: please identify the Thread CPU Core: 0,1,2,3!"<<endl;
		return 0;
	}

	// 获取该线程所绑定的cpu核心
	cpu_bind = atoi(argv[1]);

	/*********************** 设置线程的CPU核心 **********************/
	CPU_ZERO(&cpuset);
	CPU_SET(cpu_bind, &cpuset);

	thread = pthread_self();
	pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);

	/*********************** 相关底层驱动初始化 ********************/
	timer_init();

	/********************** 运行指定任务************************/

	task_ret = task_1();

	if (task_ret == 1)
		cout<< "Process Running Over!"<<endl;
	else{
		cout<< "Process Running with Exception!"<<endl;
		return 0;
	}


	return 1;
}

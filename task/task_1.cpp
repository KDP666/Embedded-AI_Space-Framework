#include "proc.hpp"
#include "common.hpp"

using namespace std;
int task_1(void){
	unsigned long long time;
	unsigned long long set_time = 10000;

	cout<< "here" <<endl;

	time = get_time_ms();

	cout<<time<<endl;

	set_time_ms(set_time);

	time = get_time_ms();

	cout<<time<<endl;

	delay_ms(1200000);

	time = get_time_ms();

	cout<<time<<endl;

	return 1;
}

//char recv_buff[20];
///*************************串口测试***************************/
//uart_com ttyS1("/dev/ttyS1");
//
//ttyS1.uart_send("hello, Linux!");
//
////	while(1){
////		cout<<"Hello Pthread!"<<endl;
////		sleep(5);
////	}
//
//sleep(10);
//
//ttyS1.uart_recv(recv_buff, sizeof(recv_buff));
//
//printf("GoodBye Linux!\r\n");

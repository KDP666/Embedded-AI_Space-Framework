# Embeded Space-AI Framework 

本项目致力于构建一个高鲁棒性且对智能算法开发友好的嵌入式框架（Embeded Space-AI Framework）。该框架采用基于多核处理器的冗余安全设计，保障系统在极端环境下的稳定运行；同时，该框架的开发基于嵌入式Linux系统，支持现有主流AI算法框架（tf/pytorch等），保证创意性AI算法的快速迁移与实现。

Eembeded Space-AI Framework具有以下特点：

* 精确至ms的时钟管理模块
* 高效的多核冗余安全架构
* 丰富的对外通讯接口模块
* 可快速部署AI算法的系统环境

该项目已分享至  https://github.com/KDP666/Embedded-Space-AI-Framework 。

## 时钟管理模块

该模块采用Linux内核的1000Hz时钟，计时精度 $ \leq $ 1ms；同时，该框架支持Xenomai-4的EVL实时内核，可提供更短的线程调度和中断响应时间。

该时钟管理模块经过了cyclictest和latmus的响应延时测试（测试详情见后）。Linux内核最低响应延时为14us，平均响应延时为 19us，最高响应延时为81us；EVL实时内核最低响应延时为2.179us，平均响应延时为4.042us，最高响应延时为20.997us；两个内核的响应延时均$ \leq $ 100us。

时钟管理模块提供以下功能：

- 时钟校正功能
- 精确延时功能（延时精确度优于usleep系列函数）
- 当前时间读取功能

详情请见/include/common.hpp中timer模块。

## 多核冗余安全架构（开发中）

该架构的设计原理类似于生物DNA的表达模式。单个细胞的DNA序列包含生物体的全部信息，然而正常情况下，单个细胞只是选择性表达了DNA序列的部分信息，以完成与其他细胞的高效合作；当某一细胞失能后，其他细胞可通过完整的DNA序列信息复刻该细胞的工作职能，保障该生物系统的稳定运行。

现有的大多数嵌入式处理器都具有多个cpu核心（4核，6核，8核等）。本架构的每一个cpu核心都拥有完整的任务代码，类似于生物体的单个细胞。当所有cpu都正常工作时，各个cpu只会唤醒代码中的部分功能，多个cpu相互协作以实现任务代码的全部功能。但在极端环境下，某个cpu一旦失能，其他cpu可通过共享内存的cpu状态广播数据段确定该cpu已无法工作，从而重新进行任务分配，其他正常工作的cpu将承担失能cpu的功能。

该架构的示意图如下所示：

![多核CPU工作框架图](https://github.com/KDP666/ImageRepo/raw/main/CPU_schedule.png)



多核间的共享内存数据段承担着cpu核心间的通信工作，是该架构的核心组成部分，因此采用三取二的数据保护措施。该安全冗余的架构设计使得各个cpu核心即是相互协作的关系，又是相互备份的关系，兼顾了系统框架的高效运行需求与稳定安全特性。



## 通讯接口模块

该框架支持Linux内核提供的所有板间通讯协议，主要的通信接口如下：

- UART串口通讯（详见/include/uart.hpp）
- I2C通讯
- SPI通讯
- USB通讯



## AI算法环境部署

本框架基于嵌入式Linux内核架构，支持pytorch，tensorfolow等通用AI算法框架的部署，可实现AI算法的快速开发。



## 硬件平台，Linux内核版本

硬件平台：RaspberryPi 4B

Linux内核版本：Xenomai 4 （双内核架构：Linux kernel + EVL RT kernel）



## 开发语言

User Space：C++，python；

Kernel Space ：C （相关驱动开发）



## 附件说明

### 时钟管理模块测试

采用cyclictest测试Linux内核响应延时统计如下（24h test）：

>\#  Total: 032033055
>
>\# Min Latencies: 00014
>
>\# Avg Latencies: 00019
>
>\# Max Latencies: 00081

采用latmus测试EVL实时内核响应延时统计如下（24h test）：

>\# libevl version: evl.0.47
>
>\# sampling period: 1000 microseconds
>
>\# clock gravity: 0i 3000k 3000u
>
>\# clocksource: arch_sys_counter
>
>\# vDSO access: architected
>
>\# context: user
>
>\# thread priority: 89
>
>\# thread affinity: CPU2
>
>\# C-state restricted
>
>\# duration (hhmmss): 24:39:22
>
>\# peak (hhmmss): 14:35:16
>
>\# min latency: 2.179
>
>\# avg latency: 4.042
>
>\# max latency: 20.997
>
>\# sample count: 88763340

该测试使用的cpu核心均被隔离（isolated）。

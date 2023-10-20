## 镜像烧录和Linux镜像原理
-----------------------------
**1**. 什么是镜像？（运行环境+软件）
镜像是一种轻量级、可执行的独立软件包，用来打包软件运行环境和基于运行环境开发的软件，它包含运行某个软件所需的所有内容，包括代码、运行时、库、环境变量和配置文件。

**2**. linux系统的组成？
一个完整的linux系统，通常包含了Uboot、kernel、设备树以及根文件系统。

+ Uboot的全称 Universal Boot Loader，是遵循GPL条款的开源项目， U-Boot的主要作用是用来启动操作系统内核，它分为两个阶段，即boot + loader， boot阶段启动系统，初始化硬件设备，建立内存空间映射图，将系统的软硬件带到一个合适的状态， loader阶段将操作系统内核文件加载至内存，之后跳转到内核所在地址运行。
+ Linux内核是一个用来和硬件打交道并为用户程序提供一个有限服务集的低级支撑软件。在计算机硬件之上，为上层软件提供系统调用。Linux内核的主要模块（或组件）分以下几个部分：进程管理子系统、内存管理子系统、文件子系统、网络子系统、设备子系统等。
+ 设备树是一种描述硬件的数据结构，它把这些硬件设备的信息， 而这个文件，就是Device Tree（设备树），设备树包括设备树源码（Device Tree Source，DTS）文件、 设备树编译工具（Device Tree Compiler，DTC）与二进制格式设备树（Device Tree Blob，DTB）， DTS包含的头文件格式为DTSI。
+ 根文件系统（rootfs）是linux在初始化时加载的第一个文件系统， 根文件系统包括根目录和真实文件系统，它包含系统引导和使其他文件系统得以挂载（mount）所必要的文件。 根文件系统包函Linux启动时所必须的目录和关键性的文件，例如Linux启动时必要的初始化文件， 它在init目录下，此外根文件系统中还包括了许多的应用程序bin目录等， 任何包括这些Linux 系统启动所必须的文件都可以成为根文件系统。

ref：https://doc.embedfire.com/lubancat/build_and_deploy/zh/latest/building_image/image_composition/image_composition.html
**3**. 

```cpp


```                    


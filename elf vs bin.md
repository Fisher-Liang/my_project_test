https://www.cnblogs.com/embedded-linux/p/7237189.html


区别：
常用的可执行文件包含两类：原始二进制文件（bin）和可加载执行的二进制文件，在linux中可加载执行的二进制文件为elf文件。
BIN文件是直接的二进制文件，内部没有地址标记。bin文件内部数据按照代码段或者数据段的物理空间地址来排列。一般用编程器烧写时从00开始，而如果下载运行，则下载到编译时的地址即可。
在Linux OS上，为了运行可执行文件，他们是遵循ELF格式的，通常gcc -o test test.c，生成的test文件就是ELF格式的。执行elf文件时内核会使用加载器来解析elf文件并执行。

ELF文件格式是一个开放标准，各种UNIX系统的可执行文件都采用ELF格式，它有三种不同的类型：
可重定位的目标文件（Relocatable或者Object File）
可执行文件（Executable）
共享库（Shared Object，或者Shared Library）

 ELF格式提供了两种不同的视角，链接器把ELF文件看成是Section的集合，而加载器把ELF文件看成是Segment的集合。
在Embedded中，如果上电开始运行，没有OS系统，如果将ELF格式的文件烧写进去， 包含一些ELF文件的符号表字符表之类的section，运行碰到这些，就会导致失败，如果用objcopy生成纯粹的二进制文件，去除掉符号表之类的 section，只将代码段数据段保留下来，程序就可以一步一步运行。elf文件里面包含了符号表等。BIN文件是将elf文件中的代码段，数据段，还有一些自定义的段抽取出来做成的一个内存的镜像。并且elf文件中代码段数据段的位置并不是它实际的物理位置，实际物理位置是在表中标记出来的。

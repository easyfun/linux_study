####linux下存储分配

linux存储器系统函数<br/>
sbrk(2)

ISO C存储函数<br/>
malloc<br/>
calloc<br/>
realloc  可增减存储区长度，增加时内存重新分配，内存数据复制 <br/>

在linux下，mallc，calloc，realloc内部使用sbrk系统调用实现<br/>
大多数实现所分配的存储空间比要求的大一点，用于保存管理信息——分配块的长度，指向下一个分配块指针等等<br/>

注意：<br/>
不要在用户层分块块以外写数据，很可能破坏程序上下文<br/>
free一个已经释放的块，释放不是三个alloc函数返回的指针，会引起程序崩溃<br/>
malloc，calloc，realloc申请的内存用完后，要释放，避免内存泄漏。内存泄漏，使可用（虚拟）内存越来越少<br/>

也有很好的替代程序<br/>



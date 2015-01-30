###常用Linux命令行

命令行格式<br/>
command -options arguments<br/>

选项：-短选项(单词缩写)/--长选项(完整单词)

大小写敏感

在Linux下任何东西都是一个文件

1. man/info
查看命令帮助信息

2. date
日期

3. cal
日历

4. df
查看磁盘信息

5. free
查看内存信息

6. exit
退出终端

7. pwd
打印当前工作目录

8. cd
更改目录<br/>
cd/cd ~ 进入当前用户主目录<br/>
cd -	进入上一个工作目录

. 当前目录
..上一级目录

####4 探究操作系统
1. ls
查看目录/文件信息

2. file
查看文件类型<br/>
在Linux下，扩展名不决定文件的类型，辅助人们区分文件类型

3. less/cat
less分页查看文件内容<br/>
cat一次显示文件全部内容

####5 操作文件和目录
4. cp
复制文件和目录

5. mv
移动/重命名文件和目录

6. mkdir
创建目录

7. rm
删除文件和目录

8. ln
创建硬链接和符号链接(软链接)

硬链接：是档案的别名<br/>
		不能跨文件系统<br/>
		不能链接目录(实现起来麻烦，低效，不支持)，只能链接档案<br/>

ln file link 创建硬链接<br/>
ln -s file link 创建符号链接(软链接)<br/>

ext2文件系统<br/>
super block 记录文件系统的整体信息<br/>
inode 记录文档、目录的权限和属性，inode不记录目录、文件名，目录名、文件名记录在block中<br/>
block 记录文档、目录的数据<br/>

目录的权限<br/>
r 读取目录中的子目录、文档名列表，读取目录的权限、属性，ls命令<br/>
w 在目录中增加、删除子目录、文档，修改子目录、文档的名称<br/>
x 进入目录，把目录作为当前工作目录，cd命令<br/>


####6 使用命令
四类指令<br/>
可执行程序<br/>
shell内置命令，cd<br/>
shell函数<br/>
命令别名<br/>

1. type
说明怎样解释一个命令名

2. which
显示会执行哪个可执行程序，只对可执行程序的指令有效

3. man/info
显示命令手册页

4. apropos
显示一系列合适的命令

5. whatis
显示一个命令的简洁描述

6. alias
创建命令别名

####7 重定向
标准输入<br/>		<
标准输出<br/>		>
标准错误<br/>		&>     2>&1

1. 管道线|
command1|command2<br/>
command1输出作为command2的输入<br/>

2. 过滤器
sort 排序<br/>
uniq 去掉重复内容<br/>
wc 打印行、字和字节数<br/>
grep 打印匹配行<br/>
head 打印文件开头部分<br/>
tail 打印文件结尾部分<br/>
tee 从stdin读取数据，同时输出到stdout和文件<br/>

####9 键盘高级操作技巧
1. clear
清空屏幕

2. history
显示历史命令列表内容

3. tab键
文件目录名，命令名自动补全

####10 权限
1. id
显示用户身份号

/etc/passwd文件保存账号信息<br/>
/etc/group文件保存群组信息<br/>
/etc/shadow文件报错账号密码信息<br/>

2. chmod
更改文件模式

只有文件的所有者和超级用户才能改文件、目录的模式

3. umask
设置默认的文件权限

使用八进制表示，从文件模式属性中删除一个位掩码<br/>
xxxx<br/>
特殊权限-owner-group-other<br/>

4. su
以另一个用户的身份来执行shell<br/>
_注意：_启动一个新的shell，并加载新用户的shell运行环境，原先的shell还存在<br/>

su -l [user]<br/>
su -c 'command'<br/>


5. sudo
以另一个用户的身份来执行命令<br/>

_注意：_不会启动新的shell，也不会加载新用户的shell运行环境<br/>
验证的密码不是超级用户的密码，而是当前会话用户的密码<br/>


6. chown
更改文件的拥有者（所有者）、用户组（群组）<br/>

chown [user][:[group]] file...


7. chgrp
更改文件的群组

8. passwd
更改用户密码


####11 进程
1. ps<br/>
报告当前进程快照<br/>

ps         列出与当前终端会话相关的进程运行信息<br/>
ps x       显示所有进程运行信息<br/>
ps aux     BSD风格显示所有进程运行信息<br/>

2. top<br/>
显示任务，定时刷新<br/>

3. jobs<br/>
列出活跃的任务<br/>

Ctrl+c   可以关闭在shell中的大部分进程<br/>

4. bg<br/>
把一个任务放到后台执行<br/>

command &   工作控制，在shell起后台进程<br/>
jobs        列出从shell启动的进程清单<br/>

Ctrl+z      stop挂起shell中当前前台进程，不是杀进程<br/>
bg %jobspec 在后台唤醒挂起的进程<br/>

5. fg<br/>
把一个任务放到前台执行<br/>

fg %jobspec<br/>

6. kill<br/>
给一个进程发送信号<br/>
kill [-signal] PID<br/>

Ctrl+c       INT(中断)信号<br/>
Ctrl+z       TSTP(终端停止)信号<br/>

7. killall<br/>
杀死指定名字的进程<br/>

kill [-user] [-sginal] name<br/>

8. shutdown<br/>
关机或重启系统<br/>

9. pstree<br/>
输出一颗进程树，展示进程间的父子关系<br/>

10. vmstat<br/>
输出系统资源快照

vmstat time 定时刷新系统资源快照

11. xload,tload
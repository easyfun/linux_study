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


####12 shell环境
shell变量<br/>
环境变量<br/>

1. printenv<br/>
打印部分或全部环境变量，只显示环境变量<br/>

2. set<br/>
设置shell选项，可以查看环境变量和shell变量<br/>

echo<br/>
echo &VARIRY<br/>

3. export<br/>
导出环境变量，让随后执行的程序知道<br/>

4. alias<br/>
创建命令别名<br/>

5. shell会话类型<br/>
两种shell坏话类型：<br/>
登录shell会话，shell，虚拟终端<br/>
非登录shell会话，GUI模式<br/>


####13 vi简介<br/>
普通模式（命令模式）<br/>
ex命令模式(普通模式下输入:)<br/>
编辑模式<br/>
ESC---INSERT按键（i按键）---普通模式按下:按键

1. 启动<br/>
vi options filename<br/>

2. 退出<br/>
ex命名模式<br/>
退出  :q    <br/>
强制退出  :q!    <br/>

3. 保存<br/>
普通模式：ZZ    <br/>
ex命令模式：:w      另存为：:w filename
ex命令模式：:wq     :wq filename

4. 打开一行<br/>
普通模式：o/O    <br/>

5. 删除<br/>
普通模式：x    <br/>

6. 剪切<br/>
普通模式：d    <br/>

7. 复制<br/>
普通模式：y    <br/>

8. 粘贴<br/>
普通模式：p/P    <br/>

9. 连接行<br/>
普通模式：J    <br/>


####14. 软件包管理
系统中一种安装和维护软件的方法。<br/>

主要的包管理系统：<br/>
.deb<br/>
.rpm<br/>

1. 包文件

2. 资源库

3. 依赖性

4. 上层和底层软件包工具<br/>
底层工具：安装、删除软件包文件<br/>
上层工具：完成元数据搜索和依赖项解析<br/>

发行版                     底层工具        上层工具
Debian-Style               dpkg            apt-get,apttitude
Fedora,RHEL,CentOS         rpm             yum

package_name 软件包实际名称<br/>
package_file 包含在软件包中的文件名<br/>


5. 查找资源库中的软件包
上层工具命令<br/>
风格        命令
Debian      apt-get update;apt-cache search search_string
RHEL        yum search search_string

6. 从资源库中安装一个软件包
上层工具命令<br/>
风格        命令
Debian      apt-get update;apt-cache install package_name
RHEL        yum install package_name

7. 通过软件包文件来安装软件
获取到软件包文件，用底层工具安装，没有依赖解析，安装中rpm发现缺少依赖，会报错退出<br/>
底层工具命令<br/.
风格        命令
Debian      dpkg --install package_file
RHEL        rpm -i package_file

8. 卸载软件
可以用底层工具和上层工具

上层工具命令<br/>
风格        命令
Debian      apt-get remove package_name
RHEL        yum erase package_name

9. 通过资源库更新软件包
上层工具命令<br/>
风格        命令
Debian      apt-get update;apt-get upgrade
RHEL        yum update

10. 通过软件包文件更新软件
风格        命令
Debian      dpkg --install package_file
RHEL        rpm -U package_file

11. 列出所安装的软件包
底层工具命令<br/>
风格        命令
Debian      dpkg --list
RHEL        rpm -qa

12. 确认是否安装了一个软件
底层工具命令<br/>
风格        命令
Debian      dpkg --status package_name
RHEL        rpm -q package_name

13. 显示所安装软件包的信息
上层工具命令<br/>
风格        命令
Debian      apt-cache show package_name
RHEL        yum info package_name

14. 查找安装某个文件的软件包
底层工具命令<br/>
风格        命令
Debian      dpkg --search file_name
RHEL        rpm -qf file_name


####16 存储媒介

1. mount<br/>
挂载一个文件系统<br/>

2. umount<br/>
卸载一个文件系统<br/>

3. fsck<br/>
检查和修复一个文件系统<br/>

4. fdisk<br/>
分区表控制器<br/>

5. mkfs<br/>
创建文件系统<br/>

6. fdformat<br/>
格式化一张软盘<br/>

7. dd<br/>
把面向块的数据直接写入设备<br/>

8. genisoimage(mkisofs)<br/>
创建一个ISO 9660的映像文件<br/>

9. wodim(cdrecord)<br/>
把数据写入光存储介质<br/>

10. md5sum<br/>
计算MD5校验码<br/>


####17 网络系统
1. ping<br/>
发送ICMP ECHO_REQUEST数据包到网络主机<br/>

2. traceroute<br/>
打印到一台网络主机的路由数据包<br/>

3. netstat<br/>
打印网络连接，路由表，接口统计数据，伪装连接，多路广播成员。<br/>

netstat -ie<br/>
查看系统中的网络接口<br/>
因特网接口eth0<br/>
内部回环网络接口lo<br/>

netstat -r<br/>
查看路由表<br/>

4. ftp<br/>
因特网文件传输程序<br/>
客户端程序<br/>

第一步：启动ftp应用
第二步：登录（user，password)
第三步：进入远端目录
第四步：切换本地目标目录
第五步：下载
第六步：退出

lftp
ftp客户端程序<br/>

5. wget<br/>
非交互式网络下载器<br/>

6. ssh<br/>
OpenSSH SSH 客户端（远程登录程序）<br/>


####18 查找文件
1. locate<br/>
通过名字查找文件<br/>
在路径名数据库中查找，速度快。路径名数据库，不是实时更新，可能找不到<br/>
locate数据库由updatedb程序创建更新<br/>

2. find<br/>
在目录层次结构中搜索文件<br/>

3. xargs<br/>
从标准输入生成和执行命令<br/>

4. touch<br/>
更改文件时间，创建空文本文件<br/>

5. stat<br/>
显示文件或文件系统状态<br/>


####19 归档和备份
压缩算法分为两大类：<br/>
无损压缩，解压的文件与原始文件一样<br/>
有损压缩，解压出的文件与原始文件有区别<br/>

1. gzip<br/>
压缩或者展开文件<br/>
文件扩展名.gz<br/>

gunzip    解压<br/>

2. bzip2<br/>
块排序文件压缩器<br/>
文件扩展名.bz2<br/>
相比gzip，bzip2舍弃了速度，压缩级别更高<br/>

bunzip2,bzcat    解压<br/>

3. tar<br/>
磁带打包工具<br/>

.tar文件，普通的tar包<br/>
.tgz文件，经gzip压缩过的tar包<br/>

常用模式:<br/>
c    创建归档文件<br/>
x    抽取归档文件<br/>
r    追加具体的路径到归档文件的末尾<br/>
t    列出归档文件的内容<br/>
z    使用gzip压缩包<br/>
j    使用bzip2压缩包<br/>

tar cf file.tar file<br/>
tar tf file.tar<br/>
tar xf file.tar<br/>

4. zip<br/>
打包和压缩文件<br/>

unzip    解压zip包<br/>


5. rsync<br/>
同步远端文件和目录<br/>

小结：<br/>
压缩，解压单个文件：<br/>
gzip,bzip2独立的单个文件<br/>

打包多个文件：<br/>
tar,zip<br/>

常用排名：<br/>
gzip<br/>
bzip2<br/>
tar<br/>
zip<br/>


####21    文本处理
unix行结束，\n    <br/>
MS-DOS行结束，\r\n    <br/>
dos2unix<br/>
unix2dos<br/>

1. cat<br/>
连接文件并且打印到标准输出<br/>

-A    显示非打印字符<br/>
-n    显示行号<br/>
-s    禁止输出多个空白行<br/>

2. sort<br/>
给文本行排序<br/>

3. uniq<br/>
报告或者省略重复行<br/>

4. cut<br/>
从每行中删除文本区域<br/>

5. paste<br/>
合并文件文本行<br/>

6. join<br/>
基于某个共享字段来联合两个文件的文本行<br/>

7. comm<br/>
逐行比较两个有序的文件<br/>

8. diff<br/>
逐行比较文件<br/>

-c    上下文模式<br/>
-u    统一模式<br/>

9. patch<br/>
给原始文件打补丁<br/>

制作发布diff文件<br/>
diff -Naur old_file new_file > diff_file<br/>
更新文件<br/>
patch < diff_file<br/>

10. tr<br/>
翻译或删除字符<br/>

11. sed<br/>
用于筛选和转换文本的流编辑器<br/>

12. aspell<br/>
交互式拼写检查器<br/>


####22 格式化输出
1. nl<br/>
添加行号<br/>

2. fold<br/>
限制文件列宽<br/>

3. fmt<br/>
一个简单的文本格式转换器<br/>

4. pr<br/>
让文本为打印做好准备<br/>

5. printf<br/>
格式化数据并打印出来<br/>

6. groff<br/>
一个文件格式系统<br/>

####24 编译程序
1. make<br/>
维护程序的工具<br/>











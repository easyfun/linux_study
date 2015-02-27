###鸟哥的Linux私房菜服务篇

###第1章 架站之前所需的技能分析
1.1 架设一台完美服务器的基本功课<br/>
熟练操作操作系统，登录分析，账号管理，文件系统管理<br/>
网络知识<br/>
防火墙知识<br/>

1.2 架站的基本流程<br/>
了解网络基础<br/>
了解架站的目的<br/>
Linux硬盘规划<br/>
了解想要架站的服务原理<br/>
服务软件的安装、漏洞补修、包升级<br/>
主机设置、启动、观察与调试<br/>
客户端设置、观察与调试<br/>
安全性设置<br/>
服务日志、日志文件与备份管理<br/>

###第2章 网络基本概念
2.1 网络<br/>
2.1.2 以太网<br/>
网络硬件：光纤网络，以太网，wifi，蓝牙，ATM<br/>
各种网络硬件适用于不同的场景<br/>

1.以太网速度：
第一代 10Mbps 同轴电缆线 后来用双绞线<br/>
第二代 100Mbps 双绞线<br/>
第三代 1000Mbps 更好的双绞线<br/>

同轴电缆线    总线（bus）连接<br/>
双绞线        星形连接（集线器，交换机，路由器）<br/>

2.以太网的接头：RJ-45接头（568A，568B）<br/>

网线种类：
并行线  两个568A接头的网线，连接主机网卡和集线器<br/>
跳线    一个568A，一个568B接头的网下，直接连接两个主机网卡<br/>

3.数据在以太网间的传送（MAC)<br/>
_网络共享介质_在单一时间点内，仅能被一台主机使用<br/>
以太网采用CSMA/CD技术，载波监听多路访问/冲突检测技术，工作在网络共享介质上<br/>
以太网数据传输使用广播方式，在同一个子网内部<br/>
通信方式：点对点，广播（组播）<br/>

MAC帧是网络硬件上数据传送的最小单位<br/>

以太网MAC帧的结构<br/>
链路层--           目的地址6B 源地址6B 数据域位通信2B 数据46~1500B 校验码4B<br/>
物理层--  前导码8B 以太网MAC帧
[!mac_image](./images/yi_tai_wang_mac_format.png)

数据部分长度有扩展<br/>
不同的网络介质，MAC帧格式不一样<br/>

MAC地址  6个字节<br/>
前3个字节厂商编码<br/>

4.共不共享很重要，集线器还是交换机<br/>
集线器（Hub）是共享媒介<br/>
交换机（Switch）不是共享媒介<br/>

2.1.3 OSI七层协议<br/>
开放式系统互联参考模型<br/>
从下到上：物理层，链路层，网络层，传输层，会话层，表示层，应用层<br/>
下层为上层服务<br/>

五层参考模型<br/>
从下到上：物理层，链路层，网络层，传输层，应用层<br/>

各层的作用<br/>
物理层 定义硬件的电器特性（0，1信号的电压等等），传输0，1信号<br/>
       集线器工作在这层<br/>

链路层 定义网络上传输数据的最小单位（帧格式），错误检查，流量检查<br/>
       单独的0，1信号是没有意义的；帧是0，1信号的组合，有意义<br/>
       以太网工作在物理层，链路层<br/>

网络层 定义IP地址，划分子网，确定路由<br/>
       交换机，路由器工作在这层<br/>

传输层 <br/>

应用层 <br/>

Tcp/IP协议结构<br/>
[!tcp_ip_protocol_1](tcp_ip_protocol_1.png)
[!tcp_ip_protocol_2](tcp_ip_protocol_2.png)

每一层都实现特定的服务，包含特点的协议。协议与服务不是同一个概念。<br/>
算法+协议实现服务<br/>


2.2 IP与MAC<br/>

2.2.1 传输单位与MAC<br/>
MAC（媒体访问控制），MAC帧在同一个IP网段上广播，不能跨IP网段。<br/>
MAC帧中 源MAC地址，目标MAC地址<br/>

ipconfig 查看IP和MAC地址。<br/>

ARP 地址解析协议，获取同个IP网段内的指定IP主机的网卡的MAC地址。<br/>
    arp table 同个IP网段的IP-MAC地址表，动态更新，可以添加静态记录<br/>
RARP 逆地址解析协议。<br/>

2.2.2 IP的组成<br/>
IP地址 32bit，通常使用点分十进制格式<br/>
       IP地址分成两个部分，Net_ID+Host_ID<br/>
       Net_ID，子网掩码用来划分子网<br/>

IP协议 IPv4，IPv6<br/>

2.2.3 网段的概念与IP的分级<br/>
1. 网段的概念<br/>
MAC地址不能分子网，以太网采用广播通信，同一个网络的主机数目不能太大，所以采用IP地址。<br/>
IP地址分成两个部分，Net_ID+Host_ID<br/>
Net_ID，子网掩码用来划分子网<br/>

物理网段 同一个物理网段可以化成多个IP网段<br/>
IP（网络）网段<br/>

2. IP的分级<br/>
A，B，C三类地址<br/>

A类 前8位 以0开头<br/>
B类 前16位 以10开头<br/>
C类 前24位 以110开头<br/>

127.xxx.xxx.xxx是一个C类地址，不供Internet使用，给了操作系统，作为内部循环网络<br/>

2.2.4 Netmask的用途与子网的划分<br/>
A，B，C类地址使用率太低，使用Netmask再次划分网络，计算IP网段<br/>

两种记法<br/>
IP/位数 192.168.0.52/24<br/>
IP/点分十进制 192.168.0.52/255.255.255.0<br/>

IP按位与Netmask==Net_ID<br/>

2.2.5 IP的种类与取得方式<br/>
1.IP的种类<br/>
公有IP 在Internet上使用<br/>
私有IP 在局域网使用<br/>
       解决IPv4的IP数不足<br/>

私有IP保留了A，B，C3类IP地址段<br/>
A类 10.0.0.0~10.255.255.255<br/>
B类 172.16.0.0~172.31.255.255<br/>
C类 192.168.0.0~192.168.255.255<br/>

私有IP的限制<br/>
私有地址的路由信息不能对外广播<br/>
使用私有地址作为源或目的地址的数据包，不能在Internet上传送<br/>
关于私有地址的参考记录（如DNS），只能在内部网络使用<br/>

局域网（内网）内的主机要访问Internet，通过启动防火墙和NAT服务的主机，做了IP伪装后访问Internet<br/>

2.特殊的loopback IP网段<br/>
主机没有联网，通过内部循环网络（内部回环网络），做网络服务测试<br/>

3.IP的取得方式<br/>

2.2.6 IP数据包的表头<br/>
IP包头+IP包体<br/>

IP包头的长度是32bits的整数倍<br/>
IP数据包的最大长度65535B，包括包头长度和包体长度<br/>

IP包头的关键字段<br/>
TTL Time to life，存活时间，能通过的路由器的最大数目<br/>
Protocol<br/>
来源IP<br/>
目标IP<br/>

2.3 网络层路由的概念<br/>
2.3.1什么是路由<br/>
主机间发送数据包时，确定下个节点MAC地址（目标接口，或者网关/路由器）的过程<br/>
通过路由表进行<br/>

Network A有2台主机PC01，PC02<br/>
Network B有2台主机PC11，PC02<br/>
Network A和Network B通过路由器Server A连接<br/>
PC01(192.168.0.1)，PC02（192.168.0.2），GW路由器接口1（192.168.0.254）<br/>
PC01(192.168.1.1)，PC02（192.168.1.2），GW路由器接口1（192.168.1.254）<br/>
PC01向PC02发送数据的路由过程?<br/>
要点：主机在组装MAC帧时，通过目标IP，路由表，arp表，确定目标MAC地址<br/>

2.3.2观察主机的路由<br/>
route [-n]<br/>

路由表字段<br/>


路由表的记录，有程序在维护，动态监视网络状态，修改路由信息，也可以手动设置静态记录<br/>


2.4 常见的通讯协议<br/>
TCP，UDP，ICMP<br/>

2.4.1TCP协议<br/>
TCP提供面向连接的，可靠的通信服务<br/>
IP层定义IP格式，定义子网划分的方式，定义路由选择方式，不关心网络的工作状态，硬件损坏，网络拥塞......<br/>

1.TCP数据包头<br/>
重要的几个：源端口，目标端口，控制标识码，TCP数据包序号<br/>
控制标志码重要的字段：SYN，ACK，FIN<br/>
SYN 连接请求标志<br/>
ACK 相应数据包标志<br/>
FIN 数据发送完毕请求断开连接标志<br/>

2.通讯端口与Socket<br/>
端口用于标志主机上的进程<br/>
端口数目65536，编号0，1，2，...，65535<br/>
0到1023的端口号系统保留<br/>

每条连接，客户端、服务端都要分配一个端口号<br/>
Socket包含的信息有 源IP，目标IP，源端口，目标端口<br/>

3.数据包的传送<br/>
连接建立经过3次握手，进行3次TCP数据包的传送。<br/>
要点：请求SYN，应答ACK，TCP数据包序号<br/>

2.4.2UDP协议<br/>
UDP提供无连接的，不可靠的通讯服务<br/>
通讯过程中，无需建立连接，没有3次握手，通信实时<br/>
DNS服务器采用UDP/TCP混合工作方式<br/>

2.4.3ICMP协议<br/>
因特网信息控制协议<br/>
进行错误检测和回报，功能是确保网络的连接状态和连接的正确性<br/>
ICMP数据包放在IP数据包的包体中<br/>

ping，traceroute命令使用ICMP协议<br/>

2.4.4MTU限制<br/>
最大传输单元<br/>
指一种通信协议的某一层上面所能通过的最大数据包大小（以字节为单位）。最大传输单元这个参数通常与通信接口有关（网络接口卡、串口等）<br/>

MTU越大，网络传输效率越高，延迟越大。<br/>
MTU不是越大越好，采用合适的值<br/>

Internet网硬件多样，不要轻易改变MTU，尽量使用小的值<br/>

2.4.5数据包过滤的防火墙概念<br/>
解析MAC包头，IP包头，TCP包头......各种协议包头，按照一定的规则，丢掉数据包<br/>

2.5连上Internet前的准备事项<br/>
2.5.1什么是主机名称与DNS<br/>
IP是一串数字，记忆不方便。为了便于记忆，使用主机名，或者域名。<br/>
互联网底层，依赖与IP地址，所以建立DNS服务<br/>
DNS服务器 找到域名对应的IP<br/>

2.5.2连上Internet的必要网络参数<br/>
IP，Netmask，Network，Broadcast，Gateway，DNS<br/>


###第3章 局域网架构简介与Linux版本选择
3.1局域网的联机<br/>
3.1.1什么是局域网<br/>
LAN local area network<br/>
在同一个物理网段内（可以包含多个IP网段），使用IP或者局域网适用的通信协议串起来的网络环境<br/>

局域网可以访问Internet<br/>
使用IP分享器<br/>
使用NAT服务器<br/>

###第4章 连上Internet
4.1Linux连上Internet前的注意事项<br/>
4.1.1Linux的网卡<br/>

4.1.2编译网卡驱动程序<br/>
1.解压缩与编译<br/>
2.模块的测试与处理<br/>
3.设置开机自动启动网卡模块<br/>

4.1.3Linux网络相关设置文件<br/>
系统开机会读取网络配置文件，初始话化网络相关的参数<br/>

1.与网络相关的文件<br/>
（1）/etc/sysconfig/network<br/>
设置主机名称，自动启动Network<br/>

（2）/etc/sysconfig/network-scripts/ifcfg-eth0<br/>
设置网卡参数的文件（IP，Network，Netmask，Broadcast，Gateway，IP取得方式）<br/>

（3）/etc/modprobe.conf<br/>

（4）/etc/resolv.conf和/etc/hosts<br/>
DNS服务相关<br/>

（5）/etc/services<br/>
记录TCP/IP上的所有协议<br/>

（6）/etc/protocols<br/>
定义IP数据包协议相关的数据<br/>


2.与网络相关的启动指令<br/>
（1）/etc/init.d/network restart<br/>
script文件。重启网络参数，重新加载网络配置文件初始话网络参数<br/>

（2）ifup eth0（ifdown eth0）<br/>
script文件。启用，关闭网络接口<br/>

4.2连上Internet的方法<br/>
4.2.1固定IP上网方式<br/>
4.2.2可自动取得IP的环境<br/>
4.2.3ADSL拨号连接上网<br/>

4.3无线网络<br/>

###第5章 Linux常用的网络命令
ifconfig 查询、设置网卡与IP网段等参数，热设置不会修改网络配置文件<br/>
ifup、ifdown 两个脚本文件。启动、关闭网络接口，不会改变网络配置文件<br/>
Route 查询、设置路由表<br/>
ip 复合式命令，可以直接修改上述命令提到的功能<br/>

ip指令功能很强大<br/>
ip [option] [操作] [命令]<br/>
参数：<br/>
option -s 显示统计信息<br/>
操作<br/>
    link  关于设备的相关设置，包括MTU、MAC地址，链路层参数<br/>
    address 关于IP网络参数设置，包括IP，Network，Netmask，Broadcast等，网络层参数<br/>
    route 与路由有关的设置<br/>

iwlist，iwconfig<br/>
无线网络使用的指令<br/>

dhClient<br/>
使用DHCP获取IP网络参数<br/>

5.2网络侦错与观察指令<br/>
ping<br/>
traceroute<br/>
netstat<br/>
host<br/>
nslookup 建议使用dig<br/>

ICMP两类报文 差错报告报文和询问报文<br/>
差错报告报文 终点不可达，源点抑制，时间超过，参数问题，改变路由<br/>
询问报文 回送请求或问答，时间戳请求或问答<br/>

5.2.1ping<br/>
检测两台主机间的网络是否是通的<br/>
网络中的节点在收到数据包（不局限于ICMP询问报文）时，如果发现错误，会主动给源主机发送ICMP差错报告报文<br/>
ping指令使用ICMP回送请求和回送回答报文，应用层直接使用网络层ICMP协议,通过IP包发送ICMP包<br/>

5.2.2tracetoute<br/>
检测两台主机间的路由<br/>
traceroute 主要利用IP包头的TTL字段，数据包是无法交付的UDP数据包（端口号非法）<br/>

5.2.3netstat<br/>
检测主机的联机状态<br/>
netstat -[rn]    <==与路由有关的参数<br/>
netstat -[antulpc]   <==与网络接口有关的参数<br/>

stat连接状态<br/>
ESTABLISED：已建立连接的状态<br/>
SYN_SENT：发出主动连接（SYN标志）的连接数据包<br/>
SYN_RECV：接收到一个要求连接的数据包<br/>
FIN_WAIT1：该连接正在断开连接<br/>
FIN_WAIT2：该连接已挂断，但正在等待对方主机响应断线确认的数据包<br/>
TIME_WAIT：该连接已挂断，但socket还在网络上等待结束<br/>
LISTEN：通常用在服务的监听port<br/>

5.2.4 host<br/>
通过主机名查找IP<br/>

5.2.5 nslookup<br/>
通过主机名查找IP，通过IP查找主机名<br/>

5.3远程联机命令<br/>
远程联机 在不同的计算机之间登录<br/>

5.3.1 Telnet<br/>
telnet [host|IP] [port]<br/>

5.3.2 FTP<br/>
5.3.3 LFTP<br/>
FTP客户端<br/>

5.4文本网页浏览<br/>
5.4.1 lync<br/>
文字接口模式下的“浏览器”<br/>

5.4.2 wget<br/>
文字接口模式下的下载工具<br/>

5.5 数据包捕获功能<br/>
5.5.1 tcpdump<br/>
数据包分析工具<br/>

5.5.2 ethereal<br/>
网络流量分析工具<br/>
有文本界面和图形界面<br/>

5.5.3 nc、netcat<br/>
服务检测，针对port<br/>

###第6章 Linux网络侦错<br/>

###第10章 认识网络安全<br/>
10.1网络数据包进入主机的流程<br/>
10.1.1数据包进入主机的流程<br/>
1.数据包过滤防火墙：IP Filtering或Net Filter<br/>
iptabels软件提供的防火墙功能<br/>

2.第二层防火墙：TCP Warppers<br/>

3.服务（daemon）的功能<br/>

4.使用主机的文件系统资源<br/>
通过操作系统内核调用<br/>

10.1.2主机能做的保护：权限设置、软件更新、SELinux<br/>
1.权限的重要性<br/>
2.严格保证密码的复杂性<br/>
3.软件更新的重要性<br/>

4.SELinux<br/>
内核模块，针对文件系统权限作更细部规划的模块，不是防火墙软件<br/>

10.3 常见攻击手段与主机保护方式<br/>
1.取得账号信息猜密码<br/>
2.利用系统的程序漏洞主动攻击<br/>
3.利用社交工具欺骗<br/>
4.利用程序功能的被动攻击<br/>
5.蠕虫或木马的rootkit<br/>

6.DoS攻击(Denial of Service)<br/>
Client向Server发送SYN数据包请求建立连接，Server会送ACK/SYN数据包，Client丢弃这个数据包，让Server空等，Server占用一个Port。DoS攻击会耗尽主机系统的Port，是主机网络功能瘫痪。在内网中，可使整个网络瘫痪。
应对方式：系统内核自动抵挡DoS攻击<br/>
          侦测软件防御<br/>

7.其它<br/>
数据包内部信息替换，ip，tcp头部信息替换。<br/>

10.4被入侵后的修复工作<br/>
10.4.1网管人员必备技巧与任务<br/>

10.4.2入侵恢复工作<br/>
1.立即拔除网线<br/>

2.分析日志文件信息，搜索可能的入侵途径<br/>
分析日志文件：/var/log/messages，/var/log/secure文件，last指令查看登录主机的账号信息<br/>
检查主机开放的服务：

3.重要数据备份<br/>

4.重装系统<br/>

5.软件的漏洞修补<br/>

6.关闭或移除不需要的服务<br/>

7.数据恢复与恢复服务设置<br/>

8.连上Internet<br/>


###第18章 WWW服务器

WEB使用HTTP协议，传送文字、图形、影像、声音等多媒体信息，通过超文本方式在Internet上传输数据<br/>
HTTP协议 超文本传输协议<br/>

1.WWW使用HTTP协议，分为服务器与客户端<br/>
    服务器：开源 Apache，Nginx，Tomact，lighttpd；商业 Microsoft IIS，IBM WebSphere<br/>
    客户端：Chrome，Firefox，Opera，IE，UC<br/>
2.Apache是服务端软件，主要依据HTTPd服务器发展而来，开源软件<br/>
3.Mozilla是一个开源软件的开发计划，firefox浏览器<br/>
4.网页文件尽量使用W3C标准<br/>

18.2.2WWW主机与浏览器所提供的资源设置<br/>
Web服务器提供数据和文件，HTML,CSS,JavaScript等<br/>
数据保存在服务端文件或数据库（数据库文件也保存在磁盘中）<br/>
保存Web文件的默认目录/var/www/html/或/srv/www/ <br/>
CentOS保存Web文件的默认目录/var/www/html/ <br/>

1.URL<br/>
<协议>://<主机地址或主机名称（域名）>[:port]/<目录资源>   <br/>
（1）协议<br/>
常用协议 HTTP,HTTPs,FTP,Telnet,news,gopher等<br/>
（3）目录资源<br/>
http://hostdomain对应/var/www/html，首页文件index.html,index.php等<br/>
http://hostdomain/linux_basic/index.php对应/var/www/html/linux_basic/index.php <br/>

2.传递数据的方法<br/>
GET，POST，HEAD，OPTIONS，DELETE<br/>

10.2.3 WWW服务器的类型<br/>
1.主机分类<br/>
（1）静态网站<br/>
（2）动态网站<br/>
Web服务器通过“网页程序语言”与代理（浏览器等）用户互动<br/>
“网页程序语言” PHP，Python，perl，ASP，JavaScript等<br/>

网页动态化 JavaScript，flash<br/>

常用架构<br/>
1.Linux+Apache+PHP+MySQL<br/>
2.Linux+Nginx+PHP+MySQL<br/>
3.Linux+Tomcat+MySQL<br/>
4.Windows+IIS+ASP+MSSQL<br/>

18.2.4加密的网页数据（SSL）及第三方公正单位<br/>
HTTP协议数据明文传输，有被窃取风险<br/>
HTTPS协议数据加密传输<br/>

1.SSL（Secure Socket Layer）<br/>
公钥加密，私钥解密<br/>
2.CA（Certificate Authorities）<br/>

18.2.5常用浏览器<br/>
Chorme，Firefox，Opera，IE<br/>

Linux下文字接口 lynx，wget<br/>

18.3WWW（Apache）服务器基本设置<br/>

18.3.1LAMP所需软件与其结构<br/>
1.所需软件<br/>
httpd<br/>
mysql<br/>
mysql-Server<br/>
php<br/>
php-devel（与PHP加速软件有关）<br/>
php-mysql<br/>

尽量使用yum安装，不用tarball（打包工具，源码安装）<br/>
yum install httpd mysql-Server php php-devel php-mysql<br/>

Apache命名<br/>
主要版本 1.3.x，2.0.x，2.2.x<br/>
最新已经到了2.4.x<br/>
1.3.x以前称为Apache<br/>
2.x以后称为HTTPd<br/>

2.主要目录结构<br/>

（1）Apache主要文件目录<br/>
/etc/httpd/	  配置文件目录<br/>
    /etc/httpd/conf/httpd.conf   主要配置文件<br/>

/usr/lib/httpd/modules/   模块目录<br/>

/var/www/   网站文件目录<br/>
    /var/www/html/<br/>
    /var/www/error/<br/>
    /var/www/cgi-bin/<br/>

/var/log/httpd/   日志文件目录<br/>

/usr/sbin/apachectl   服务执行脚本文件<br/>

/usr/sbin/httpd   Apache二进制执行文件<br/>

/usr/bin/htpasswd   Apache密码保护<br/>


（2）MySQL主要文件目录<br/>
/etc/my.cnf   MySQL的配置文件<br/>

/var/lib/mysql/   MySQL数据库文件存放位置<br/>


（3）PHP主要文件目录<br/>
/usr/lib/httpd/modules/libphp4.so   PHP提供给Apache使用的模块<br/>

/etc/httpd/conf.d/php.conf   PHP设置参数<br/>

/etc/php.ini   PHP主要配置文件<br/>

/etc/php.d/mysql.ini，/usr/lib/php4/mysql.so   PHP支持MySQL的文件<br/>

/usr/bin/phpize，/usr/include/php/   PHP加速器软件相关<br/>


18.3.2httpd.conf的基本设置<br/>
1.针对主机环境的设置项目<br/>
Apache有两种工作模式<br/>
    prefork   单线程多进程   执行文件/usr/sbin/httpd<br/>
    worker   多进程多线程   执行文件/usr/sbin/httpd.worker<br/>

/etc/sysconfig/httpd文件指定了工作模式<br/>

2.针对中文Big5编码语言<br/>

3.首页权限相关设置（DocumentRoot与Directory）<br/>


18.3.3PHP等额外配置文件<br/>


18.3.4Apache的启动与PHP的测试<br/>
1.传统方法<br/>
/etc/init.d/httpd start   启动<br/>
/etc/init.d/httpd stop   关闭<br/>

2.利用脚本<br/>
/usr/sbin/apachectl start   启动<br/>
/usr/sbin/apachectl stop   关闭<br/>

判断启动状态<br/>
netstat -tunl|grep ':80'<br/>
tail /var/log/httpd/error_log<br/>


18.3.5 MySQL数据库的启动与测试<br/>


18.4Apache服务器的进阶设置<br/>


18.5日志文件分析及PHP强化模块等软件说明<br/>


18.6建立SSL（HTTPs）网站<br/>


18.7安全性管理网页<br/>












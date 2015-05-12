ssh.md

常见的客户端软件有putty,securecrt,windows secure shell


SecureCRT中文显示乱码
来源：http://www.cnblogs.com/totozlj/archive/2012/09/01/2666804.html

环境：SecureCRT登陆REDHAT5.3 LINUX系统

问题：vi编辑器编辑文件时文件中的内容中文显示乱码，但是直接使用linux系统terminal打开此文件时中文显示正常，确诊问题出现在客户端即SecureCRT的显示问题

解决方法：

1、修改远程linux机器的配置 

[root@rhel ~]#vi /etc/sysconfig/i18n  

把LANG改成支持UTF-8的字符集 
如： LANG=”zh_CN.UTF-8″ 或者是 LANG=”en_US.UTF-8″  本文修改为后者

2、修改Secure CRT的Session Options

Options->Session Options->Appearance->Font->新宋体 字符集：中文GB2312 ->Character encoding 为UTF-8

3、OK.
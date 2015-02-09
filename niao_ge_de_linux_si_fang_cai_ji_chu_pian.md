###第十四章 Linux账号管理与ACL权限设定
1. 使用者标识符：UID与GID<br/>
使用者账号：便于记忆<br/>
UID，GID：一串数字编号，文件属性中存储的是UID，GID<br/>

/etc/passwd文件：保存账号信息，主键是账号<br/>
/etc/shadow文件：保存账号密码，主键是账号<br/>
/etc/group，/etc/gshadow文件：保存账号群组信息，主键是群组名<br/>

2. 使用者类型<br/>
超级用户：root<br/>
系统用户：bin，daemon，adm，nobody，系统用户是系统正常运行必须的，千万不能干掉<br/>
普通用户：<br/>

UID值分组<br/>
id范围     用户特性<br/>
0          系统管理员<br/>

除了0的UID，权限与特性一样<br/>
1~499      系统账号，保留账号，给特定服务使用<br/>
           1~99：由distributions创建<br/>
           100~499：由操作者创建<br/>
500~65535  可登录账号，给一般用户使用<br/>

2. 有效群组与初始群组<br/>
一个用户可以属于多个群组<br/>
初始群组：在/etc/passwd文件中的GID对应的群组<br/>

有效群组：在作业时，以那个为准的群组<br/>
          新建文件、目录的群组是有效群组<br/>
          groups列出的群组清单中，第一个是有效群组<br/>
          newgrp切换有效群组，会新起shell<br/>

3. 如何加入群组<br/>
系统管理员：usermod<br/>
群组管理员：gpasswd<br/>


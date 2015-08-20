CentOs图形界面的开启与关闭<br/>
from:http://http://yelb.iteye.com/blog/1047138<br/>

CentOS <br/>
CentOS关闭图形界面(x window)2010-06-18 18:211.在图像界面关闭x window: <br/>
1.1 shell中运行 init 3  进入文本模式,同时会关闭相关的服务(Xserver 肯定关闭)<br/> 
1.2 Alt+Ctrl+F1~F6到字符界面，root登陆，ps aux|grep /usr/X11R6/bin/X,得到X进程号，<br/> 
kill -9 进程号，其实这时已经到文本界面了，没必要关X。（这样太粗鲁了) <br/>

2.如果你想一开机后不进入X Window: <br/>
编辑/etc/inittab <br/>
id:5:initdefault:改成 <br/>
id:3:initdefault: <br/>

3.在文本模式打开图形界面（X window）: <br/>
在shell中输入：startx 或者 init 5 <br/>

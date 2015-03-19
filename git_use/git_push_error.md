####github push错误403

github push错误：<br/>
The requested URL returned error:403 Forbidden while accessing https://github.com/yourname/yourgit/info/refs<br/>

OS:CentOS<br/>

解决方案：<br/>
vim .git/config

修改<br/>
[remote "origin"]
url=https://github.com/yourname/yourgit.git<br/>
为
[remote "origin"]
url=https://yourname@github.com/yourname/yourgit.git<br/>

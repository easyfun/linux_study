==程序中跳转ctags
命令行窗口ctags -R生成符号数据库文件

ctags -R --c++-kinds=+p --fields=+iaS --extra=+q file_path
--c++-kinds=+p  : 为C++文件增加函数原型的标签
--fields=+iaS   : 在标签文件中加入继承信息(i)、类成员的访问控制信息(a)、以及函数的指纹(S)
--extra=+q      : 为标签增加类修饰符。注意，如果没有此选项，将不能对类成员补全

CTRL+]        自动跳转到函数的定义部分，
CTRL+T        返回

==源码分析工具taglist
:Tlist        显示TagList窗口
再输入:Tlist   关闭TagList窗口

==文件浏览组件WinManager
:WMToggle     打开/关闭FileExplorer(TagList)窗口

==多文档编辑minibufexpl
ctrl+Tab         切换到前一个buffer，并在当前窗口打开文件
ctrl+shift+Tab   切换到后一个buffer，并在当前窗口打开文件
ctrl+箭头键      可以切换到上下左右窗口中
ctrl+h,j,k,l，   切换到上下左右的窗口中

==在工程中快速查找grep
:Grep            打开查找窗口

==h\c切换（针对C、C++）a.vim
:A               切换h,c/cpp文件

==高亮书签
ctrl+F2          增加/取消标签
F2               在书签之间正向切换
shift+F2         反向切换

==自动补全OminiCppComplete.vim
常用
自动补全          Ctrl+X Ctrl+O

当自动补全下拉窗口弹出后，一些可用的快捷键:
Ctrl+P  向前切换成员
Ctrl+N  向后切换成员
Ctrl+E  表示退出下拉窗口, 并退回到原来录入的文字
Ctrl+Y  表示退出下拉窗口, 并接受当前选项

其他补全方式:
整行补全                        CTRL-X CTRL-L
根据当前文件里关键字补全        CTRL-X CTRL-N
根据字典补全                    CTRL-X CTRL-K
根据同义词字典补全              CTRL-X CTRL-T
根据头文件内关键字补全          CTRL-X CTRL-I
根据标签补全                    CTRL-X CTRL-]
补全文件名                      CTRL-X CTRL-F
补全宏定义                      CTRL-X CTRL-D
补全vim命令                     CTRL-X CTRL-V
用户自定义补全方式              CTRL-X CTRL-U
拼写建议                        CTRL-X CTRL-S 

==提示函数原型echofunc
函数名后输入一个"("的时候, 这个函数的声明就会自动显示在命令行中。如果这个函数有多个声明, 则可以通过按键"Alt+-"和"Alt+="向前和向后翻页
注意：需要tags文件的支持, 并且在创建tags文件的时候要加选项"--fields=+lS"
在编译vim时加上了"+balloon_eval"特性，那么当你把鼠标放在函数名上的时候会有一个tip窗口弹出, 该窗口中也会有函数的声明



"去掉有关vi一致性模式，避免以前版本的bug和局限
set nocompatible

"显示行号
set number

"检测文件的类型
filetype on

"记录历史的行数
set history=1000

"背景使用黑色
set background=dark

"语法高亮显示
syntax on

"下面两行在编写代码时，在格式对齐上很有用
"第一行，vim使用自动对齐
"第二行，依据上面的对齐格式，只能的选择对齐方式
set autoindent
set smartindent

"第一行设置tab健为4个空格，第二行设置当行之间交错时使用4个空格
set tabstop=4
set shiftwidth=4

"把tab转换成空格
set expandtab

"设置匹配模式，类似当输入一个左括号时会匹配相应的右括号
set showmatch

"去除vim的GUI版本中的toolbar
set guioptions=T

"当vim进行编辑时，如果命令错误，会发出响声，去掉错误报警
set vb t_vb=

"在编辑过程中，在右下角显示光标位置的状态行
set ruler

"默认情况下，寻找匹配是高亮度显示的，该设置关闭高亮显示
set nohls

"查询时非常方便，如要查找book单词，当输入到/b时，会自动找到第一
"个b开头的单词，当输入到/bo时，会自动找到第一个bo开头的单词，依
"次类推，进行查找时，使用此设置会快速找到答案，当你找要匹配的单词
"时，别忘记回车
set incsearch

"修改一个文件后，自动进行备份，备份的文件名为原文件名加“~“后缀
if has("vms") 
set nobackupd
else
set backup
endif





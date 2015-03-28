####设置
参考资料<br/>
[vim设置](http://iybk.blog.163.com/blog/static/19409510020117571224963)

家目录下修改配置文件.vimrc<br/>
"双引号开始的行为注释行，下同<br/>
"去掉有关vi一致性模式，避免以前版本的bug和局限<br/>
set nocompatible<br/>

"显示行号<br/>
set number<br/>

"检测文件的类型<br/>
filetype on<br/>

"记录历史的行数<br/>
set history=1000<br/>

"背景使用黑色<br/>
set background=dark<br/>

"语法高亮显示<br/>
syntax on<br/>

"下面两行在编写代码时，在格式对齐上很有用<br/>
"第一行，vim使用自动对齐<br/>
"第二行，依据上面的对齐格式，只能的选择对齐方式<br/>
set autoindent<br/>
set smartindent<br/>

"第一行设置tab健为4个空格，第二行设置当行之间交错时使用4个空格<br/>
set tabstop=4<br/>
set shiftwidth=4<br/>

"设置匹配模式，类似当输入一个左括号时会匹配相应的右括号"<br/>
set showmatch<br/>

"去除vim的GUI版本中的toolbar"<br/>
set guioptions=T<br/>

"当vim进行编辑时，如果命令错误，会发出响声，去掉错误报警"<br/>
set vb t_vb=<br/>

"在编辑过程中，在右下角显示光标位置的状态行<br/>
set ruler<br/>

"默认情况下，寻找匹配是高亮度显示的，该设置关闭高亮显示<br/>
set nohls<br/>

"查询时非常方便，如要查找book单词，当输入到/b时，会自动找到第一<br/>
"个b开头的单词，当输入到/bo时，会自动找到第一个bo开头的单词，依<br/>
"次类推，进行查找时，使用此设置会快速找到答案，当你找要匹配的单词<br/>
"时，别忘记回车<br/>
set incsearch<br/>

"修改一个文件后，自动进行备份，备份的文件名为原文件名加~后缀<br/>
   
   if has("vms") //注意双引号要用半角的引号
   set nobackup
   else
   set backup
   endif





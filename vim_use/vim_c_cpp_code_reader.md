----------------------------------------------------------------------------------------
Vim-Ctags-Taglist阅读C/C++代码之(一)—Ctags (2008-10-23 21:59:14)
----------------------------------------------------------------------------------------
来源:http://blog.sina.com.cn/s/blog_700e74120100lmsj.html

    很多Linux/Unix程序员都希望能拥有Source Insight那样的杀手级的工具，能在代码之间无拘无束、来去自如。但是Source Insight只能用于Windows平台，而且价格也不菲。当然，我们会去找一些替代案，虽然功能无法超越Source Insight，但是够用就好，不是吗？Ctags就是一个很好的借助标签信息来实现代码跳转和补全的一个很好的选择。

1.在源码根目录下执行ctags --sort=yes -R
会在当前目录下生成一个名为tags的tagfile。
如果不加--sort=yes,生成的文件头中也显示是sorted的(不知道是不是个bug，可能只在某些版本有吧)，但是有时vim会提示tagsfile unsorted，查找会变慢。因为对于sorted tagfile，vim会使用二分查找法；对于unsorted tagfile，vim会使用线性查找法。而且有时错误会影响你的使用，通过set notagbsearch可以关闭错误提示，但vim将总是用线性查找法。

2.vi -t $tag启动vim并自动定位到tag的定义处。如果不是在tagfile所在目录下打开vim，需在vim启动后设置set tags=path/tagfile。
这样你就可以用CTRL+]定位tag的定义，用CTRL+T来返回，用tag $tag定位到特定tag。
在编写代码的时调用CTRL+P、CTRL+N也会自动搜索tag信息来进行补齐。

3.如果有鼠标的话，设置
set mouse=a
set scroll=5
会较好用些。
可用CRTL+left click来代替CTRL+]
可用g+right click来代替CTRL+T

4.如时标签有多个匹配，会显示tag i of N，可用:tfirst跳转到第一个匹配，:tlast跳转到最后一个匹配，:tprevious跳转到前一个匹配，:tnext跳转到下一个匹配，:tselect选择要跳转的匹配。

5.其它
用tag $tag+n次TAB进行tag的自动补齐来(别忘了在.vimrc中设置set wildmenu)定位到特定tag。set ignorecase会可能会影响到tag定位的结果。tags会显示tag堆栈的历史记录。

6.常用命令助记
ta[g] $tag+TAB
tf[irst]
tr[ewind]与tfirst等价
tl[ast]
number+tp[revious]
number+tn[ext]
number+tN[ext]与tprevious等价
ts[elect] $tag
tj[ump] $tag与tselect相似，但当只有一个匹配时，直接跳转到定义。
sts[elect] $tag与tselect相似，但是会在新建水平分割窗口是显示所选的tag的定义。
stj[ump] $tag是tj与sts相结合的产物

g CTRL+] 与tjump等价

下面这些命令与上面类似，但是都是在预览(preview)窗口中显示tag定义。
pt[ag] $tag+TAB
ptf[irst]
ptr[ewind]与ptfirst等价
ptl[ast]
number+ptp[revious]
number+ptn[ext]
number+ptN[ext]


----------------------------------------------------------------------------------------
Vim-Ctags-Taglist阅读C/C++代码之(二)—Tag预览 (2008-10-24 22:00:46)
----------------------------------------------------------------------------------------

    在使用Ctags生成的标签信息阅读代码的时候，可以在你的.vimrc中加入如下脚本来实现将当前光标下的标的签定义自动显示在预览窗口中。

set updatetime=50

"setup for ctags auto-cursor-preview
au! CursorHold *.[ch] nested call PreviewWord()

func PreviewWord()
  if &previewwindow                     " don't do this in the preview window
    return
  endif

  let w = expand("<cword>")             " get the word under cursor

  if w =~ '\a'                          " if the word contains a letter 
    " Delete any existing highlight before showing another tag
    silent! wincmd P                    " jump to preview window
    if &previewwindow                   " if we really get there...
      match none                        " delete existing highlight
      wincmd p                          " back to old window
    endif
    " Try displaying a matching tag for the word under the cursor
    try
      exe "ptag " . w
    catch
      return
    endtry

    silent! wincmd P                    " jump to preview window
    if &previewwindow                   " if we really get there...
      if has("folding")
        silent! .foldopen               " don't want a closed fold
      endif
      call search("$", "b")             " to end of previous line
      let w = substitute(w, '\\', '\\\\', "")
      call search('\<\V' . w . '\>')    " position cursor on match
      " Add a match highlight to the word at this position
      hi previewWord term=bold ctermbg=green guibg=green
      exe 'match previewWord "\%' . line(".") . 'l\%' . col(".") . 'c\k*"'
      wincmd p                          " back to old window
    endif
  endif
endfun



----------------------------------------------------------------------------------------
Vim-Ctags-Taglist阅读C/C++代码之(三)—Taglist [此博文包含图片] (2008-10-25 22:00:46)
----------------------------------------------------------------------------------------
来自：http://blog.sina.com.cn/s/blog_700e74120100lmsq.html 

    想不想一侧显示变量或函数列表，另一侧显示源代码窗口，Taglist可以帮你实现这点。

1.下载taglist.zip并解压到 $HOME/.vim，会产生以下两个目录：
  plugin/taglist.vim - main taglist plugin file
  doc/taglist.txt    - documentation (help) file

2.确保.vimrc文件中开启了：  filetype on

2.切换到 $HOME/.vim/doc，启动Vim并执行":helptags ."命令来产生taglist的帮助文件，没有这一步，你在VIM中就无法查看taglist的帮助。

3.使用":Tlist[Toggle]" 命令开启与关闭taglist窗口，使用TlistOpen和TlistClose来打开和关闭taglist窗口。

4.使用回车键或鼠标双击来浏览相应tag。用o在新窗口中打开标签，用p在预览窗口打开标签使鼠标仍留在taglist窗口。

5.为方便使用，在.vimrc中作如下设置：
let Tlist_Compact_Format=1          “使用紧凑模式显示标签，不会添加空行
let Tlist_Display_Prototype=1       “显示标签原型，而不仅是名字
let Tlist_File_Fold_Auto_Close=1  ”自动折叠不活动的文件或buffer的标签

下面这张效果图来自Taglist官方网站的Screenshot。



----------------------------------------------------------------------------------------
Vim-Ctags-Taglist阅读C/C++代码之(四)—快速打开工作空间 (2008-10-31 22:00:37)
----------------------------------------------------------------------------------------
来自:http://blog.sina.com.cn/s/blog_700e74120100lmso.html

    很不幸，Ctags的auto-cursor-preview脚本并不能和Taglist很好的在一起工作。它们都借助于updatetime来更新信息，有时它们会出现窗口的错乱。所以我常会在两种模式下工作。

    我会在$HOME目录下建立一个文件夹来管理我的工作空间(估且这么叫吧)，不妨叫viworkspace。我通常会这样组织我的工程，假定我的源码在.../src/目录下，我会在~/viworkspace/下建立一个符号链接src指向实际的源码目录.../src/。然后我在~/viworkspace/目录下运行ctags -R *，会在当前目录生成一个tags文件。然后我会在以下两种模式下工作：

第一种就是auto-cursor-preview模式

我在~/viworkspace/创建一个叫workspace1的文件，其内容为如下的vi脚本：
"********************************************************
set updatetime=50               "预览窗更新间隔

set tags=~/viworkspace/tags "设置tags文件
cd ~/viworkspace/src             "进入到源码目录
edit .                                  "用netrw打开当前目录

"设置自动预览
au! CursorHold *.[ch] nested call PreviewWord()

func PreviewWord()
  if &previewwindow                     " don't do this in the preview window
    return
  endif

  let w = expand("<cword>")             " get the word under cursor

  if w =~ '\a'                          " if the word contains a letter 
    " Delete any existing highlight before showing another tag
    silent! wincmd P                    " jump to preview window
    if &previewwindow                   " if we really get there...
      match none                        " delete existing highlight
      wincmd p                          " back to old window
    endif
    " Try displaying a matching tag for the word under the cursor
    try
      exe "ptag " . w
    catch
      return
    endtry

    silent! wincmd P                    " jump to preview window
    if &previewwindow                   " if we really get there...
      if has("folding")
        silent! .foldopen               " don't want a closed fold
      endif
      call search("$", "b")             " to end of previous line
      let w = substitute(w, '\\', '\\\\', "")
      call search('\<\V' . w . '\>')    " position cursor on match
      " Add a match highlight to the word at this position
      hi previewWord term=bold ctermbg=green guibg=green
      exe 'match previewWord "\%' . line(".") . 'l\%' . col(".") . 'c\k*"'
      wincmd p                          " back to old window
    endif
  endif
endfun
"********************************************************

 

第二种就是Taglist模式

"********************************************************
set updatetime=50                    "设置标签窗口更新间隔

let Tlist_Compact_Format=1       "设置标签列表为紧凑模式，去掉多余空行
"let Tlist_Display_Prototype=1    "设置标签列表为原型模式
let Tlist_File_Fold_Auto_Close=1 "设置不活动文件，自动折叠标签列表，仅显示当前文件列表

TlistToggle                               "开启Taglist列表

set tags=~/viworkspace/tags "设置tags文件
cd ~/viworkspace/src             "进入到源码目录
edit .                                  "用netrw打开当前目录
"********************************************************

最后，在.vimrc中添加键盘映射。

"********************************************************
map <F2> :source ~/viworkspace/workspace1<CR>
imap <F2> <ESC>:source ~/viworkspace/workspace1<CR>
map <F3> :source ~/viworkspace/workspace2<CR>
imap <F3> <ESC>:source ~/viworkspace/workspace2<CR>
"********************************************************

    这样，只要以后启动了vim，按下<F2>就会自动进入源码目录，用netrw打开文件列表，并进入auto-cursor-preview模式。同理，按下<F3>就会自动进入源码目录，用netrw打开文件列表，并进入Taglist模式。在这两种模式下，只要在文件列表中选择要打开的文件，并按回车，就可以开始代码之旅了。



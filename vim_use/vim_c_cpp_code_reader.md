----------------------------------------------------------------------------------------
Vim-Ctags-Taglist�Ķ�C/C++����֮(һ)��Ctags (2008-10-23 21:59:14)
----------------------------------------------------------------------------------------
��Դ:http://blog.sina.com.cn/s/blog_700e74120100lmsj.html

    �ܶ�Linux/Unix����Ա��ϣ����ӵ��Source Insight������ɱ�ּ��Ĺ��ߣ����ڴ���֮���޾���������ȥ���硣����Source Insightֻ������Windowsƽ̨�����Ҽ۸�Ҳ���ơ���Ȼ�����ǻ�ȥ��һЩ���������Ȼ�����޷���ԽSource Insight�����ǹ��þͺã�������Ctags����һ���ܺõĽ�����ǩ��Ϣ��ʵ�ִ�����ת�Ͳ�ȫ��һ���ܺõ�ѡ��

1.��Դ���Ŀ¼��ִ��ctags --sort=yes -R
���ڵ�ǰĿ¼������һ����Ϊtags��tagfile��
�������--sort=yes,���ɵ��ļ�ͷ��Ҳ��ʾ��sorted��(��֪���ǲ��Ǹ�bug������ֻ��ĳЩ�汾�а�)��������ʱvim����ʾtagsfile unsorted�����һ��������Ϊ����sorted tagfile��vim��ʹ�ö��ֲ��ҷ�������unsorted tagfile��vim��ʹ�����Բ��ҷ���������ʱ�����Ӱ�����ʹ�ã�ͨ��set notagbsearch���Թرմ�����ʾ����vim�����������Բ��ҷ���

2.vi -t $tag����vim���Զ���λ��tag�Ķ��崦�����������tagfile����Ŀ¼�´�vim������vim����������set tags=path/tagfile��
������Ϳ�����CTRL+]��λtag�Ķ��壬��CTRL+T�����أ���tag $tag��λ���ض�tag��
�ڱ�д�����ʱ����CTRL+P��CTRL+NҲ���Զ�����tag��Ϣ�����в��롣

3.��������Ļ�������
set mouse=a
set scroll=5
��Ϻ���Щ��
����CRTL+left click������CTRL+]
����g+right click������CTRL+T

4.��ʱ��ǩ�ж��ƥ�䣬����ʾtag i of N������:tfirst��ת����һ��ƥ�䣬:tlast��ת�����һ��ƥ�䣬:tprevious��ת��ǰһ��ƥ�䣬:tnext��ת����һ��ƥ�䣬:tselectѡ��Ҫ��ת��ƥ�䡣

5.����
��tag $tag+n��TAB����tag���Զ�������(��������.vimrc������set wildmenu)��λ���ض�tag��set ignorecase����ܻ�Ӱ�쵽tag��λ�Ľ����tags����ʾtag��ջ����ʷ��¼��

6.������������
ta[g] $tag+TAB
tf[irst]
tr[ewind]��tfirst�ȼ�
tl[ast]
number+tp[revious]
number+tn[ext]
number+tN[ext]��tprevious�ȼ�
ts[elect] $tag
tj[ump] $tag��tselect���ƣ�����ֻ��һ��ƥ��ʱ��ֱ����ת�����塣
sts[elect] $tag��tselect���ƣ����ǻ����½�ˮƽ�ָ������ʾ��ѡ��tag�Ķ��塣
stj[ump] $tag��tj��sts���ϵĲ���

g CTRL+] ��tjump�ȼ�

������Щ�������������ƣ����Ƕ�����Ԥ��(preview)��������ʾtag���塣
pt[ag] $tag+TAB
ptf[irst]
ptr[ewind]��ptfirst�ȼ�
ptl[ast]
number+ptp[revious]
number+ptn[ext]
number+ptN[ext]


----------------------------------------------------------------------------------------
Vim-Ctags-Taglist�Ķ�C/C++����֮(��)��TagԤ�� (2008-10-24 22:00:46)
----------------------------------------------------------------------------------------

    ��ʹ��Ctags���ɵı�ǩ��Ϣ�Ķ������ʱ�򣬿��������.vimrc�м������½ű���ʵ�ֽ���ǰ����µı��ǩ�����Զ���ʾ��Ԥ�������С�

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
Vim-Ctags-Taglist�Ķ�C/C++����֮(��)��Taglist [�˲��İ���ͼƬ] (2008-10-25 22:00:46)
----------------------------------------------------------------------------------------
���ԣ�http://blog.sina.com.cn/s/blog_700e74120100lmsq.html 

    �벻��һ����ʾ���������б���һ����ʾԴ���봰�ڣ�Taglist���԰���ʵ����㡣

1.����taglist.zip����ѹ�� $HOME/.vim���������������Ŀ¼��
  plugin/taglist.vim - main taglist plugin file
  doc/taglist.txt    - documentation (help) file

2.ȷ��.vimrc�ļ��п����ˣ�  filetype on

2.�л��� $HOME/.vim/doc������Vim��ִ��":helptags ."����������taglist�İ����ļ���û����һ��������VIM�о��޷��鿴taglist�İ�����

3.ʹ��":Tlist[Toggle]" �������ر�taglist���ڣ�ʹ��TlistOpen��TlistClose���򿪺͹ر�taglist���ڡ�

4.ʹ�ûس��������˫���������Ӧtag����o���´����д򿪱�ǩ����p��Ԥ�����ڴ򿪱�ǩʹ���������taglist���ڡ�

5.Ϊ����ʹ�ã���.vimrc�����������ã�
let Tlist_Compact_Format=1          ��ʹ�ý���ģʽ��ʾ��ǩ��������ӿ���
let Tlist_Display_Prototype=1       ����ʾ��ǩԭ�ͣ�������������
let Tlist_File_Fold_Auto_Close=1  ���Զ��۵�������ļ���buffer�ı�ǩ

��������Ч��ͼ����Taglist�ٷ���վ��Screenshot��



----------------------------------------------------------------------------------------
Vim-Ctags-Taglist�Ķ�C/C++����֮(��)�����ٴ򿪹����ռ� (2008-10-31 22:00:37)
----------------------------------------------------------------------------------------
����:http://blog.sina.com.cn/s/blog_700e74120100lmso.html

    �ܲ��ң�Ctags��auto-cursor-preview�ű������ܺ�Taglist�ܺõ���һ���������Ƕ�������updatetime��������Ϣ����ʱ���ǻ���ִ��ڵĴ��ҡ������ҳ���������ģʽ�¹�����

    �һ���$HOMEĿ¼�½���һ���ļ����������ҵĹ����ռ�(������ô�а�)��������viworkspace����ͨ����������֯�ҵĹ��̣��ٶ��ҵ�Դ����.../src/Ŀ¼�£��һ���~/viworkspace/�½���һ����������srcָ��ʵ�ʵ�Դ��Ŀ¼.../src/��Ȼ������~/viworkspace/Ŀ¼������ctags -R *�����ڵ�ǰĿ¼����һ��tags�ļ���Ȼ���һ�����������ģʽ�¹�����

��һ�־���auto-cursor-previewģʽ

����~/viworkspace/����һ����workspace1���ļ���������Ϊ���µ�vi�ű���
"********************************************************
set updatetime=50               "Ԥ�������¼��

set tags=~/viworkspace/tags "����tags�ļ�
cd ~/viworkspace/src             "���뵽Դ��Ŀ¼
edit .                                  "��netrw�򿪵�ǰĿ¼

"�����Զ�Ԥ��
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

 

�ڶ��־���Taglistģʽ

"********************************************************
set updatetime=50                    "���ñ�ǩ���ڸ��¼��

let Tlist_Compact_Format=1       "���ñ�ǩ�б�Ϊ����ģʽ��ȥ���������
"let Tlist_Display_Prototype=1    "���ñ�ǩ�б�Ϊԭ��ģʽ
let Tlist_File_Fold_Auto_Close=1 "���ò���ļ����Զ��۵���ǩ�б�����ʾ��ǰ�ļ��б�

TlistToggle                               "����Taglist�б�

set tags=~/viworkspace/tags "����tags�ļ�
cd ~/viworkspace/src             "���뵽Դ��Ŀ¼
edit .                                  "��netrw�򿪵�ǰĿ¼
"********************************************************

�����.vimrc����Ӽ���ӳ�䡣

"********************************************************
map <F2> :source ~/viworkspace/workspace1<CR>
imap <F2> <ESC>:source ~/viworkspace/workspace1<CR>
map <F3> :source ~/viworkspace/workspace2<CR>
imap <F3> <ESC>:source ~/viworkspace/workspace2<CR>
"********************************************************

    ������ֻҪ�Ժ�������vim������<F2>�ͻ��Զ�����Դ��Ŀ¼����netrw���ļ��б�������auto-cursor-previewģʽ��ͬ������<F3>�ͻ��Զ�����Դ��Ŀ¼����netrw���ļ��б�������Taglistģʽ����������ģʽ�£�ֻҪ���ļ��б���ѡ��Ҫ�򿪵��ļ��������س����Ϳ��Կ�ʼ����֮���ˡ�



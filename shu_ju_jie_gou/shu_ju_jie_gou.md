数据结构——C语言版

#第9章 查找树

#9.1 静态查找表
    顺序查找
    二分查找（拆半查找）
        唯一二叉判定树

#9.2 动态查找表
#9.2.1 二叉排序树和平衡二叉树
    二叉排序树——二叉查找树，形态不是唯一的

#9.2.2 B-树和B+树
    B-树和B+树，结点包含的关键字数不仅仅只有一个。

    B-树：是一种平衡多路查找树，在文件系统，数据库中应用广泛

    B+树：是B-树的变型树
        B+树的查找不论成功还是失败，都是从根到叶子结点。
        B+树的查找类似B-树。
        B+树的插入仅在叶子结点上进行。
        B+树的删除仅在叶子结点上进行。
        B+树不是严格意义定义的树。

#9.2.3 键树



#第10章 内部排序
排序的功能：将无序序列变成有序序列，可以加块查找
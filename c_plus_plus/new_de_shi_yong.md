####new/delete操作符的使用

####new操作符
1.参数：类型，内置的基本类型，自定义的类类型<br/>
2.返回值：成功返回指向指定类型的指针；失败，NULL或者抛出异常<br/>

在堆上分配空间<br/>
对于类类型，会自动调用构造函数<br/>


申请数组的用法<br/>
    new type[const];

####delete操作符

标准使用方法<br/>
    delete point;
    point=0;

    delete []point_array;
    point_array=0;

避免指针变成悬垂指针（迷途指针，失控指针）<br/>
    delete point;
    //point=0;  
    //没有这个操作,我们仍然可以通过point引用之前的内存，
    //该段内存极有可能已经分配它用，用point继续操作此内存很危险，不崩溃改变程序的执行状态，恒崩溃利于查错
    

####注意
1.new来的内存，不用时一定要用delete释放，避免内存泄漏<br/>
2.delete一段已经释放的内存，结果未知，可能会导致抛出异常;delete空指针是安全的<br/>
3.delete非new返回的指针，会导致抛出异常<br/>

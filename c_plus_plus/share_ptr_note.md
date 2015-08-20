 学习笔记：shared_ptr陷阱 (2011-10-10 23:31:21)<br/>
 来源：http://blog.sina.com.cn/s/blog_62b4e3ff0100v1tc.html<br/>

条款1：不要把一个原生指针给多个shared_ptr管理<br/>
int* ptr = new int;<br/>
shared_ptr<int> p1(ptr);<br/>
shared_ptr<int> p2(ptr); //logic error<br/>
ptr对象被删除了2次<br/>
这种问题比喻成“二龙治水”，在原生指针中也同样可能发生。<br/>

条款2：不要把this指针给shared_ptr<br/>
class Test{<br/>
public:<br/>
    void Do(){  m_sp =  shared_ptr<Test>(this);  }<br/>
private:<br/>
    shared_ptr<Test> m_member_sp;<br/>
};<br/>

Test* t = new Test;<br/>
shared_ptr<Test> local_sp(t);<br/>
p->Do();<br/>

发生什么事呢，t对象被删除了2次！<br/>
t对象给了local_sp管理，然后在m_sp =  shared_ptr<Test>(this)这句里又请了一尊神来管理t。<br/>
这就发生了条款1里“二龙治水”错误。<br/>

条款3：shared_ptr作为被保护的对象的成员时，小心因循环引用造成无法释放资源。<br/>

对象需要相互协作，对象A需要知道对象B的地址，这样才能给对象B发消息（或调用其方法）。<br/>
设计模式中有大量例子，一个对象中有其他对象的指针。现在把原生指针替换为shared_ptr.<br/>

假设a对象中含有一个shared_ptr<B>指向b对象；假设b对象中含有一个shared_ptr<A>指向a对象<br/>
并且a，b对象都是堆中分配的。很轻易就能与他们失去最后联系。<br/>
考虑某个shared_ptr<A> local_a;是我们能最后一个看到a对象的共享智能指针，其use_count==2,<br/>
因为对象b中持有a的指针。所以当local_a说再见时，local_a只是把a对象的use_count改成1。<br/>
同理b对象。然后我们再也看不到a,b的影子了，他们就静静的躺在堆里，成为断线的风筝。<br/>

解决方案是：Use weak_ptr to "break cycles."（boost文档里写的）或者显示的清理<br/>

条款4：不要在函数实参里创建shared_ptr<br/>

function ( shared_ptr<int>(new int), g( ) );  //有缺陷<br/>
可能的过程是先new int，然后调g( )，g( )发生异常，shared_ptr<int>没有创建，int内存泄露<br/>

shared_ptr<int> p(new int());<br/>
f(p, g());  //Boost推荐写法<br/>

条款5：对象内部生成shared_ptr<br/>

前面说过，不能把this指针直接扔给shared_ptr. 但是没有禁止在对象内部生成自己的shared_ptr<br/>

//这是Boost的例子改的。<br/>
class Y: public boost::enable_shared_from_this<Y><br/>
{<br/>
    boost::shared_ptr<Y> GetSelf()<br/>
    {<br/>
        return shared_from_this();<br/>
    }<br/>
};<br/>

原理是这样的。普通的（没有继承enable_shared_from_this）类T的shared_ptr<T> p(new T).<br/>
p作为栈对象占8个字节，为了记录（new T）对象的引用计数，p会在堆上分配16个字节以保存<br/>
引用计数等“智能信息”。share_ptr没有“嵌入(intrusive)”到T对象，或者说T对象对share_ptr毫不知<br/>

情。Y对象则不同，Y对象已经被“嵌入”了一些share_ptr相关的信息，目的是为了找到“全局性”的<br/>
那16字节的本对象的“智能信息”。<br/>

原理说完了，就是陷阱<br/>
Y y;<br/>
boost::shared_ptr<Y> p=  y.GetSelf(); //无知的代码，y根本就不是new出来的<br/>

Y* y = new Y;<br/>
boost::shared_ptr<Y> p=  y->GetSelf(); //似是而非，仍旧程序崩盘。<br/>
Boost文档说，在调用shared_from_this()之前，必须存在一个正常途径创建的shared_ptr<br/>

boost::shared_ptr<Y> spy(new Y)<br/>
boost::shared_ptr<Y> p =  spy->GetSelf(); //OK<br/>

条款6 ：处理不是new的对象要小心。<br/>

int* pi = (int*)malloc(4)<br/>
shared_ptr<int> sp( pi ) ; //delete马嘴不对malloc驴头。<br/>

条款7：多线程对引用计数的影响。<br/>

如果是轻量级的锁，比如InterLockIncrement等，对程序影响不大<br/>
如果是重量级的锁，就要考虑因为share_ptr维护引用计数而造成的上下文切换开销。<br/>
1.33版本以后的shared_ptr对引用计数的操作使用的是Lock-Free（类似InterLockIncrement函数族）<br/>
的操作，应该效率不错，而且能保证线程安全（库必须保证其安全，程序员都没有干预这些隐藏事物的机会）。<br/>
Boost文档说read，write同时对shared_ptr操作时，行为不确定。这是因为shared_ptr本身有两个成员px，pi。<br/>
多线程同时对px读写是要出问题的。与一个int的全局变量多线程读写会出问题的原因一样。<br/>

条款8：对象数组用shared_array<br/>

int* pint = new int[100];<br/>
shared_array<int> p (pint );<br/>

既然shared_ptr对应着delete；显然需要一个delete[]对应物shared_array<br/>

条款9：学会用删除器<br/>

struct Test_Deleter<br/>
{   <br/>
    void  operator ()( Test* p){   ::free(p);   }<br/>
};<br/>
Test* t = (Test*)malloc(sizeof(Test));<br/>
new (t) Test;<br/>

shared_ptr<Test> sp( t ,  Test_Deleter() ); //删除器可以改变share_ptr销毁对象行为<br/>

有了删除器，shared_array无用武之地了。<br/>
template<class T><br/>
struct Array_Deleter<br/>
{   <br/>
    void  operator ()( T*){   delete[] p;   }<br/>
};<br/>
int* pint = new int[100];<br/>
shared_ptr<int> p (pint, Array_Deleter<int>() );<br/>

条款10：学会用分配器<br/>

存放引用计数的地方是堆内存，需要16-20字节的开销。<br/>
如果大量使用shared_ptr会造成大量内存碎片。<br/>
shared_ptr构造函数的第3个参数是分配器，可以解决这个问题。<br/>

shared_ptr<Test> p( (new Test), Test_Deleter(), Mallocator<Test>() );<br/>
注意删除器Test_Deleter是针对Test类的。分配器是针对shared_ptr内部数据的。<br/>

Mallocator<Test>()是个临时对象（无状态的），符合STL分配器规约。<br/>

template <typename T> <br/>
class Mallocator { <br/>
    //略。。。。。。<br/>
    T * allocate(const size_t n) const {<br/>
        return singleton_pool<T,sizeof(T)>::malloc();<br/>
    }<br/>
    //略。。。。。。<br/>

Mallocator传入Test，实际分配的类型确是<br/>
class boost::detail::sp_counted_impl_pda<class Test *,
                                         struct Test_Deleter,
                                         class Mallocator<class Test> >
这是用typeid(T).name()打印出来的。可能和rebind相关。<br/>

条款11 weak_ptr在使用前需要检查合法性。<br/>
weak_ptr<K> wp;<br/>
{<br/>
shared_ptr<K>  sp(new K);  //sp.use_count()==1<br/>
wp = sp; //wp不会改变引用计数，所以sp.use_count()==1<br/>
shared_ptr<K> sp_ok = wp.lock(); //wp没有重载->操作符。只能这样取所指向的对象<br/>
}<br/>
shared_ptr<K> sp_null = wp.lock(); //sp_null .use_count()==0;<br/>
因为上述代码中sp和sp_ok离开了作用域，其容纳的K对象已经被释放了。<br/>
得到了一个容纳NULL指针的sp_null对象。在使用wp前需要调用wp.expired()函数判断一下。<br/>
因为wp还仍旧存在，虽然引用计数等于0，仍有某处“全局”性的存储块保存着这个计数信息。<br/>
直到最后一个weak_ptr对象被析构，这块“堆”存储块才能被回收。否则weak_ptr无法直到自己<br/>
所容纳的那个指针资源的当前状态。<br/>

条款12 不要new shared_ptr<T><br/>

本来shared_ptr就是为了管理指针资源的，不要又引入一个需要管理的指针资源shared_ptr<T>*<br/>

条款13  尽量不要get<br/>

class B{...};<br/>
class D : public B{ ...};  //继承层次关系<br/>

shared_ptr<B> sp (new D);    //通过隐式转换，储存D的指针。<br/>
B* b = sp.get();             //shared_ptr辛辛苦苦隐藏的原生指针就这么被刨出来了。<br/>
D* d = dynamic_cast<D*>(b);  //这是使用get的正当理由吗？<br/>

正确的做法<br/>
shared_ptr<B> spb (new D)  ;<br/>
shared_ptr<D> spd = shared_dynamic_cast<D>(spb); //变成子类的指针<br/>
shared_ptr在竭尽全力表演的像一个原生指针，原生指针能干的事，它也基本上能干。<br/>

另一个同get相关的错误<br/>
shared_ptr<T> sp(new T);<br/>
shared_ptr<T> sp2( sp.get() ) ;//又一个“二龙治水”实例，指针会删2次而错误。<br/>

条款14 不要memcpy shared_ptr<br/>

shared_ptr<B> sp1 (new B)  ;<br/>
shared_ptr<B> sp2;<br/>
memcpy(&sp2,&sp1,sizeof(shared_ptr<B>)); //sp2.use_count()==1<br/>
很显然，不是通过正常途径（拷贝构造，赋值运算），引用计数是不会正确增长的。<br/>

条款15 使用BOOST预定义的宏去改变shared_ptr行为。<br/>

shared_ptr行为由类似BOOST_SP_DISABLE_THREADS这样的宏控制。需要去学习他们到底是干什么的。<br/>
大师Andrei Alexandrescu设计了一种基于模板策略设计模式的智能指针，通过几个模板参数去定制化<br/>
智能指针的行为。Boost却不以为然，官方解释是：需要统一的接口，这样利于大规模书写。<br/>
smart_ptr<T,OwnershipPolicy,ConversionPolicy,CheckingPolicy,StoragePolicy> sp(new T);<br/>
上述接口缺点是外形复杂，看上去像个大花脸。优点是客户程序员可以轻易的定制行为。<br/>

条款17 构造函数里调用shared_from_this抛例外<br/>

class Holder:public enable_shared_from_this<Holder>{<br/>
public:<br/>
    Holder() {<br/>
        shared_ptr<Holder> sp = shared_from_this();<br/>
        int x = sp.use_count();<br/>
    }<br/>
};<br/>
同前面条款5，不符合enable_shared_from_this使用前提。<br/>

总结：<br/>
学习了一天就总结出10多条条款，长期研究一下恐怕就出现条款100了。为什么还要使用shared_ptr呢？<br/>
有很多开源库用shared_ptr，而且shared_ptr具有“传染性”（某网友语：像毒品沾上就甩不掉），<br/>
抛开它就会有更严重的多龙治水现象。shared_ptr作为原生指针的替代品，能解决一定的内存泄露问题。<br/>
实际上初学原生指针时，每个人都遇到过野指针，删两次，忘记删除等问题。学习shared_ptr也会遇到。<br/>
shared_ptr的确能改善上述问题，并不能完全解决问题。shared_ptr可能在将来占主流，它最可能号令江湖，<br/>
否则一大堆auto_ptr,weak_ptr,原生指针，scoped_ptr共存就把人搞糊涂了。<br/>
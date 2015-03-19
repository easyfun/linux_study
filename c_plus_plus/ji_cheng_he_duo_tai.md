####继承和多态

####两类关系
has-a关系，通过成员数据描述<br/>
is-a关系，泛化/具体化，通过继承/派生描述<br/>

####三种访问属性
public，任何地方都可以访问<br/>
private，只有自己的成员方法能访问<br/>
protected，只有自己和子类可以访问<br/>

####继承
继承的意思自动获得。子类继承父类的所有特点，即子类自动获得父类的所有特点。<br/>
class 派生类名:[继承方式]基类名
{
  派生类成员数据
  派生类成员函数
};
继承方式不写，表示私有继承

struct 派生类名:[继承方式]基类名
{
  派生类成员数据
  派生类成员函数
};
继承方式不写，表示公有继承

####三种派生方式
public派生<br/>
private派生<br/>
protected派生<br/>

####保护访问
派生类的继承关系<br/>
继承方式   派生类的继承关系<br/>
public     基类的public和protected成员被派生类继承后，保持原有状态<br/>
protected  基类的public和protected成员被派生类继承后，变成派生类的protected成员<br/>
private    基类的public和protected成员被派生类继承后，变成派生类的private成员<br/>

父类Mammal
class Mammal
{
public:
    Mammal();
    ~Mammal();

protected:
    int itsAge;
}

子类Dog公有派生<br/>
class Dog : public Mammal
{
public:
    Dog();
    ~Dog();

protected:
    int itsWeight;
}
Mammal的itsAge成员在Dog的访问属性是protected

子类Dog私有派生<br/>
class Dog : private Mammal
{
public:
    Dog();
    ~Dog();

protected:
    int itsWeight;
}
Mammal的itsAge成员在Dog的访问属性是private


子类Dog保护派生<br/>
class Dog : private Mammal
{
public:
    Dog();
    ~Dog();

protected:
    int itsWeight;
}
Mammal的itsAge成员在Dog的访问属性是protected

使用public和protected派生时，父类的protected成员在子类，子孙类中访问属性仍然是protected的<br/>


####覆盖基类函数
覆盖基类函数，在派生类中定义返回值，特征标与基类中一样，但是实现不同。<br/>

特征标，指函数原型中除返回类型外的内容，函数名，参数列表，[const关键字]

如果父类中某个函数重载，子类覆盖其中一个，其它几个会被隐藏<br/>
子类中定义同名的父类函数，但是不符合覆盖条件，并不会构成重载，也会隐藏父类定义的函数<br/>
被隐藏的基类的函数，可以通过基类名称显示调用<br/>

**应该**：<br/>
应该通过派生来扩展经过测试的类的功能<br/>
通过覆盖基类方法来改变派生类中某些函数的行为<br/>

**不应该**：<br/>
不要通过修改函数特征标来隐藏基类函数<br/>
别忘了const是特征标的组成部分<br/>
别忘了返回类型不是特征标的组成部分<br/>

####虚方法
在基类中将一个成员方法标记为virtual，在派生中重写，可以不必显式标记为virtual。显式标记为virtual，语义更直接。

**虚函数的工作原理**
创建派生对象时，首先调用基类的构造函数，接着调用派生类的构造函数。需要在类中跟踪虚方法。类包含虚指针vptr或v-pointer，指向虚函数表v-table。虚函数表的每条记录指向类的虚函数。在构造基类时，vptr指向基类的v-table，构造派生类时，添加派生类的成员部分，并调整vptr使其指向派生类的v-table。

利用基类指针，或者引用来完成动态调用，调用正确的虚函数。通过基类指针，不能调用派生类新定义的成员函数（普通，virtual都不能）。<br/>

**切除**
派生类对象赋值给基类对象，会发生切除，派生类对象自有部分切除，vptr也会调整成基类的v-table。<br/>

**创建虚拟析构函数**
类中任何一个函数是virtual，析构函数定义成vitrual<br/>
delete 基类指针;<br/>
析构函数是virtual，总能正确析构<br/>

**虚复制构造函数**
构造函数不能是virtual。<br/>
可以使用virtual clone函数。<br/>

**使用虚方法的代价**
使用v-table跟踪虚方法，v-table的维护会带来开销。<br/>

**应该**
打算从一个类派生出其他类时，应该在这个类中使用虚方法。<br/>
在任何一个方法为虚方法时，应将析构函数声明为虚函数。<br/>

**不应该**
不要将构造函数声明为虚函数。<br/>
不要试图通过派生类对象访问基类的私有数据。<br/>

**私有继承**
基类的方法不能在外部使用。<br/>

私有继承的优点：<br/>
可以访问基类的protected成员<br/>
可以覆盖（重写）基类virtual成员函数<br/>
缺点：<br/>
会带来性能问题（v-table维护）<br/>














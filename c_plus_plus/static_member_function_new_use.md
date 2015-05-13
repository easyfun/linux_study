static_member_function_new_use.md
####静态成员函数的替代方式
使用类的空指针，调用不访问普通成员的函数

class Person
{
public:
	Person();
	~Person();

public:
	int GetAge();
	int GetNum();
private:
	int m_iAge;
};

Person::Person()
{
	m_iAge=0;
}

Person::~Person()
{
	
}

int Person::GetAge()
{
	return m_iAge;
}

int Person::GetNum()
{
	int num=0;
	return num;
}

int main(int argc, char* argv[])
{
	Person* p=0;
	// ok
	cout<<"num="<<p->GetNum()<<endl;

	// dump
	cout<<"age="<<p->GetAge()<<endl;
	return 0;
}


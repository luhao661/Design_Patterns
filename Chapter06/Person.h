#ifndef PERSON_H
#define PERSON_H
 
#include <string>
#include <iostream>

//装饰模式：动态地给一个对象添加一些额外的职责，就增加功能来说，
//装饰模式比生成子类更为灵活。

//ConcreteComponent即Component
class Person
{
private:
	std::string name;
public:
	Person()
    {};

	Person(std::string name)
	{
		this->name=name;
	}

	virtual void Show()
	{
		std::cout<<"装饰的"<<name<<std::endl;
	}
};
 
#endif
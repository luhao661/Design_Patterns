#include <iostream>
#include <string>
 
//代理模式

//SchoolGirl类
class SchoolGirl
{
private:
	std::string name;
public:
	void setName(std::string name)
	{
		this->name=name;
	}
	std::string getName()
	{
		return name;
	}
};
 
//Subject类，定义了RealSubject和Proxy的共用接口，这样就可以在任何使用RealSubject的地方使用Proxy
class IGiveGift
{
public:
	virtual void GiveDolls()=0;
	virtual void GiveFlowers()=0;
	virtual void GiveChocolate()=0;
};
 
//RealSubject类，定义了Proxy所代表的真实实体
class Pursuit:public IGiveGift
{
private:
	SchoolGirl* mm;
public:
	Pursuit(SchoolGirl* mm)
	{
		this->mm=mm;
	}
	void GiveDolls()
	{
		std::cout<<mm->getName()<<"  送你洋娃娃"<<std::endl;
	}
	void GiveFlowers()
	{
		std::cout<<mm->getName()<<"  送你鲜花"<<std::endl;
	}
	void GiveChocolate()
	{
		std::cout<<mm->getName()<<"  送你巧克力"<<std::endl;
	}
};
 
//Proxy类，保存一个引用是的代理可以访问实体，并提供一个与Subject的接口相同的接口，这样代理就可以用来替代实体
class Proxy:public IGiveGift
{
private:
	Pursuit* gg;
public:
	Proxy(SchoolGirl* mm)
	{
		gg=new Pursuit(mm);
	}
	void GiveDolls()
	{
		gg->GiveDolls();
	}
	void GiveFlowers()
	{
		gg->GiveFlowers();
	}
	void GiveChocolate()
	{
		gg->GiveChocolate();
	}
};
 
 
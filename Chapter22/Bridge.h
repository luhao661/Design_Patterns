#ifndef BRIDGE_H
#define BRIDGE_H
 
#include <iostream>
 
//Implementor：此处为手机软件抽象类
class HandsetSoft
{
public:
	virtual void Run()=0;
};
 
//ConcreteImplementorA，此处为手机游戏
class HandsetGame:public HandsetSoft
{
	void Run()
	{
		std::cout<<"Run mobile games"<<std::endl;
	}
};
 
//ConcreteImplementorB，此处为手机通讯录
class HandsetAddressList:public HandsetSoft
{
	void Run()
	{
		std::cout<<"Run your phone address book"<<std::endl;
	}
};
 
//Abstraction，此处为手机品牌抽象类
class HandsetBrand
{
protected:
	HandsetSoft* soft;
public:
	void SetHandsetSoft(HandsetSoft* soft)
	{
		this->soft=soft;
	}
	virtual void Run()=0;
};
 
//RefineAbstraction，此处为手机品N
class HandsetBrandN:public HandsetBrand
{
public:
	void Run()
	{
		soft->Run();
	}
};
 
//RefineAbstraction，此处为手机品M
class HandsetBrandM:public HandsetBrand
{
public:
	void Run()
	{
		soft->Run();
	}
};
 
 
#endif
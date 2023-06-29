#include "Observer.h"
#include <iostream>

Observer::Observer()
{}
 
Observer::Observer(std::string name,Subject* sub)
{
	this->name=name;
	this->sub=sub;
}
 
//void Observer::Update()
//{
//	std::cout<<"Observer.Update()"<<std::endl;
//}
 
bool Observer::operator==(const Observer& observer)const
{
	return (this->name==observer.name)&&(this->sub==observer.sub);
}
 
 
StockObserver::StockObserver()
{}
 
StockObserver::StockObserver(std::string name,Subject* sub)
	:Observer(name, sub)
{
	//写法二：(不使用成员初始化列表)
	//this->name=name;
	//this->sub=sub;

	//错误写法：
	//Observer(name,sub);
	//原因：基类对象应当在程序进入派生类构造函数之前被创建。
	//因此应该使用成员初始化列表
}
 
void StockObserver::Update()
{
	std::cout << sub->GetSubjectState() << " " << name << " ";
	std::cout <<"Close the stock market and get back to work!"<<std::endl;
}
 
 
NBAObserver::NBAObserver()
{}
 
NBAObserver::NBAObserver(std::string name,Subject* sub)
{
	this->name=name;
	this->sub=sub;
}
 
void NBAObserver::Update()
{
	std::cout << sub->GetSubjectState() << " " << name << " ";
	std::cout <<"Turn off NBA live and get back to work!"<<std::endl;
}
 
 
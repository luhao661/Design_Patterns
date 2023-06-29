#include "Observer.h"
 
Observer::Observer(){}
 
Observer::Observer(std::string name,Subject* sub)
{
	this->name=name;
	this->sub=sub;
}
 
void Observer::Update()
{
	std::cout<<"Observer.Update()"<<std::endl;
}
 
bool Observer::operator==(const Observer& observer)const
{
	return (this->name==observer.name)&&(this->sub==observer.sub);
}
 
 
StockObserver::StockObserver(){}
 
StockObserver::StockObserver(std::string name,Subject* sub)
{
	this->name=name;
	this->sub=sub;
}
 
void StockObserver::Update()
{
	std::cout << sub->GetSubjectState() << " " << name << " ";
	std::cout <<"Close the stock market and get back to work!"<<std::endl;
}
 
 
NBAObserver::NBAObserver(){}
 
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
 
 
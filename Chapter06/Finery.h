#ifndef FINERY_H
#define FINERY_H
 
#include <iostream>
#include "Person.h"
 
//Decorator类
class Finery:public Person
{
protected:
	Person* component;
public:
	void Decorator(Person* component)
	{
		this->component=component;
	}
	void Show()
	{
		if(component!=NULL)
			component->Show();
	}
};
 
//下面是一系列ConcreteDecorator类
class TShirts:public Finery
{
public:
	void Show()
	{
		std::cout<<"大T恤  ";
		Finery::Show();
	}
 
};
 
//ConcreteDecorator类
class BigTrouser:public Finery
{
public:
	void Show()
	{
		std::cout<<"垮裤  ";
		Finery::Show();
	}
 
};
 
//ConcreteDecorator类
class Sneakers:public Finery
{
public:
	void Show()
	{
		std::cout<<"破球鞋  ";
		Finery::Show();
	}
 
};
 
//ConcreteDecorator类
class Suit:public Finery
{
public:
	void Show()
	{
		std::cout<<"西装  ";
		Finery::Show();
	}
 
};
 
//ConcreteDecorator类
class Tie:public Finery
{
public:
	void Show()
	{
		std::cout<<"领带  ";
		Finery::Show();
	}
 
};
 
//ConcreteDecorator类
class LeatherShoes:public Finery
{
public:
	void Show()
	{
		std::cout<<"皮鞋  ";
		Finery::Show();
	}
	 
};
  
#endif
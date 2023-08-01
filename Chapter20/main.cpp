#include "Iterator.h"
#include "Aggregate.h"
#include <iostream>
#include <cstdlib>
 
//Client客户端
int main()
{
	
	//公交车，即聚集对象
	ConcreteAggregate* a=new ConcreteAggregate();
	
	//新上来的乘客
	a->GetVector()->push_back("Big bird");
	a->GetVector()->push_back("Xiaocai");
	a->GetVector()->push_back("Luggage");
	a->GetVector()->push_back("Foreigner");
	a->GetVector()->push_back("Ticket seller");
	a->GetVector()->push_back("Thief");
 
	//售票员出场，先看好了上车的是哪些人，即声明了迭代器对象。
	//下面两种获取迭代器的方法都可以
	//Iterator* i=new ConcreteIterator(a);
	
	//产生从前往后的迭代器
	Iterator* it1=a->CreateIterator();
	
	//告知每一位乘客买票
	std::cout<<"Iterators from front to back:"<<std::endl<<std::endl;

	while(!it1->IsDone())
	{
		std::cout<<it1->CurrentItem()<<"  Ticket, please!"<<std::endl;
		it1->Next();
	}
	std::cout<<std::endl;
 
	//产生从后往前的迭代器
	Iterator* it2=a->CreateIteratorDesc();
 
	//告知每一位乘客买票
	std::cout<<"Iterators from back to front:"<<std::endl<<std::endl;

	while(!it2->IsDone())
	{
		std::cout<<it2->CurrentItem()<<"  Ticket, please!"<<std::endl;
		it2->Next();
	}
	std::cout<<std::endl<<std::endl;
 
	delete a,it1,it2;
 
	system("pause");

	return 0;
}
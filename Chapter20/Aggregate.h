#ifndef AGGREGATE_H
#define AGGREGATE_H
 
#include <vector>
#include <string>
#include <iostream>
 
class Iterator;
class ConcreteIterator;
 
typedef std::string object;
 
//聚集抽象类
class Aggregate
{
public:
	virtual Iterator* CreateIterator()=0; 
	virtual std::vector<object>* GetVector()=0;
};
 
//具体聚集类
class ConcreteAggregate:public Aggregate
{
private:
	std::vector<object> *items;
public:
	ConcreteAggregate();
	~ConcreteAggregate();
	
	//产生从前往后的迭代器
	Iterator* CreateIterator();
	//产生从后往前的迭代器
	Iterator* CreateIteratorDesc();
 
	std::vector<object>* GetVector();

	int Count();
	object GetElement(int index);
	void SetElement(int index,object o);
};
 
#endif
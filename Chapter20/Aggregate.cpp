#include "Aggregate.h"
#include "Iterator.h"
 
ConcreteAggregate::ConcreteAggregate()
{
	items=new std::vector<object>;
}
ConcreteAggregate::~ConcreteAggregate()
{
	delete items;
}
Iterator* ConcreteAggregate::CreateIterator()
{
	//由于有ConcreteIterator类的前向声明，所以此处可以使用
	Iterator* it=new ConcreteIterator(this);
	return it;
}
Iterator* ConcreteAggregate::CreateIteratorDesc()
{
	Iterator* it=new ConcreteIteratorDesc(this);
	return it;
}
int ConcreteAggregate::Count()
{
	return items->size();
}
std::vector<object>* ConcreteAggregate::GetVector()
{
	return items;
}
object ConcreteAggregate::GetElement(int index)
{
	return items->at(index);
}
void ConcreteAggregate::SetElement(int index,object o)
{
	items->at(index)=o;
}
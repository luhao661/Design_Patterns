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
	//������ConcreteIterator���ǰ�����������Դ˴�����ʹ��
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
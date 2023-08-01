#include "Iterator.h"
 
ConcreteIterator::ConcreteIterator(Aggregate* aggregate)
{
	this->aggregate=(ConcreteAggregate*)aggregate;

	current=0;
}
object ConcreteIterator::First()
{
	return aggregate->GetVector()->at(0);
}
object ConcreteIterator::Next()
{
	current++;
	if(current<aggregate->GetVector()->size())
		return aggregate->GetVector()->at(current);
}
bool ConcreteIterator::IsDone()
{
	//若当前current值大于等于vector对象的size方法返回值，则返回真
	//相当于
	//若当前current值小于vector对象的size方法返回值，则返回假
	return current>=aggregate->GetVector()->size()?true:false;
}
object ConcreteIterator::CurrentItem()
{
	return aggregate->GetVector()->at(current);
}
  
 
ConcreteIteratorDesc::ConcreteIteratorDesc(Aggregate* aggregate)
{
	this->aggregate=(ConcreteAggregate*)aggregate;
	current=(((ConcreteAggregate*)aggregate)->GetVector()->size())-1;
}
object ConcreteIteratorDesc::First()
{
	return *(aggregate->GetVector()->end());
}
object ConcreteIteratorDesc::Next()
{
	current--;
	if(current>=0)
		return aggregate->GetVector()->at(current);
}
bool ConcreteIteratorDesc::IsDone()
{
	//若当前currnt值大于等于0，则返回假
	return current<0?true:false;
}
object ConcreteIteratorDesc::CurrentItem()
{
	return aggregate->GetVector()->at(current);
}
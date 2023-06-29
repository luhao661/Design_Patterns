#include "Builder.h"
#include <iostream>
#include <cstdlib>
 
//Client，客户不知道具体的建造过程。
int main()
{
    //创建一个指挥者类指针
    //指挥者类能通过使用Builder抽象基类的指针
    //调用继承了Builder类的派生类的方法
	Director* director=new Director();
 
    //创建一个Builder抽象基类的指针，
    //指向动态分配的匿名的具体建造者类1
	Builder* builder1=new ConcreteBuilder1();
	Builder* builder2=new ConcreteBuilder2();
 
	std::cout<<"指挥者用ConcreteBuilder1的方法建造产品："
    <<std::endl;
    //指挥者用ConcreteBuilder1的方法建造产品
	director->Construct(builder1);
    //创建一个产品类指针，指向ConcreteBuilder1的方法建造的产品
	Product* p1=builder1->GetResult();
	p1->Show();
	std::cout<<std::endl;
 
	std::cout<<"指挥者用ConcreteBuilder2的方法建造产品："
    <<std::endl;
	director->Construct(builder2);
	Product* p2=builder2->GetResult();
	p2->Show();
	std::cout<<std::endl;
 
	delete director;
	delete builder1;
	delete builder2;
 
	system("pause");

    return 0;
}
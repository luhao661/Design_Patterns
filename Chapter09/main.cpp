#include <iostream>
#include <stdlib.h>
#include "Prototype.h"
 
// using namespace std;

int main()
{
	//创建一个具体原型类指针，指向动态分配的匿名的具体原型
	//(具体原型的构造函数创建了匿名的WorkExperience类对象
	//并用其数据成员(即指向WorkExperience类的指针)指向这个类对象)
	Resume* a=new Resume("大鸟");
	//具体原型类指针调用SetPersonalInfo()方法，设置
	//原型的抽象基类的类数据成员的值
	a->SetPersonalInfo("男","29");
	//具体原型类指针调用SetWorkExperience()方法，设置
	//WorkExperience类的类数据成员的值
	a->SetWorkExperience("1998-2000","XX公司");
 
 	//创建一个具体原型类指针，指向具体原型类指针调用Clone()方法
	//动态分配的匿名具体原型类对象
	//(该对象的数据成员的内容就是之前创建的匿名WorkExperience类对象的地址
	//而其继承的基类的数据成员的值就是之前创建成员时设置好的值)
	Resume* b=a->Clone();
	b->SetWorkExperience("1998-2006","YY公司");
 
	Resume* c=b->Clone();
	c->SetPersonalInfo("男","24");
	c->SetWorkExperience("1998-2003","ZZ公司");
 
	a->Display();
	b->Display();
	c->Display();
 
	delete a;
	delete b;
	delete c;
	a=b=c=NULL;
	system("pause");

    return 0;
}
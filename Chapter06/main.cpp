#include "Finery.h"
#include <string>
#include <iostream>
 
//客户端
int main()
{
	//创建一个指向基类Person的指针xc
	Person* xc=NULL;
	//申请一个动态分配的已由构造函数进行初始化的类对象，
	//xc指向这个匿名类对象
	xc=new Person("小菜");
 
	std::cout<<"第一种装扮："<<std::endl;
	
	//Finery类继承了Person类
	//Finery类内含一个指向Person类的指针
	//Sneakers继承了Finery类
	Sneakers* pqx=NULL;
	//申请一个动态分配的已由默认的默认构造函数进行初始化的类对象，
	//***注***
	//它的父类都用默认的默认构造函数进行初始化了
	//pqx指向这个匿名类对象
	pqx=new Sneakers();

	BigTrouser* kk=NULL;
	kk=new BigTrouser();

	TShirts* dtx=NULL;
	dtx=new TShirts();
 
	//***
	//派生类指针pqx调用基类的Decorator()方法
	//pqx指向的派生类的component成员被赋值为一个指向基类Person的指针xc
	pqx->Decorator(xc);
	//派生类指针kk调用基类的Decorator()方法
	//kk指向的派生类的component成员被赋值为一个指向派生类的指针pqx
	kk->Decorator(pqx);
	//派生类指针dtx调用基类的Decorator()方法
	//dtx指向的派生类的component成员被赋值为一个指向派生类的指针kk
	dtx->Decorator(kk);
	
	//***注***
	
	dtx->Show();
 
	std::cout<<"第二种装扮："<<std::endl;
 
	LeatherShoes* px=NULL;
	px=new LeatherShoes();
	Tie* ld=NULL;
	ld=new Tie();
	Suit* xz=NULL;
	xz=new Suit();
 
	px->Decorator(xc);
	ld->Decorator(px);
	xz->Decorator(ld);
 
	xz->Show();
 
	if(xc!=NULL)
	{
		delete xc;
		xc=NULL;
	}
	if(pqx!=NULL)
	{
		delete pqx;
		pqx=NULL;
	}
	if(kk!=NULL)
	{
		delete kk;
		kk=NULL;
	}
	if(dtx!=NULL)
	{
		delete dtx;
		dtx=NULL;
	}
	if(px!=NULL)
	{
		delete px;
		px=NULL;
	}
	if(ld!=NULL)
	{
		delete ld;
		ld=NULL;
	}
	if(xz!=NULL)
	{
		delete xz;
		xz=NULL;
	}
 
	system("pause");

    return 0;
}
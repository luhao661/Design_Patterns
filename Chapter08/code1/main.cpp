#include <iostream>
#include <cstdlib>
 
//工厂模式实现计算器

using namespace std;
 
//抽象产品类
//(产品基类)
class Operation
{
protected:
	double numberA;
	double numberB;
 
public:
	double getA()
	{
		return numberA;
	}
	double getB()
	{
		return numberB;
	}
	void setA(double number)
	{
		numberA=number;
	}
	void setB(double number)
	{
		numberB=number;
	}
 
	virtual double GetResult()
	{
		double result=0;
		return result;
	}
};

//下面是四个具体产品类
class OperationAdd:public Operation
{
public:
	double GetResult()
	{
		double result=0;
		result=numberA+numberB;
		return result;
	}
};
 
class OperationSub:public Operation
{
public:
	double GetResult()
	{
		double result=0;
		result=numberA-numberB;
		return result;
	}
};
 
class OperationMul:public Operation
{
public:
	double GetResult()
	{
		double result=0;
		result=numberA*numberB;
		return result;
	}
};
 
class OperationDiv:public Operation
{
public:
	double GetResult()
	{
		double result=0;
		if(numberB!=0)
			result=numberA/numberB;
		return result;
	}
};
 
//抽象工厂基类(ABC)
class AbstractFactory
{
public:
	virtual Operation* createOperation() = 0; 
};

//下面是四个具体工厂类，分别用于产生四个具体产品
class AddFactory:public AbstractFactory
{
public:
	Operation* createOperation()
	{
		Operation* oper=new OperationAdd;
		return oper;
	}
};
 
class SubFactory:public AbstractFactory
{
public:
	Operation* createOperation()
	{
		Operation* oper=new OperationSub;
		return oper;
	}
};
 
class MulFactory:public AbstractFactory
{
public:
	Operation* createOperation()
	{
		Operation* oper=new OperationMul;
		return oper;
	}
};
 
class DivFactory:public AbstractFactory
{
public:
	Operation* createOperation()
	{
		Operation* oper=new OperationDiv;
		return oper;
	}
};
 
//客户端
//与简单工厂模式相比，制造产品的工厂类不再只有一个，而是每种具体产品类
//都对应一个生产它的具体工厂类。而这些具体工厂类的共同特征
//再被提取出来形成一个抽象产品类，这些具体产品类都继承自这个抽象产品类。

//当需要增加一种产品的时候，需要做的是：增加一种继承自抽象产品的具体产品类，
//增加一种继承在抽象工厂的具体工厂类，更改客户端。
//而不需要在简单工厂模式中那样更改工厂内的switch。
// ————————————————
// 版权声明：本文为CSDN博主「西青年」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/xiqingnian/article/details/40957025
int main()
{
    //创建一个抽象工厂基类的指针
	AbstractFactory* af=NULL;
    //使该指针指向具体工厂类对象
	af=new AddFactory();
	
    //创建一个产品基类指针
	Operation* oper=NULL;
    //使该指针指向具体工厂类调用createOperation()方法
    //生成的具体产品类对象
	oper=af->createOperation();
	
	oper->setA(1);
	oper->setB(2);
	cout<<oper->GetResult()<<endl;
	
	if(af!=NULL)
	{
		delete af;
		af=NULL;
	}
	if(oper!=NULL)
	{
		delete oper;
		oper=NULL;
	}
 
	system("pause");

    return 0;
}
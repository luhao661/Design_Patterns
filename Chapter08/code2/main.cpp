#include <iostream>
#include <cstdlib>
 
//工厂模式

using namespace std;
 
//抽象产品类：雷锋
//(产品基类)
class Leifeng
{
public:
	virtual void Sweep()
	{
		cout<<"扫地"<<endl;
	}
	virtual void Wash()
	{
		cout<<"洗衣"<<endl;
	}
	virtual void BuyRice()
	{
		cout<<"买米"<<endl;
	}
};
 
//下面是两个具体产品类
class Undergraduate:public Leifeng
{
public:
	void Sweep()
	{
		cout<<"学生-扫地"<<endl;
	}
	void Wash()
	{
		cout<<"学生-洗衣"<<endl;
	}
	void BuyRice()
	{
		cout<<"学生-买米"<<endl;
	}
};
 
class Volunteer:public Leifeng
{
public:
	void Sweep()
	{
		cout<<"志愿者-扫地"<<endl;
	}
	void Wash()
	{
		cout<<"志愿者-洗衣"<<endl;
	}
	void BuyRice()
	{
		cout<<"志愿者-买米"<<endl;
	}
};
 
#if 0
//抽象工厂类
class AbstractFactory
{
public:
	virtual Leifeng* CreateLeifeng()
	{
		return new Leifeng;
	}
};
#endif
//也可以这么写
//抽象工厂基类
class AbstractFactory
{
public:
    virtual Leifeng *CreateLeifeng() = 0;
};

//下面是两个具体工厂类，分别于两个具体产品相对应
class UndergraduateFactory:public AbstractFactory
{
public:
	Leifeng* CreateLeifeng()
	{
        Leifeng* lf=new Undergraduate;
		return lf;
	}
};
 
class VolunteerFactory:public AbstractFactory
{
public:
	Leifeng* CreateLeifeng()
	{
        //也可以这么写
		return new Volunteer();
	}
};
 
//客户端
int main()
{
	//想要生产Volunteer产品的话，
    //只需要将此处的UndergraduateFactory更改为VolunteerFactory即可。

    //创建一个抽象工厂基类的指针
	AbstractFactory* af=NULL;
    //使该指针指向具体工厂类对象
	af=new UndergraduateFactory;
	
    //创建一个产品基类指针
	Leifeng* lf=NULL;
    //使该指针指向具体工厂类调用CreateLeifeng()方法
    //生成的具体产品类对象
	lf=af->CreateLeifeng();
 
	lf->BuyRice();
	lf->Sweep();
	lf->Wash();
 
	if(af!=NULL)
	{
		delete af;
		af=NULL;
	}
	if(lf!=NULL)
	{
		delete lf;
		lf=NULL;
	}
 
	system("pause");

    return 0;
}
//工厂方法克服了简单工厂违背开放-封闭原则的缺点，
//又保持了封装对象创建过程的优点。
//工厂方法模式是简单工厂模式的进一步抽象和推广
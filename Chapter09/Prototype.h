#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>
 
//工作经验类：WorkExperience类
class WorkExperience
{
private:
	std::string workDate;
	std::string company;

public:
	WorkExperience()
    {}
	~WorkExperience()
    {}

	//供克隆调用的构造函数
	WorkExperience(WorkExperience* work)
	{
        //使用string类的=运算符重载函数，
        //进行深复制
		this->workDate=work->workDate;
		this->company=work->company;
	}

	std::string getWorkDate()
	{
		return workDate;
	}
	void setWorkDate(std::string workDate)
	{
		this->workDate=workDate;
	}
    
	std::string getCompany()
	{
		return company;
	}
	void setCompany(std::string company)
	{
		this->company=company;
	}
 
	//克隆
	WorkExperience*  Clone()
	{
		//调用供克隆调用的构造函数WorkExperience（WorkExperience）
		return new WorkExperience(this);

		//也可以写为：
		/*
		WorkExperience* cloneWorkExperience = 
		new WorkExperience;

		cloneWorkExperience->workDate=this->workDate;
		cloneWorkExperience->company=this->company;

		return cloneWorkExperience;
		*/
	}
};
 
//原型抽象基类，声明一个克隆自身的接口。
class Prototype
{
protected:
	std::string name;
	std::string sex;
	std::string age;
	std::string timeArea;
	std::string company;
public:
	virtual void SetPersonalInfo(std::string sex,std::string age)=0;
	virtual void Display()=0;
	virtual Prototype* Clone()=0; 
};
 
//具体原型类，即ConcretePrototype类，本例中为简历Resume类，
//实现一个克隆自身的操作。
class Resume:public Prototype
{
private:
	WorkExperience* work;
public:
	Resume(std::string name)
	{
		this->name=name;
		work=new WorkExperience();
	}
	~Resume()
	{
		if(work!=NULL)
			delete work;
	}

	//供克隆调用的构造函数
	Resume(WorkExperience* work)
	{
		this->work=work->Clone();
	}
	void SetPersonalInfo(std::string sex,std::string age)
	{
		this->sex=sex;
		this->age=age;
	}
	void SetWorkExperience(std::string workDate,std::string company)
	{
		work->setWorkDate(workDate);
		work->setCompany(company);
	}
	void Display()
	{
		std::cout<<name<<"  "<<sex<<"  "<<age<<std::endl;
		std::cout<<"工作经历  "<<work->getWorkDate()<<"  "
		<<work->getCompany()<<std::endl;
	}
 
	//克隆
	Resume* Clone()
	{
		//调用供克隆函数调用的构造函数Resume(work)
		Resume *cloneResume=new Resume(work);
		cloneResume->name=this->name;
		cloneResume->age=this->age;
		cloneResume->sex=this->sex;
		return cloneResume;
	}
};
 
 
#endif
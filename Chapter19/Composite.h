#include<iostream>
#include<list>
#include<string>
using namespace std; 
 
//Component：此处为抽象公司类
class Company
{
protected:
	string m_name;
 
public:
	explicit Company(const string &name) :m_name(name) {}
	virtual ~Company() = default;
 
	virtual void Add(Company *c) = 0;
	virtual	void Remove(Company *c) = 0;
	virtual void Display(int depth) = 0;
	virtual void LineOfDuty() = 0; // 不同的公司有不同的职责
}; 
 
//Composite：具体公司类
class ConcreteCompany :public Company
{
private:
	list<Company*> m_children;
 
public:
	explicit ConcreteCompany(const string &name) :Company(name) {}
 
	void Add(Company *c)override
	{
		m_children.push_back(c);
	}

	void Remove(Company *c)override
	{
		while (!m_children.empty())
		{
			for (auto tt = m_children.begin(); tt != m_children.end(); ++tt)
			{
				if (*tt == c)
				{
					m_children.erase(tt);
					break;
				}
			}
			break;
		}
	}
	void Display(int depth)override
	{
		if (!m_children.empty())
		{
			for (int i = 0; i != depth; ++i)
				cout << "-";

			cout << m_name << endl;
 
			for (auto tt : m_children)
			{
                //***注***
                //指向抽象基类的指针tt
                //若存储的是某个派生类(HRDepartment或FinanceDepartment)
                //的地址值，
                //则将调用某个派生类的Display()方法，
				//若存储的是派生类ConcreteCompany的地址值
				//则将导致递归调用该函数。
				tt->Display(depth + 2);
			}
		}
	}
	void LineOfDuty() override // 不同的公司有不同的职责
	{
		while (!m_children.empty())
		{
			for (auto tt : m_children)
			{
				tt->LineOfDuty();
			}
			break;
		}
		
	}
};
 
//Leaf:人力资源部
class HRDepartment :public Company
{
	void Add(Company*)override {}
	
	void Remove(Company*)override {}
	
public:
	explicit HRDepartment(const string &name) :Company(name) {}
 
	 void Display(int depth) override
	{
		 for (int i = 0; i != depth; ++i)
			 cout << "-";
		 cout << m_name << endl;
	}
	 void LineOfDuty() override // 不同的公司有不同的职责
	{
		 cout << m_name << "Staff recruitment training management!" << endl;
	}
};
 
//Leaf:财务部
class FinanceDepartment :public Company
{
	void Add(Company*)override {}
 
	void Remove(Company*)override {}
 
public:
	explicit FinanceDepartment(const string &name) :Company(name) {}
 
	void Display(int depth) override
	{
		for (int i = 0; i != depth; ++i)
			cout << "-";
		cout << m_name << endl;
	}
	void LineOfDuty() override // 不同的公司有不同的职责
	{
		cout << m_name << "Company financial revenue and expenditure management!" << endl;
	}
};
 

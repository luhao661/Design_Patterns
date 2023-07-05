#ifndef ABSTRACT_H
#define ABSTRACT_H

#include<iostream>
using namespace std;
 
// 抽象产品Department ,定义具体产品的公共接口
class Department  
{
public:
    // =default 来要求编译器生成默认构造函数，
    //仅仅是因为我们既需要其他形式的构造函数，也需要默认的构造函数。
	virtual ~Department() = default;
	virtual void Insert() = 0;
	virtual Department *GetDepartment() = 0;
};
 
// 创建具体产品类SqlserDepartment， 定义生产的具体产品；
class  SqlserDepartment :public Department 
{
public:
	void Insert()override
	{
		cout << "Add a record to the Department table in SQL Server!" << endl;
	}
	Department *GetDepartment()override
	{
		cout << "Get a record in the Department table according to ID in SQL Server!" << endl;
		return nullptr;
	}
};

// 创建具体产品类AccessDepartment， 定义生产的具体产品；
class AccessDepartment : public Department 
{
public:
	void Insert()override
	{
		cout << "Add a record to the Department table in Access!" << endl;
	}
	Department *GetDepartment()override
	{
		cout << "Get a record in the Department table according to ID in Access!" << endl;
		return nullptr;
	}
};
 

// 抽象产品User ,定义具体产品的公共接口
class User   
{
 
public:
	virtual ~User() = default;
	virtual void Insert() = 0;
	virtual User *GetUser() = 0;
};
 
// 创建具体产品类SqlserverUser， 定义生产的具体产品；
class SqlserverUser :public User  
{
public:
	void Insert()override
	{
		cout << "Add a record to the User table in SQL Server!" << endl;
	}
	User *GetUser()override
	{
		cout << "Get a User table record according to ID in SQL Server!" << endl;
		return nullptr;
	}
};

// 创建具体产品类AccessUser， 定义生产的具体产品；
class AccessUser :public User  
{
public:
	void Insert()override
	{
		cout << "Add a record to the User table in Access!" << endl;
	}
	User *GetUser()override
	{
		cout << "Get a User table record according to ID in Access!" << endl;
		return nullptr;
	}
};
 
 
// 抽象工厂,定义具体工厂的公共接口
class AbstractFactory 
{
public:
	virtual ~AbstractFactory() = default;
	virtual User *CreateUser() = 0;
	virtual Department *CreateDepartment() = 0;
};
 
// 创建具体工厂SqlServerFactory,定义创建对应具体产品实例的方法；
class SqlServerFactory :public AbstractFactory 
{
public:
	User *CreateUser()override
	{
		return new SqlserverUser(); // 该工厂生产的产品
	}
	Department *CreateDepartment()override
	{
		return new SqlserDepartment;
	}
};
// 创建具体工厂AccessFactory，定义创建对应具体产品实例的方法；
class AccessFactory :public AbstractFactory  
{
public:
	User *CreateUser()override
	{
		return new AccessUser(); // 该工厂生产的产品
	}
	Department *CreateDepartment()override
	{
		return new AccessDepartment;
	}
};
 

// ————————————————
// 版权声明：本文为CSDN博主「To-String」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/qq_34536551/article/details/89312812

#endif
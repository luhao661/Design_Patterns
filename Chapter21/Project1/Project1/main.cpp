#include <iostream>
#include "Singleton.h"

//静态成员在类体外定义
Singleton* Singleton::instance = 0;
CRITICAL_SECTION Singleton::m_Sec = CRITICAL_SECTION();

int main()
{
	//初始化临界区
	InitializeCriticalSection(Singleton::getLock());

	Singleton* singleton1 = Singleton::GetInstance();
	Singleton* singleton2 = Singleton::GetInstance();

	//删除临界区
	DeleteCriticalSection(Singleton::getLock());

	if (singleton1 == singleton2)
		std::cout << "两个对象是相同的实例。" << std::endl;

	system("pause");

	return 0;
}
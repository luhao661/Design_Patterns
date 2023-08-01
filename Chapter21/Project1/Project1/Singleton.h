#ifndef SINGLETON_H
#define SINGLETON_H
#include <afx.h>

class Singleton
{
private:
	static Singleton* instance;
	//临界区，防止多线程产生多个实例
	static CRITICAL_SECTION m_Sec;

	//默认构造函数为私有
	Singleton() {}

public:
	static CRITICAL_SECTION* getLock()
	{
		return &m_Sec;
	}
	static Singleton* GetInstance()
	{
		//双重锁定
		if (instance == NULL)
		{

			EnterCriticalSection(&m_Sec);

			if (instance == NULL)
				instance = new Singleton();

			LeaveCriticalSection(&m_Sec);

		}
		return instance;
	}
};

#endif
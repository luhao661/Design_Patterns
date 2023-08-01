#ifndef SINGLETON_H
#define SINGLETON_H
#include <afx.h>

class Singleton
{
private:
	static Singleton* instance;
	//�ٽ�������ֹ���̲߳������ʵ��
	static CRITICAL_SECTION m_Sec;

	//Ĭ�Ϲ��캯��Ϊ˽��
	Singleton() {}

public:
	static CRITICAL_SECTION* getLock()
	{
		return &m_Sec;
	}
	static Singleton* GetInstance()
	{
		//˫������
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
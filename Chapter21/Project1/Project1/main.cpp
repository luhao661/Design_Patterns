#include <iostream>
#include "Singleton.h"

//��̬��Ա�������ⶨ��
Singleton* Singleton::instance = 0;
CRITICAL_SECTION Singleton::m_Sec = CRITICAL_SECTION();

int main()
{
	//��ʼ���ٽ���
	InitializeCriticalSection(Singleton::getLock());

	Singleton* singleton1 = Singleton::GetInstance();
	Singleton* singleton2 = Singleton::GetInstance();

	//ɾ���ٽ���
	DeleteCriticalSection(Singleton::getLock());

	if (singleton1 == singleton2)
		std::cout << "������������ͬ��ʵ����" << std::endl;

	system("pause");

	return 0;
}
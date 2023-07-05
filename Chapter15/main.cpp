#include "Abstract.h"

int main()
{
	//AbstractFactory *factory = new SqlServerFactory;
	AbstractFactory *factory = new AccessFactory();
    //调用的是 AccessFactory 工厂，准备生产 AccessUser 产品
	User *iu = factory->CreateUser();
	iu->Insert();
	iu->GetUser();
 
    //调用的是 AccessFactory 工厂，准备生产  AccessDepartment 产品
	Department *id = factory->CreateDepartment(); 
	id->Insert();
	id->GetDepartment();
 
	delete factory;
	delete iu;
	delete id;

	factory = nullptr;
	id = nullptr;
	id = nullptr;
    
	system("pause");
	return 0;
}
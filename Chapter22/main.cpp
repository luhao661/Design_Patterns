#include "Bridge.h"
#include <iostream>
 
//Client，客户端
int main()
{
	//手机品牌N
	std::cout<<"Mobile phone brand N:"<<std::endl;
	HandsetBrand* ab=new HandsetBrandN();
 
	ab->SetHandsetSoft(new HandsetGame());
	ab->Run();
 
	ab->SetHandsetSoft(new HandsetAddressList());
	ab->Run();
 
	delete ab;
 
	//手机品牌M
	std::cout<<std::endl<<"Mobile phone brand M:"<<std::endl;
	ab=new HandsetBrandM();
 
	ab->SetHandsetSoft(new HandsetGame());
	ab->Run();
 
	ab->SetHandsetSoft(new HandsetAddressList());
	ab->Run();
 
	delete ab;
	ab=NULL;
 
	std::cout<<std::endl;
	system("pause");

    return 0;
}
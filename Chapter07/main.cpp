#include "Proxy.h"
#include <iostream>
#include <stdlib.h>
 
//Client，客户端
int main()
{
	SchoolGirl* jiaojiao=new SchoolGirl();
	jiaojiao->setName("李娇娇");
 
	Proxy* daili=new Proxy(jiaojiao);
 
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();
 
	delete jiaojiao;
        jiaojiao=NULL;
	delete daili;
        daili=NULL;
	system("pause");

    return 0;
}
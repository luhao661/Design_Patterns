#include "Facade.h"
#include <iostream>
#include <cstdlib>
 
//Client
int main()
{
	Facade* facade=new Facade();
 
	facade->MethodA();
	facade->MethodB();
 
	delete facade;
 
	system("pause");

    return 0; 
}
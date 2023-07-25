#include <iostream>
#include <cstdlib>
#include "Work.h"
//#include "State.h"
 
using namespace std;
 
int main()
{
	Work emergencyProjects;
 
	emergencyProjects.setHour(9);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(10);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(12);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(13);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(14);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(17);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setFinish(false);
 
	emergencyProjects.setHour(19);
	emergencyProjects.writeProgram();
 
	emergencyProjects.setHour(22);
	emergencyProjects.writeProgram();
 
	system("pause");

	return 0;
}
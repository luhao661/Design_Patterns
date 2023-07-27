#include "Composite.h"

int main()
{
	Company* root = new ConcreteCompany("Beijing head office");
	HRDepartment  *leaf1 = new HRDepartment("Head office HR department");
	FinanceDepartment *leaf2 = new FinanceDepartment("Head office finance department");
	root->Add(leaf1);
	root->Add(leaf2);
 
	Company* comp = new ConcreteCompany("Shanghai East China Branch");
	HRDepartment  *leaf3 = new HRDepartment("East China Branch human resources Department");
	FinanceDepartment *leaf4 = new FinanceDepartment("East China branch finance Department");
	comp->Add(leaf3);
	comp->Add(leaf4);
	root->Add(comp);
 
	Company* comp1 = new ConcreteCompany("Nanjing Office");
	HRDepartment  *leaf5 = new HRDepartment("Human Resources Department, Nanjing Office");
	FinanceDepartment *leaf6 = new FinanceDepartment("Nanjing Office finance Department");
	comp1->Add(leaf5);
	comp1->Add(leaf6);
	comp->Add(comp1);
 
	Company* comp2 = new ConcreteCompany("Hangzhou Office");
	HRDepartment  *leaf7 = new HRDepartment("Human Resources Department, Hangzhou Office");
	FinanceDepartment *leaf8 = new FinanceDepartment("Hangzhou Office finance Department");
	comp2->Add(leaf7);
	comp2->Add(leaf8);
	comp->Add(comp2);
 
 
	cout << "Structure chart: " << endl << endl;
	root->Display(1);
 
	cout << endl << "Duty: " << endl << endl;
	root->LineOfDuty();
 
 
	delete leaf1; delete leaf2;
	delete leaf3; delete leaf4;
	delete leaf5; delete leaf6;
	delete leaf7; delete leaf8;
 
	delete root; 
    delete comp;
    delete comp1;
    delete comp2;

	system("pause");
    
	return 0;
}
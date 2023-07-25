#include "Adapter.h"

int main()
{
	Player *b = new Forwads("Batir");
	b->Attack();
 
	Player *m = new Guards("McGrady");
	m->Attack();
 
	Player *ym = new Translator("Yaoming");
	ym->Attack();
	ym->Defense();
 
	delete b; 
	delete m;
	delete ym;

	b = nullptr;
	m = nullptr;
	ym = nullptr;

	system("pause");

	return 0;
}
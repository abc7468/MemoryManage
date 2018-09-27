#include "Manage.h"





int Manage::firstFitMyalloc(int size)
{
	int addr = List::fAlloc(size);
	List::display();
	return addr;
}

void Manage::myfree(int addr)
{
	List::ffree(addr);
	List::display();
}

Manage::~Manage()
{
}

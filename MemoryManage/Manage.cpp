#include "Manage.h"





int Manage::myalloc_FF(int size)
{
	int addr = List::fAlloc(size);
	List::display();
	return addr;
}

int Manage::myalloc_BF(int size)
{
	int addr = List::bAlloc(size);
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

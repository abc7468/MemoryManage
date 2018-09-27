#include "Manage.h"





int Manage::myalloc(int size)
{
	int addr = List::alloc(size);
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

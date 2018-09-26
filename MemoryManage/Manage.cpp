#include "Manage.h"





int Manage::myalloc(int size)
{
	int addr = List::alloc(size);
	List::display();
	return addr;
}

Manage::~Manage()
{
}

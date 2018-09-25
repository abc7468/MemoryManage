#include "Manage.h"





void Manage::myalloc(int size)
{
	List::alloc(size);
	List::display();
}

Manage::~Manage()
{
}

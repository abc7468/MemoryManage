#pragma once
#include "List.h"
class Manage : public List
{
public:
	Manage(int size) :List(size) {};
	int firstFitMyalloc(int);
	void myfree(int);
	~Manage();
};


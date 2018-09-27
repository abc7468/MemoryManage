#pragma once
#include "List.h"
class Manage : public List
{
public:
	Manage(int size) :List(size) {};
	int myalloc(int);
	void myfree(int);
	~Manage();
};


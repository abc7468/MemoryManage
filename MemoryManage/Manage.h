#pragma once
#include "List.h"
class Manage : public List
{
public:
	Manage(int size) :List(size) {};
	int myalloc_FF(int);
	int myalloc_BF(int);
	void myfree(int);
	void displayAll();
	~Manage();
};


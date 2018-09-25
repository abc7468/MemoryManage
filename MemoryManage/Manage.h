#pragma once
#include "List.h"
class Manage : public List
{
public:
	Manage(int size) :List(size) {};
	void myalloc(int);
	~Manage();
};


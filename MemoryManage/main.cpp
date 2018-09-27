#include<iostream>
#include"List.h"
#include"Manage.h"
using namespace std;

int main() {
	int a, b,c,d;
	Manage* manager = new Manage(100);
	a = manager->myalloc(10);
	b = manager->myalloc(20);
	c = manager->myalloc(30);
	d = manager->myalloc(20);

	manager->myfree(b);
}
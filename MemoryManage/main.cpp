#include<iostream>
#include"List.h"
#include"Manage.h"
using namespace std;

int main() {
	int a, b, c, d,e,f;
	Manage* manager = new Manage(200);
	a = manager->myalloc_FF(40);
	b = manager->myalloc_FF(60);
	c = manager->myalloc_FF(30);
	d = manager->myalloc_FF(20);
	e = manager->myalloc_FF(10);

	manager->myfree(d);
	manager->myfree(b);
	b = manager->myalloc_BF(30);
	manager->displayAll();
	
}
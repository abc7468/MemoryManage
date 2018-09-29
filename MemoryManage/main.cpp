#include<iostream>
#include"List.h"
#include"Manage.h"
using namespace std;

int main() {
	int a, b, c, d,e;
	Manage* manager = new Manage(200);
	a = manager->myalloc_FF(10);
	b = manager->myalloc_FF(60);
	c = manager->myalloc_FF(40);
	d = manager->myalloc_FF(30);
	e = manager->myalloc_FF(40);


	manager->myfree(b);
	manager->myfree(d);
	b = manager->myalloc_BF(30);
}
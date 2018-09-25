#include<iostream>
#include"List.h"
#include"Manage.h"
using namespace std;

int main() {
	
	Manage* a = new Manage(100);
	a->myalloc(10);
	a->myalloc(20);
	a->myalloc(30);
	a->myalloc(40);

}
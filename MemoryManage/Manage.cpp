#include "Manage.h"
#include <iostream>
using namespace std;


int Manage::myalloc_FF(int size)
{
	if (size > 0) {
		int addr = List::fAlloc(size);
		cout << size << "byte를 First-Fit으로 할당합니다." << endl;
		List::display();
		return addr;
	}
	else {
		cout << "오류 : 0보다 큰 값을 입력하시오" << endl;
		return 0;
	}
}

int Manage::myalloc_BF(int size)
{
	if (size > 0) {
		int addr = List::bAlloc(size);
		cout << size << "byte를 Best-Fit으로 할당합니다." << endl;
		List::display();
		return addr;
	}
	else {
		cout << "오류 : 0보다 큰 값을 입력하시오" << endl;
		return 0;
	}
}

void Manage::myfree(int addr)
{
	cout << addr << "주소에 있는 메모리를 제거합니다." << endl;
	List::ffree(addr);
	List::display();
}

void Manage::displayAll()
{
	List::displayAll();
}

Manage::~Manage()
{
}
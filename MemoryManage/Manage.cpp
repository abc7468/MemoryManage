#include "Manage.h"
#include <iostream>
using namespace std;


int Manage::myalloc_FF(int size)
{
	if (size > 0) {
		int addr = List::fAlloc(size);
		cout << size << "byte�� First-Fit���� �Ҵ��մϴ�." << endl;
		List::display();
		return addr;
	}
	else {
		cout << "���� : 0���� ū ���� �Է��Ͻÿ�" << endl;
		return 0;
	}
}

int Manage::myalloc_BF(int size)
{
	if (size > 0) {
		int addr = List::bAlloc(size);
		cout << size << "byte�� Best-Fit���� �Ҵ��մϴ�." << endl;
		List::display();
		return addr;
	}
	else {
		cout << "���� : 0���� ū ���� �Է��Ͻÿ�" << endl;
		return 0;
	}
}

void Manage::myfree(int addr)
{
	cout << addr << "�ּҿ� �ִ� �޸𸮸� �����մϴ�." << endl;
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
#include "List.h"
#include<iostream>
#include<Windows.h>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::fSearch(int size) // ���� ������ �޸𸮰� �ִ��� ã���ְ� �� �ּҸ� ��ȯ�� �ִ� �Լ�
{
	
	Node* current = head;
	while (current->state != TAIL) {
		current = current->next;
		if (current->state == EMPTY && (current->data)>=size) {
			return current;
		}
	}
	cout << "���� : ������ �� �ִ� �޸𸮰� �����ϴ�." << endl;

	return 0;
}

Node * List::bSearch(int size)
{
	Node* current = head->next;
	Node* tempNode = new Node;
	int temp = INT_MAX;
	int check = 0;

	while (current->state != TAIL) {
		if (current->state == EMPTY && current->data == size) {
			return current;
		}
		else if (current->state == EMPTY && current->data - size < temp) {
			if (current->data - size >= 0) {
				temp = current->data - size;
				tempNode = current;
			}
			current = current->next;
			
			
		}
		else {
			current = current->next;
		}
	}
	return tempNode;
}

void List::sort(Node* orial) // �̾��� EMPTYNODE�� �����ִ� �Լ�
{
	Node* currentNode = head;
	while (currentNode->next != tail) {
		if (currentNode->state == EMPTY && currentNode->next->state == EMPTY) {
			orial = currentNode;
			currentNode = currentNode->next;
			deleteNode(orial);
		}
		else {
			currentNode = currentNode->next;
		}
	}
}

void List::deleteNode(Node *orial) //sort�Լ����� ������������Node�� Free�����ִ� �Լ�
{
	orial->next->data = orial->next->data + orial->data;
	orial->before->next = orial->next;
	orial->next->before = orial->before;
	delete orial;
	orial = nullptr;
}

int List::fAlloc(int size) // alloc����
{
	
	Node* allocNode = new Node;

	
	allocNode->data = size;
	allocNode->state = FULL;
	Node* findNode = fSearch(size);
	findNode->data = (findNode->data) - size;
	findNode->before->next = allocNode;
	allocNode->before = findNode->before;
	findNode->before = allocNode;
	allocNode->next = findNode;
	int addr = findAddr(findNode, size);
	if (findNode->data == 0 && findNode->state == EMPTY) {
		findNode->before->next = findNode->next;
		findNode->next->before = findNode->before;
		deleteNode(findNode);
	}
	return addr;
	
}

int List::bAlloc(int size)
{
	Node* allocNode = new Node;

	
	allocNode->data = size;
	allocNode->state = FULL;
	Node* findNode = bSearch(size);
	findNode->data = (findNode->data) - size;
	findNode->before->next = allocNode;
	allocNode->before = findNode->before;	
	findNode->before = allocNode;
	allocNode->next = findNode;
	int addr = findAddr(findNode, size);
	if (findNode->data == 0 && findNode->state == EMPTY) {
		findNode->before->next = findNode->next;
		findNode->next->before = findNode->before;
		deleteNode(findNode);
	}
	return addr;
}

int List::findAddr(Node *findNode, int size)
{
	int addr = 0;
	Node* currentNode = head->next;
	while (currentNode->next != findNode) {
		addr = addr + (currentNode->data);
		currentNode = currentNode->next;
	}

	return addr;
}

void List::ffree(int size)
{
	int addr = 0;
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		if (addr == size) {
			currentNode->state = EMPTY;
			sort(currentNode);
			return;
		}
		addr = addr + (currentNode->data);
		currentNode = currentNode->next;
	}
	cout << "���� : free�� ��尡 �������� �ʽ��ϴ�" << endl;

	return;
}

void List::display()
{
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		if (currentNode->state == EMPTY) {
			cout << " s i z e  : " << currentNode->data << endl;
			Sleep(200);
			cout << "s t a t e : EMPTY" << endl;
			Sleep(200);
			cout << "      ��" << endl;
			currentNode = currentNode->next;
			Sleep(1000);
		}
		else {
			currentNode = currentNode->next;

		}
		
	}
	Sleep(300);
	cout << "     ��ħ" << endl;
	Sleep(1000);
	cout << endl << endl << "-----------------------------------------------" << endl;

}

void List::displayAll()
{
	cout << "�޸� ������ ����� ��� �޸𸮸� �����帳�ϴ�." << endl;
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
			cout << " s i z e  : " << currentNode->data << endl;
			Sleep(200);
			if (currentNode->state == EMPTY) {
				cout << "s t a t e : EMPTY" << endl;
			}
			else if (currentNode->state == FULL) {
				cout << "s t a t e : FULL" << endl;
			}
			Sleep(200);
			cout << "      ��" << endl;
			currentNode = currentNode->next;
			Sleep(1000);

	}
	Sleep(300);
	cout << "     ��ħ" << endl;
	Sleep(1000);
	cout << endl << endl << "-----------------------------------------------" << endl;

}

List::List(int MAX)
{
	if (MAX <= 0) {
		cout << "���� : 0�̻��� ���� �Է��Ͻÿ�" << endl;
	}
	else{
		Node* memoryNode = new Node;
		head = new Node;
		tail = new Node;
		head->before = nullptr;
		head->state = HEAD;
		head->data = INT_MAX;
		head->next = memoryNode;
		memoryNode->before = head;
		memoryNode->data = MAX;
		memoryNode->state = EMPTY;
		memoryNode->next = tail;
		tail->before = memoryNode;
		tail->data = INT_MAX;
		tail->state = TAIL;
		tail->next = nullptr;
		cout << "�ִ� �޸� ���� " << MAX << "���� �����ϼ̽��ϴ�." << endl<<endl<<endl;
	}
}


List::~List()
{
}

#include "List.h"
#include<iostream>

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
		else if (current->state == EMPTY && current->data > size) {
			if (temp > current->data - size) {
				temp = current->data - size;
				tempNode = current;
				current = current->next;
			}
			
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
	while (currentNode != findNode) {
		addr = addr + (currentNode->data);
		currentNode = currentNode->next;
	}

	return addr;
}

int List::ffree(int size)
{
	int addr = 0;
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		addr = addr + (currentNode->data);
		if (addr == size) {
			currentNode->state = EMPTY;
			sort(currentNode);
			return 0;
		}
		currentNode = currentNode->next;

	}
	return 0;
}

void List::display()
{
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		if (currentNode->state == EMPTY) {
			cout << "������ ũ�� : " << currentNode->data << " ���� : " << currentNode->state << "-> ";
			currentNode = currentNode->next;
		}
		else {
			currentNode = currentNode->next;

		}
		
	}
	cout << endl;
}

List::List(int MAX)
{
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
	cout << "�ִ� �޸� ���� " << MAX << "���� �����ϼ̽��ϴ�." << endl;
}


List::~List()
{
}

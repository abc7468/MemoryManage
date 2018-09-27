#include "List.h"
#include<iostream>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::search(int size) // ���� ������ �޸𸮰� �ִ��� ã���ְ� �� �ּҸ� ��ȯ�� �ִ� �Լ�
{
	
	Node* current = head;
	while (current->state != TAIL) {
		current = current->next;
		if (current->state == EMPTY && (current->data)>=size) {
			return current;
		}
	}
	cout << "������ �� �ִ� �޸𸮰� �����ϴ�." << endl;

	return 0;
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

int List::alloc(int size) // alloc����
{
	
	Node* allocNode = new Node;
	allocNode->data = size;
	allocNode->state = FULL;
	Node* findNode = search(size);
	findNode->data = (findNode->data) - size;
	findNode->before->next = allocNode;
	allocNode->before = findNode->before;
	findNode->before = allocNode;
	allocNode->next = findNode;
	int addr = findAddr(findNode, size);
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
		currentNode = currentNode->next;
		if (addr == size) {
			currentNode->state = EMPTY;
			sort(currentNode);
			return 0;
		}
	}
}

void List::display()
{
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		cout << "������ ũ�� : " << currentNode->data << " ���� : " << currentNode->state << "-> ";
		currentNode = currentNode->next;
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

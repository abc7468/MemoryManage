#include "List.h"
#include<iostream>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::search(int size)
{
	
	Node* current = head;
	while (current->state != EMPTY) {
		current = current->next;
		if (current->state == EMPTY && (current->data)>=size) {
			return current;
		}

	}
}

int List::sort()
{
	Node* currentNode = head;
	Node* orial = new Node;
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
	return 0;
}

void List::deleteNode(Node *orial)
{
	orial->next->data = orial->next->data + orial->data;
	orial->before->next = orial->next;
	orial->next->before = orial->before;
	free(orial);
}

void List::alloc(int size)
{
	Node* allocNode = new Node;
	allocNode->data = size;
	allocNode->state = FULL;
	Node* findNode = search(size);
	findNode->before->next = allocNode;
	allocNode->before = findNode->before;
	findNode->before = allocNode;
	allocNode->next = findNode;
	
}

void List::display()
{
	Node* currentNode = head->next;
	while (currentNode->state != TAIL) {
		cout << "데이터 크기 : " << currentNode->data << "상태 : " << currentNode->state << endl;
		currentNode = currentNode->next;
	}
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
	cout << "최대 메모리 값을 " << MAX << "으로 지정하셨습니다." << endl;
}


List::~List()
{
}

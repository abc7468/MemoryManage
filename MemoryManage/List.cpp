#include "List.h"
#include<iostream>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


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
	memoryNode->state = FULL;
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

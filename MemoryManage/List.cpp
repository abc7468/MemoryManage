#include "List.h"
#include<iostream>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::search(int size)
{
	int check = 1;
	Node* current = head;
	while (check == 1) {
		current = current->next;
		if (current->state == EMPTY && current->data>=size) {
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
	cout << "�ִ� �޸� ���� " << MAX << "���� �����ϼ̽��ϴ�." << endl;
}


List::~List()
{
}

#include "List.h"
#include<iostream>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::search(int size) // 저장 가능한 메모리가 있는지 찾아주고 그 주소를 반환해 주는 함수
{
	
	Node* current = head;
	while (current->state != TAIL) {
		current = current->next;
		if (current->state == EMPTY && (current->data)>=size) {
			return current;
		}
	}
	cout << "저장할 수 있는 메모리가 없습니다." << endl;

	return 0;
}

void List::sort(Node* orial) // 이어진 EMPTYNODE를 합쳐주는 함수
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

void List::deleteNode(Node *orial) //sort함수에서 낙동강오리알Node를 Free시켜주는 함수
{
	orial->next->data = orial->next->data + orial->data;
	orial->before->next = orial->next;
	orial->next->before = orial->before;
	delete orial;
	orial = nullptr;
}

int List::alloc(int size) // alloc역할
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
		cout << "데이터 크기 : " << currentNode->data << " 상태 : " << currentNode->state << "-> ";
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
	cout << "최대 메모리 값을 " << MAX << "으로 지정하셨습니다." << endl;
}


List::~List()
{
}

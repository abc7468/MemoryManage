#include "List.h"
#include<iostream>
#include<Windows.h>

#define HEAD 100
#define TAIL 101
#define FULL 1
#define EMPTY 0

using namespace std;


Node* List::fSearch(int size) // 저장 가능한 메모리가 있는지 찾아주고 그 주소를 반환해 주는 함수
{
	
	Node* current = head;
	while (current->state != TAIL) {
		current = current->next;
		if (current->state == EMPTY && (current->data)>=size) {
			return current;
		}
	}
	cout << "오류 : 저장할 수 있는 메모리가 없습니다." << endl;

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

int List::fAlloc(int size) // alloc역할
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
	cout << "오류 : free할 노드가 존재하지 않습니다" << endl;

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
			cout << "      ▼" << endl;
			currentNode = currentNode->next;
			Sleep(1000);
		}
		else {
			currentNode = currentNode->next;

		}
		
	}
	Sleep(300);
	cout << "     마침" << endl;
	Sleep(1000);
	cout << endl << endl << "-----------------------------------------------" << endl;

}

void List::displayAll()
{
	cout << "메모리 공간에 저장된 모든 메모리를 보여드립니다." << endl;
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
			cout << "      ▼" << endl;
			currentNode = currentNode->next;
			Sleep(1000);

	}
	Sleep(300);
	cout << "     마침" << endl;
	Sleep(1000);
	cout << endl << endl << "-----------------------------------------------" << endl;

}

List::List(int MAX)
{
	if (MAX <= 0) {
		cout << "오류 : 0이상의 값을 입력하시오" << endl;
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
		cout << "최대 메모리 값을 " << MAX << "으로 지정하셨습니다." << endl<<endl<<endl;
	}
}


List::~List()
{
}

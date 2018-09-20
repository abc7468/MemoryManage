#pragma once
class Node
{
private:
	int data;
	int state;
	Node* next;
	Node* before;
};
class List
{
private:
	Node* head;
	Node* tail;
public:
	int myalloc(int);
	int myfree(int);
	int sort();

	//test
	List(int);
	~List();
};


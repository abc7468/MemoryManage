#pragma once
class Node 
{
	friend class List;
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
protected:
	Node* fSearch(int);
	Node* bSearch(int);
	int fAlloc(int);
	int bAlloc(int);
	int findAddr(Node*, int);
	void sort(Node*);
	void ffree(int);
	void deleteNode(Node*);
	void display();
	void displayAll();

public:
	List() {};
	List(int);
	~List();
};


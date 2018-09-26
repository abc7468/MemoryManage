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
	Node* search(int);
	int sort();
	int alloc(int);
	int findAddr(Node*, int);
	void deleteNode(Node*);
	void display();

public:
	List() {};
	List(int);
	~List();
};


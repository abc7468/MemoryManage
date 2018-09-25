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
	void deleteNode(Node*);
	void alloc(int);
	void display();
public:
	List() {};
	List(int);
	~List();
};


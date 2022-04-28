#include "Header.h"


graphsort::LinkedList::Node::Node(int v, int value)
{
	this->v = v;
	this->value = value;
	this->next = nullptr;
}

graphsort::LinkedList::Node::Node()
{
	this->next = nullptr;
}

graphsort::LinkedList::Node::Node(int w_temp, int v, int value)
{
	this->v = v;
	this->value = value;
	this->w_temp = w_temp;
	this->next = nullptr;
}


graphsort::Graph::Graph(int ver)
{
	this->ver = ver;
}

void graphsort::Graph::add_edge(int v, int w, int value)
{
	LinkedList::Node* temp1 = new LinkedList::Node(w,value);
	LinkedList::Node* temp2 = new LinkedList::Node(v, value);
	

	if (list[v].head == nullptr) {
		list[v].head = temp1;
		list[v].tail = temp1;
	}
	else {
		list[v].tail->next = temp1;
		list[v].tail = temp1;
	}
	if (list[w].head==nullptr) {
		list[w].head = temp2;
		list[w].tail = temp2;
	}
	else {
		list[w].tail->next = temp2;
		list[w].tail = temp2;
	}

}


graphsort::LinkedList::Node::~Node()
{
	delete next;

}

graphsort::LinkedList::~LinkedList()
{
	
	while (head != nullptr) {
		Node* temp = head->next;
		delete head;
		head = temp;
	}

}


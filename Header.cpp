#include "Header.h"
#include <iostream>

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

void graphsort::Graph::mergesort(LinkedList::Node* all_edges, int const begin, int const end)
{

	if (begin >= end)
		return;

	int mid = begin + (end-begin)/2;
	mergesort(all_edges,begin,mid);
	mergesort(all_edges, mid+1, end);
	merge(all_edges, begin, mid, end);
	

}

void graphsort::Graph::sort_edges(int const n)
{
	bool* visited=new bool[n];
	LinkedList::Node* all_edges = new LinkedList::Node[n*n];
	int counter = 0;
	
	
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	

	for (int i = 0; i < n; i++) {
		LinkedList::Node* temp = list[i].head;
		while (list[i].head!=nullptr) {
			if (!visited[temp->v]) {
				LinkedList::Node temp_edge = LinkedList::Node(i, temp->v, temp->value);
				all_edges[counter] = temp_edge;
				counter++;
			}
			if (temp != list[i].tail)
				temp = temp->next;
			else
				break;
		}
		visited[i] = true;
	}
	//std::cout << " counter : " << counter;
	std::cout << "Was:\n";
	print_out_sorted(all_edges, counter);
	std::cout << '\n';

	mergesort(all_edges,0,counter-1);

	std::cout << "Now:\n";
	print_out_sorted(all_edges,counter);

}

void graphsort::Graph::merge(LinkedList::Node* all_edges, int const left, int const mid, int const right)
{

	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	LinkedList::Node* leftArray = new LinkedList::Node[subArrayOne];
	LinkedList::Node* rightArray = new LinkedList::Node[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = all_edges[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = all_edges[mid + 1 + j];

	int indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne].value <= rightArray[indexOfSubArrayTwo].value) {
			all_edges[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			all_edges[indexOfMergedArray] =rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayOne < subArrayOne) {
		all_edges[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		all_edges[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void graphsort::Graph::print_out_sorted(LinkedList::Node* all_edges, int end)
{
	for (int i = 0; i < end; i++) {
		std::cout << all_edges[i].w_temp << " <-> " << all_edges[i].v << "   value:  " << all_edges[i].value<<'\n';
	}

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


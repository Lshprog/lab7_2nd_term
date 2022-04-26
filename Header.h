#pragma once
namespace graphsort
{	
	struct LinkedList {
		struct Node {
			int v;
			int w_temp = 0;
			int value;
			Node* next;
			Node(int v, int value);
			Node();
			Node(int w_temp,int v, int value);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	};
	struct Graph {
		Graph(int ver);
		LinkedList *list;
		int ver;
		void mergesort(LinkedList::Node* all_edges,int const begin, int const end);
		void sort_edges(int const n);
		void merge(LinkedList::Node* all_edges,int const begin,int const mid ,int const end);
		void print_out_sorted(LinkedList::Node* all_edges,int end);
		void add_edge(int v,int w, int value);
	};
	

}
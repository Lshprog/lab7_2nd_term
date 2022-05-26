#pragma once
#include <string>
#include <iostream>

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
			~Node();
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		~LinkedList();
		
	};
	template <typename T> struct Stack {
		T arr[20] = { 0 };
		int index = 0;
		
		T pop()
		{
			T k = arr[index];
			if (index == 0)
				arr[index] = 0;
			else
				index--;
			return k;

		}
		
		void push(T value)
		{
			if (arr[index] == 0)
				arr[index] = value;
			else {
				index++;
				arr[index] = value;
			}

		}
	};
	struct Map {
		struct KeyVal {
			char key;
			int val;
			KeyVal* next;
			KeyVal(char key,int val);
		};
		KeyVal* tail=nullptr;
		KeyVal* head = nullptr;

		void addtomap(char key, int val);
		int give_val(char key);
	};
	struct Graph {
		Graph(int ver);
		Graph();
		LinkedList *list;
		int ver;
		void mergesort(LinkedList::Node* all_edges,int const begin, int const end);
		void sort_edges(int const n, std::string finish);
		void merge(LinkedList::Node* all_edges,int const begin,int const mid ,int const end);
		void print_out_sorted(LinkedList::Node* all_edges,int end);
		void add_edge(int v,int w, int value);
		std::string create_rpn(std::string func);
		int functionate(int value,std::string func);
		int read_file(const char* name);
		
	};
	

}
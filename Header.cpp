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

int graphsort::Graph::functionate(int value, std::string func)
{
	Stack<int> stack = Stack<int>();
	
	int i = 0;
	while (i < size(func)) {
		if ((int(func[i]) > 47 && int(func[i]) < 58)||func[i]=='x') {
			if(func[i] == 'x')
				stack.push(value);
			else
				stack.push(func[i]-'0');
		}
		else if (int(func[i]) == 42 || int(func[i]) == 45 || int(func[i]) == 43|| int(func[i]) == 47) {
			int result;
			int x, y;

			if (stack.arr[0] != 0) 
				x = stack.pop();
			
			if (stack.arr[0] != 0)
				y = stack.pop();
			else {
				
				return NULL;
			};

			if (int(func[i]) == 42)
				result = x * y;

			else if (int(func[i]) == 45)
				result = y - x;

			else if (int(func[i]) == 43)
				result = y + x;
			else if (int(func[i]) == 47)
				result = y / x;

			stack.push(result);

		}
		else {
			
			return NULL;
		}
		i++;
	}
	if(stack.index!=0)
		return NULL;
	return stack.pop();

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

void graphsort::Graph::sort_edges(int const n, std::string finish)
{
	bool* visited=new bool[n];
	LinkedList::Node* all_edges = new LinkedList::Node[n*n*2];
	LinkedList::Node* all_edges_before = new LinkedList::Node[n * n * 2];
	int counter = 0;
	
	
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	

	for (int i = 0; i < n; i++) {
		LinkedList::Node* temp = list[i].head;
		while (list[i].head!=nullptr) {
			if (!visited[temp->v]) {

				LinkedList::Node temp_edge_before = LinkedList::Node(i, temp->v, temp->value);
				all_edges_before[counter] = temp_edge_before;


				temp->value = functionate(temp->value, finish);
				if (temp->value == NULL) {
					std::cout << "Incorrect line !!! ";
					return;
				}
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
	print_out_sorted(all_edges_before, counter);
	std::cout << '\n';

	mergesort(all_edges,0,counter-1);

	std::cout << "Now:\n";
	print_out_sorted(all_edges,counter);
	
	delete []all_edges;
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
	
	delete []leftArray;
	delete []rightArray;
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

std::string graphsort::Graph::create_rpn(std::string func)
{
	std::string finish;
	int sizek = size(func);
	
	graphsort::Stack<char> stack = graphsort::Stack<char>();
	graphsort::Map mp = graphsort::Map();

	mp.addtomap('+',1);
	mp.addtomap('-', 1);
	mp.addtomap('*', 2);
	mp.addtomap('/', 2);
	mp.addtomap('(', 3);
	mp.addtomap(')', 3);


	for (int i = 0; i < sizek; i++) {
		if (func[i] == '+' || func[i] == '-' || func[i] == '/' || func[i] == '*' || func[i] == ')' || func[i] == '(') {
			if (stack.arr[0] == 0) {
				if (func[i] == ')') {
					std::cout << "Error";
					return NULL;
				}
				stack.push(func[i]);
			}

			else if (func[i] == ')') {
				while (stack.arr[stack.index] != '(') {
					if (stack.index == 0) {
						std::cout << "Error";
						return NULL;
					}
					
					finish += stack.pop();
				}
				char k = stack.pop();
				
			}
			else if (func[i] == '(' || mp.give_val(func[i]) > mp.give_val(stack.arr[stack.index]))
				stack.push(func[i]);

			else if (mp.give_val(func[i]) <= mp.give_val(stack.arr[stack.index])) {
				while ((mp.give_val(func[i]) <= mp.give_val(stack.arr[stack.index])) && (stack.arr[stack.index] != '(')) {
					
					finish += stack.pop();;
					if (stack.arr[0] == 0) {
						break;
					}
				}
				stack.push(func[i]);
			}
		}
		else
			finish += func[i];

	}
	while (stack.arr[0] != 0) 
		finish += stack.pop();
	
	
	std::cout << finish << std::endl;
	return finish;
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
template <typename T>
T graphsort::Stack<T>::pop()
{
	T k = arr[index];
	if (index == 0)
		arr[index] = 0;
	else
		index--;
	return k;

}
template <typename T>
void graphsort::Stack<T>::push(T value)
{
	if (arr[index] == 0)
		arr[index] = value;
	else {
		index++;
		arr[index] = value;
	}
	

}

graphsort::Map::KeyVal::KeyVal(char key, int val)
{
	this->key = key;
	this->val = val;
	this->next = nullptr;

}

void graphsort::Map::addtomap(char key,int val)
{
	KeyVal* node = new KeyVal(key,val);
	if (head == nullptr&&tail == nullptr) {
		tail = node;
		head = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
}

int graphsort::Map::give_val(char key)
{
	KeyVal* temp = head;
	while (true) {
		if (temp->key == key)
			return temp->val;
		if (temp->next == nullptr) {
			std::cout << "Error";
			return 0;
		}
		temp = temp->next;
	}
}

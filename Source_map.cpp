#include "Header.h"


graphsort::Map::KeyVal::KeyVal(char key, int val)
{
	this->key = key;
	this->val = val;
	this->next = nullptr;

}

void graphsort::Map::addtomap(char key, int val)
{
	KeyVal* node = new KeyVal(key, val);
	if (head == nullptr && tail == nullptr) {
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
#include "Header.h"


std::string graphsort::Graph::create_rpn(std::string func)
{
	std::string finish;
	int sizek = size(func);

	graphsort::Stack<char> stack = graphsort::Stack<char>();
	graphsort::Map mp = graphsort::Map();

	mp.addtomap('+', 1);
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


int graphsort::Graph::functionate(int value, std::string func)
{
	Stack<int> stack = Stack<int>();

	int i = 0;
	while (i < size(func)) {
		if ((int(func[i]) > 47 && int(func[i]) < 58) || func[i] == 'x') {
			if (func[i] == 'x')
				stack.push(value);
			else
				stack.push(func[i] - '0');
		}
		else if (int(func[i]) == 42 || int(func[i]) == 45 || int(func[i]) == 43 || int(func[i]) == 47) {
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
	if (stack.index != 0)
		return NULL;
	return stack.pop();

}


#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct Operation {

	char type = 0;
	int value = 0;
};

deque<string> make_expression_brackets(int initial_number) {
	int count_of_operations;
	cin >> count_of_operations;
	vector<Operation> operations(count_of_operations);
	for (int i = 0; i < count_of_operations; ++i) {
		cin >> operations[i].type;
		cin >> operations[i].value;
	}

	deque<string> expression;
	expression.push_back(to_string(initial_number));
	for (const auto& operation : operations) {
		expression.push_front("(");
		expression.push_back(") ");
		expression.push_back(string(1, operation.type));
		expression.push_back(" ");
		expression.push_back(to_string(operation.value));
	}

	return expression;

}

bool NeedBrackets(char last, char current) {
	return (last == '+' || last == '-') && (current == '*' || current == '/');
}

deque<string> make_expression(int initial_number) {
	int count_of_operations;
	cin >> count_of_operations;
	vector<Operation> operations(count_of_operations);
	for (int i = 0; i < count_of_operations; ++i) {
		cin >> operations[i].type;
		cin >> operations[i].value;
	}

	deque<string> expression;
	expression.push_back(to_string(initial_number));

	char last_type = '*';

	for (const auto& operation : operations) {
		if (NeedBrackets(last_type, operation.type)) {
			expression.push_front("(");
			expression.push_back(")");
		}
		expression.push_back(" ");
		expression.push_back(string(1, operation.type));
		expression.push_back(" ");
		expression.push_back(to_string(operation.value));

		last_type = operation.type;
	}

	return expression;
}


int main() {
	int initial_number;
	cin >> initial_number;

	/*deque<string> expression = make_expression_brackets(initial_number);

	for (const string& s : expression) {
		cout << s;
	}*/


	deque<string> expression = make_expression(initial_number);

	for (const string& s : expression) {
		cout << s;
	}

	return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Lang {
	string name;
	int age;
};

using LangIt = vector<string>::iterator;

void PrintRange(
	LangIt range_begin,
	LangIt range_end) {
	for (auto it = range_begin;
		it != range_end; ++it) {
		cout << *it << " ";
	}
}

int main() {
	vector<Lang> langs =
	{ {"Python", 26},
		{"C++", 34},
		{"C", 45},
		{"C#", 17 },
		{"Java", 22} };
	auto result = find_if(
		begin(langs), end(langs),
		[](const Lang& lang) {
			return lang.name[0] == 'C';
		});
	if (result == end(langs)) {
		cout << "Not found";
	}
	else {
		cout << result->age << endl;
	}

	return 0;
}
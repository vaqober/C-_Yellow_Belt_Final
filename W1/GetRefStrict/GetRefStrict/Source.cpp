#include <iostream>
#include <map>

using namespace std;

template <typename Key, typename Value>

Value& GetRefStrict(map<Key, Value>& m, Key key) {
	try {
		return m.at(key);
	}
	catch (const out_of_range& oor) {
		throw runtime_error("Out of Range error");
	}
}
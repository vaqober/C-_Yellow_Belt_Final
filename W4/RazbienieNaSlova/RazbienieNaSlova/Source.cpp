#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> SplitIntoWords(const string& str) {
    vector<string> result;

    auto str_begin = begin(str);
    const auto str_end = end(str);

    while (str_begin != str_end) {
        auto it = find(str_begin, str_end, ' ');
        result.push_back(string(str_begin, it));

        if (it == str_end) {
            break;
        }
        str_begin = it + 1;
    }

    return result;
}

/*int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}*/
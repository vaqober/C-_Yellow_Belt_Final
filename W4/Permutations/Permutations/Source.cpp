#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int range_length;
    cin >> range_length;
    vector<int> permutation(range_length);

    iota(permutation.begin(), permutation.end(), 1);

    reverse(permutation.begin(), permutation.end());

    do {
        for (int num : permutation) {
            cout << num << ' ';
        }
        cout << endl;
    } while (prev_permutation(permutation.begin(), permutation.end()));

    return 0;
}
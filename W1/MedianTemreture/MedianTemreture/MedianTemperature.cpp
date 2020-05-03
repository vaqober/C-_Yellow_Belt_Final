#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint64_t n;
    cin >> n;
    vector<long double> temperatures(n);
    long double sum = 0;
    for (long double& temperature : temperatures) {
        cin >> temperature;
        sum += temperature;
    }

    long double average = sum / n;
    vector<long double> result_indices;
    for (uint64_t i = 0; i < n; ++i) {
        if (temperatures[i] > average) {
            result_indices.push_back(i);
        }
    }

    cout << result_indices.size() << endl;
    for (long double result_index : result_indices) {
        cout << result_index << " ";
    }
    cout << endl;

    return 0;
}
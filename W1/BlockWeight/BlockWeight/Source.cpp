#include <iostream>
#include <string>

using namespace std;

int main() {
	int64_t n;
	int32_t r, w, h, d;
	uint64_t weight = 0;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> w >> h >> d;
		weight += w * h * d * r;
	}
	cout << weight;
	w, h, d, r = 0;
	return 0;
}
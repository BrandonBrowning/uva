
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int runs; cin >> runs;
	for (int run = 1; run <= runs; ++run) {
		int length; cin >> length;

		vector<int> values(length);
		for (int i = 0; i < length; ++i)
			cin >> values[i];

		// Find the median
		sort(values.begin(), values.end());
		int captain_position = (int)(length / 2);
		if (length % 2 == 0)
			--captain_position;

		cout << "Case " << run << ": " << values[(int)(length / 2)] << endl;
	}
}
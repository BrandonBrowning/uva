
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int events;
	cin >> events;

	vector<int> key;
	for (int i = 0; i < events; ++i) {
		int val;
		cin >> val;
		key.push_back(val);
	}

	while (true) {
		vector<int> student;
		int val;

		for (int i = 0; i < events; ++i) {
			bool success = cin >> val;

			if (!success) {
				return 0;
			}

			student.push_back(key[val - 1]);
		}

		int sum = 0;
		for (int i = 0; i < events - 1; ++i) {
			int diff = student[i + 1] - student[i];
			if (diff > 0)
				++sum;
		}

		++sum;

		cout << sum << endl;
	}
}

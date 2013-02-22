
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	string line;
	while (cin >> line) {
		if (line == "0")
			return 0;

		int sum = 0;
		for (int i = 0; i < line.size(); ++i) {
			int addition = (line[i] - '0') * (int)(pow(2, line.size() - i) - 1);
			sum += addition;

			cerr << "Added " << addition << " ";
		}
		cout << sum << endl;
	}

	return 0;
}

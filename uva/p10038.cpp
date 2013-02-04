
#include <iostream>

using namespace std;

int main() {
	bool diffs[3000 + 1];
	
	int total;
	while (cin >> total) {
		if (total == 1) {
			int trash; cin >> trash;
			cout << "Jolly" << endl;
			continue;
		}
	
		// reset diffs
		for (int i = 0; i < 3000 + 1; ++i)
			diffs[i] = false;
			
		int left, right;
		cin >> left;
		for (int i = 0; i < total - 1; ++i) {
			cin >> right;
			int diff = left - right;
			
			left = right;
			
			if (diff < 0)
				diff *= -1;
			
			diffs[diff] = true;
		}
		
		bool broke = false;
		for (int i = 1; i <= total - 1; ++i) {
			if (!diffs[i]) {
				broke = true;
				break;
			}	
		}
		
		cout << (broke ? "Not jolly" : "Jolly") << endl;
	}

	return 0;
}

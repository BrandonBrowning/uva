
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int runs; cin >> runs;
	for (int run = 0; run < runs; ++run) {
		int ncars; cin >> ncars;
		
		vector<int> cars;
		for (int i = 0; i < ncars; ++i) {
			int car; cin >> car;
			cars.push_back(car);
		}
		
		int swaps = 0;
		for (int pass = 0; pass < ncars; ++pass) {
			for (int pos = 0; pos < ncars - 1; ++pos) {
				if (!(cars[pos] < cars[pos+1])) {
					int temp = cars[pos];
					cars[pos] = cars[pos+1];
					cars[pos+1] = temp;
					
					++swaps;
				}
			}
		}
		
		cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
	}

	return 0;
}

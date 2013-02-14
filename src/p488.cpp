
#include <iostream>

using namespace std;

int main() {
	int runs; cin >> runs;
	for (int run = 0; run < runs; ++run) {
		int amp, freq; cin >> amp >> freq;
		
		for (int i = 0; i < freq; ++i) {
			for (int j = 1; j <= amp; ++j)
				cout << string(j, (char)(j + (int)'0')) << endl;
			for (int j = amp - 1; j >= 1; --j)
				cout << string(j, (char)(j + (int)'0')) << endl;
				
			if (i != freq - 1)
				cout << endl;
		}
		
		cout << endl << endl;
	}
}

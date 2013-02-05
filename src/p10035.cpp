
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	while (true) {
		string top_raw, bottom_raw; cin >> top_raw >> bottom_raw;
		if (top_raw == "0" && bottom_raw == "0")
			return 0;
			
		cerr << "\t" << top_raw << endl << "\t" << bottom_raw << endl;
			
		string top = string(9 - top_raw.size(), '0').append(top_raw);
		string bottom = string(9 - bottom_raw.size(), '0').append(bottom_raw);
		
		cerr << "\t" << top << endl << "\t" << bottom << endl;
		
		int carries = 0;
		int carry = 0;
		for (int i = 8; i >= 0; --i) {
			int total = (top[i] - '0') + (bottom[i] - '0') + carry;
			carry = 0;
			
			if (total > 9) {
				++carries;
				carry = 1;
			}
		}
		
		if (carries == 0)
			cout << "No carry operation." << endl;
		else
			cout << carries << " carry operation" << (carries == 1 ? "" : "s") << "." << endl;
	}
}

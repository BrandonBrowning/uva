
// For every single-digit-group, there needs to be a
// multi-digit-group of the same letter on the right
// which is uniquely used to cancel that group.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int runs; cin >> runs;
	for (int run = 0; run < runs; ++run) {
		string s; cin >> s;

		vector<char> symbols;
		for (int i = 0; i < s.size(); ) {
			char first = s[i];
			bool streak = false;

			++i;
			while (s[i] == first && i < s.size()) {
				++i;
				streak = true;
			}

			char symbol = (streak ? 'A' - 'a' : 0) + first;
			symbols.push_back(symbol);
		}

		for (int i = 0; i < symbols.size(); ++i)
			cerr << (i == 0 ? "" : " ") << symbols[i];
		cerr << endl;

		int i = symbols.size() - 1;
		while (i >= 0) {
			if (symbols[i] == 'a' || symbols[i] == 'b') {
				bool found = false;
				for (int j = i; j < symbols.size(); )
			}
		}
	}

	return 0;
}
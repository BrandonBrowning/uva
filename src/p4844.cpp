
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int a = 1;
int aa = 2;
int b = 3;
int bb = 4;

/// abbaababbaaa
/// aBAbaBA
bool problemRight(vector<int> & symbols) {
	for (int i = symbols.size() - 1; i >= 0; --i) {
		int at = symbols[i];

		if (at == a || at == b) {
			if (i == symbols.size() - 1)
				return false;

			int looking_for = at == a ? aa : bb;

			++i;
			while (symbols[i] != looking_for) {
				if (i == symbols.size() - 1) {
					return false;
				}

				symbols.erase(symbols.begin() + i);
			}

			--i;
			symbols.erase(symbols.begin() + i);
		}
	}

	return true;
}

bool problemLeft(vector<int> & symbols) {
	for (int i = 0; i < symbols.size(); ++i) {
		int at = symbols[i];

		if (at == a || at == b) {
			if (i == 0)
				return false;

			int looking_for = at == a ? aa : bb;

			--i;
			while (symbols[i] != looking_for) {
				if (i == 0) {
					return false;
				}

				symbols.erase(symbols.begin() + i);
			}

			++i;
			symbols.erase(symbols.begin() + i);
		}
	}

	return true;
}

int main() {
	int runs; cin >> runs;
	for (int run = 0; run < runs; ++run) {
		string line; cin >> line;

		vector<int> symbols;
		vector<int> symbols2;
		for (int i = 0; i < line.size(); ++i) {
			char at = line[i];
			char next = (i == line.size() - 1 ? '\0' : line[i+1]);
			
			if (at == next) {
				symbols.push_back(at == 'a' ? aa : bb);
				symbols2.push_back(at == 'a' ? aa : bb);
				while(line[i] == at && i < line.size())
					++i;
				--i;
			} else {
				symbols.push_back(at == 'a' ? a : b);
				symbols2.push_back(at == 'a' ? a : b);
			}
		}
		
		cout << (problemRight(symbols) || problemLeft(symbols2)) << endl;
	}

	return 0;
}

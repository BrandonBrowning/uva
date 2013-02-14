
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int main() {
	int runs; cin >> runs;
	cin.ignore(1, '\n');
	
	for (int run = 0; run < runs; ++run) {
		string line; getline(cin, line);
		
		int vals[26];
		for (int i = 0; i < 26; ++i)
			vals[i] = 0;
		
		int max_val = 0;
		for (int i = 0; i < line.size(); ++i) {
			int dist = tolower(line[i]) - 'a';
			
			if (dist < 0 || dist > 25)
				continue;
			
			++vals[dist];
			max_val = max(max_val, vals[dist]);
		}
		
		for (int i = 0; i < 26; ++i) {
			if (vals[i] == max_val)
				cout << (char)((int)'a' + i);
		}
		
		cout << endl;
	}

	return 0;
}

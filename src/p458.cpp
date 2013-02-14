
#include <iostream>
#include <string>

using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.size(); ++i) {
			cout << (char)((int)line[i] - 7);
		}
		cout << endl;
	}
	
	return 0;
}

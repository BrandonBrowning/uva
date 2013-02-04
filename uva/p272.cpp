
#include <iostream>

using namespace std;

int main() {
	bool first = true;
	char c;
	while (cin.get(c))
		if (c == '"') {
			if (first) {
				cout << "``";
			} else {
				cout << "''";
			}
			
			first = !first;
		} else cout << c;
	
	return 0;
}

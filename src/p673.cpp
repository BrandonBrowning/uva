
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int runs; cin >> runs;
	cin.ignore(1, '\n');
	for (int run = 0; run < runs; ++run) {
		stack<char> cs;
		
		string line;
		getline(cin, line);
		
		if (line == "") {
			cout << "Yes" << endl;
			continue;
		}
		
		bool breaked = false;
		for (int i = 0; i < line.size(); ++i) {
			char c = line[i];
			if (c == '(' || c == '[')
				cs.push(c);
			else {
				if (cs.size() == 0) {
					breaked = true;
					break;
				}
			
				char top = cs.top();
				if ((c == ')' && top == '(') || (c == ']' && top == '['))
					cs.pop();
			}
		}
		
		cout << ((breaked || cs.size() != 0) ? "No" : "Yes") << endl;
	}
	
	return 0;
}

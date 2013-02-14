
#include <iostream>

using namespace std;

int main() {
	int field = 1;
	while (true) {
		int nrow, ncol;
		cin >> nrow >> ncol;
		
		if (nrow == 0 && ncol == 0)
			return 0;

		char ** vals = new char*[nrow];
		for (int x = 0; x < nrow; ++x)
			vals[x] = new char[ncol];
		
		char c;
		for (int x = 0; x < nrow; ++x) {
			for (int y = 0; y < ncol; ++y) {
				cin >> c;
				vals[x][y] = (c == '.' ? '0' : c);
			}
		}

		for (int x = 0; x < nrow; ++x)
			for (int y = 0; y < ncol; ++y)
				if (vals[x][y] == '*')
					for (int dx = -1; dx <= 1; ++dx)
						for (int dy = -1; dy <= 1; ++dy)
							if (!(dx == 0 && dy == 0))
								if (x + dx >= 0 && x + dx < nrow && y + dy >= 0 && y + dy < ncol) 
									if (vals[x + dx][y + dy] != '*') {
										++vals[x + dx][y + dy];
									}

		if (field != 1)
			cout << endl;

		cout << "Field #" << field << ":" << endl;
		for (int x = 0; x < nrow; ++x) {
			for (int y = 0; y < ncol; ++y) {
				cout << vals[x][y];
			}

			cout << endl;
		}

		++field;
				
	}

	return 0;
}

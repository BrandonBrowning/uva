#include <iostream>
using namespace std;
int abs(int x) { return x < 0 ? -x : x; }
int main() {
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2 && x1 + y1 + x2 + y2 != 0) {
		int zero = x1 == x2 && y1 == y2;
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		int diag = (dx == 0) || (dy == 0) || (dx == dy);
		cout << (zero?!zero:(diag^1)+1) << endl;
	}
}

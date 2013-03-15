
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int run = 1;
	while (true) {
		double n; cin >> n;

		if (n < 3)
			return 0;

		double area; cin >> area;

		double pi = 4 * atan(1);
		double apothem = sqrt(area / (n * tan(pi / n)));
		double radius  = apothem / cos(pi / n);
		cerr << "\tapothem=" << apothem << endl;
		cerr << "\tradius=" << radius << endl;
		double official = area - (pi * apothem * apothem);
		double spectator = (pi * radius * radius) - area;
		cerr << "\tofficial=" << official << endl;
		cerr << "\tspectator=" << spectator << endl;

		cout << setprecision(5);
		cout << "Case " << run << ": ";
		cout << spectator << " " << official << endl;

		++run;
	}

	return 0;
}
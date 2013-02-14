
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	char buffer[32];
	for (int i = 0; i < 32; ++i)
		buffer[i] = '\0';

	int runs;
	cin >> runs;

	for (int run = 0; run < runs; ++run) {
		int adds = 0;

		long long x;
		cin >> x;

		while (true) {
			sprintf(buffer, "%Ld", x);
			string s = buffer;

			int last = s.size() - 1;
			int half = (int)(last / 2);
			bool palindrome = true;
			for (int i = 0; i <= half; ++i) {
				if (s[i] != s[last - i]) {
					palindrome = false;
					break;
				}
			}

			if (palindrome) {
				cout << adds << " " << s << endl;
				break;
			}

			string s_rev(s);
			reverse(s_rev.begin(), s_rev.end());

			long x2 = atol(s_rev.c_str());
			x += x2;

			++adds;
		}
	}

	return 0;
}

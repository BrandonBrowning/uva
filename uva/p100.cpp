
#include <iostream>

using namespace std;

// Super-efficient version of 3n+1 range maximum problem
void p100() {
    const int cap = 1000000 + 1;

    int *cycle = new int[cap];
    for (int i = 0; i < cap; ++i)
        cycle[i] = 0;

    cycle[1] = 1;

    for (int i = 2; i < cap; ++i) {
        int len = 1;

        long long n = i;
        while (true) {
            if (n < cap && cycle[n] != 0) {
                cycle[i] = len + cycle[n] - 1;
                break;
            }
            
            if (n % 2 == 0) {
                n /= 2;

                ++len;
            } else {
                n = (3 * n) + 1;

                ++len;
            }

            if (n == 1) {
                cycle[i] = len;
                break;
            }
        }
    }

    int from, to = 0;
    while (cin >> from >> to) {
        int smaller = min(from, to);
        int larger  = max(from, to);

        int max = -1;
        for (int i = smaller; i <= larger; ++i) {
            int x = cycle[i];
            
            if (x > max)
                max = x;
        }

        cout << from << " " << to << " " << max << endl;
    }
}
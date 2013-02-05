
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class answer {
public:
    string assortment;
    int total;
};

struct sorter {
    bool operator()(const answer & l, const answer & r) {
        if (l.total == r.total)
            return l.assortment.compare(r.assortment) == -1 ? true : false;
        else
            return l.total < r.total;
    }
};

string toAssortment(int i) {
    if (i == 0) return "B";
    if (i == 1) return "C";
    return "G";
}

void p102() {
    // (bin id) (b, c, g)
    int bins[3][3];

    int first;
    while (cin >> first) {
        // input b, g, c -> bin b, c, g

        bins[0][0] = first;
        cin >> bins[0][2] >> bins[0][1];
        for (int i = 1; i <= 2; ++i)
            cin >> bins[i][0] >> bins[i][2] >> bins[i][1];
        
        // i, j, k are the selections for first through third bins

        vector<answer> answers;
        for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 3; ++k) {
            if (i == j || i == k || j == k) continue;

            answer a;
            a.assortment = toAssortment(i) + toAssortment(j) + toAssortment(k);
            a.total = bins[1][i] + bins[2][i];
            a.total += bins[2][j] + bins[0][j];
            a.total += bins[0][k] + bins[1][k];

            answers.push_back(a);
        }

        sort(answers.begin(), answers.end(), sorter());

        cout << answers[0].assortment << " " << answers[0].total << endl;
    }
}
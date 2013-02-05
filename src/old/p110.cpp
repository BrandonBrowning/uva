
#include <iostream>

using namespace std;

char intToChar(int n) {
    return 'a' + n;
}

void indent(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "  ";
    }
}

void p110() {
    int cs; cin >> cs;

    for (int c = 1; c <= cs; ++c) {
        int n; cin >> n;

        cout << "program sort(input,output);" << endl << "var" << endl;
        for (int i = 0; i < n; ++i) {
            cout << intToChar(i);
            if (n - i > 1)
                cout << ',';
        }

        cout << " : integer;" << endl << "begin" << endl;

        int indentation = 1;
        indent(indentation);
        cout << "readln(";
        for (int i = 0; i < n; ++i) {
            cout << intToChar(i);
            if (n - i > 1)
                cout << ',';
        }
        cout << ");" << endl;

        cout << "end." << endl;
    }
}
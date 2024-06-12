#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int order;

string s[2];

void turn() {
    char tmp = s[1][1];
    s[1][1] = s[1][0];
    s[1][0] = s[0][0];
    s[0][0] = s[0][1];
    s[0][1] = tmp;
}

int main() {
    FastIO

    char c;
    cin >> c;

    cin >> s[0] >> s[1];

    if (c == 'E') {
        order = 3;
    }
    else if (c == 'W') {
        order = 1;
    }
    else if (c == 'S') {
        order = 0;
    }
    else if (c == 'N') {
        order = 2;
    }

    for (int i = 0; i < order; i++) {
        turn();
    }

    if (s[0] == ".O" && s[1] == "P.") {
        cout << "T";
    }
    else if (s[0] == "I." && s[1] == ".P") {
        cout << "F";
    }
    else if (s[0] == "O." && s[1] == ".P") {
        cout << "Lz";
    }
    else {
        cout << "?";
    }


    return 0;
}
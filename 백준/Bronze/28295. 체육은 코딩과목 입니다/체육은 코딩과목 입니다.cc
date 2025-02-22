#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int now = 0;

    for (int i = 0; i < 10; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            now += 1;
            now %= 4;
        }
        else if (order == 2) {
            now += 2;
            now %= 4;
        }
        else if (order == 3) {
            now += 3;
            now %= 4;
        }
    }

    if (now == 0) {
        cout << "N";
    }
    else if (now == 1) {
        cout << "E";
    }
    else if (now == 2) {
        cout << "S";
    }
    else if (now == 3) {
        cout << "W";
    }

    return 0;
}
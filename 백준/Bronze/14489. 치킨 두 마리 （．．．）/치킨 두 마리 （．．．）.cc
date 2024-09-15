#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B;
    cin >> A >> B;
    int C;
    cin >> C;

    if (A + B >= C + C) {
        cout << A + B - C * 2;
    }
    else {
        cout << A + B;
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int V;
string s;

int main() {
    FastIO

    cin >> V;
    cin >> s;

    int ans = 0;

    for (char i : s) {
        if (i == 'A') ans++;
    }

    if (ans > V / 2) cout << 'A';
    else if (ans == V - ans) cout << "Tie";
    else cout << 'B';

    return 0;
}
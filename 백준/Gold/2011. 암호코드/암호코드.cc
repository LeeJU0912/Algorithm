#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
int DP[5001];

int main() {
    FastIO

    cin >> s;

    if (s[s.length() - 1] == '0') {
        if (s[s.length() - 2] > '2') {
            cout << 0;
            return 0;
        }
    }
    if (s[0] == '0') {
        cout << 0;
        return 0;
    }

    DP[0] = 1;

    for (int i = 0; i < s.length(); i++) {
        DP[i] %= 1000000;
        if (i < s.length() - 1) {
            if (s[i] == '2' && s[i + 1] <= '6') {
                DP[i + 2] += DP[i];
            }
            else if (s[i] == '1') {
                DP[i + 2] += DP[i];
            }
        }
        if (s[i] == '0') continue;
        DP[i + 1] += DP[i];
    }

    cout << DP[s.length()] % 1000000;

    return 0;
}
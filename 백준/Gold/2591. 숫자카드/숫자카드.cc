#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
int DP[41];

int main() {
    FastIO

    cin >> s;

    DP[0] = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0') {
            DP[i] += DP[i - 1];
        }

        if (s[i - 1] == '0') continue;
        if ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 34) {
            if (i == 1) DP[i]++;
            else DP[i] += DP[i - 2];
        }
    }

    cout << DP[s.size() - 1];

    return 0;
}
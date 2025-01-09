#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char now = s[i];

        if (now == 'C' || now == 'A' || now == 'M' || now == 'B' || now == 'R' || now == 'I' || now == 'D' || now == 'G' || now == 'E') {
            continue;
        }
        cout << now;
    }

    return 0;
}
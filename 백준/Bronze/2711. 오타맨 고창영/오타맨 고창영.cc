#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int n;
        string s;
        cin >> n >> s;
        n--;
        for (int i = 0; i < s.size(); i++) {
            if (i == n) continue;
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}
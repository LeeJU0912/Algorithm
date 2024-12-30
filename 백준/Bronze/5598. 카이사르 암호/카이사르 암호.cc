#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i] - 3;

        if (c < 'A') {
            c += 26;
        }

        cout << c;
    }
    
    return 0;
}
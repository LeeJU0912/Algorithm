#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    int joi = 0;
    int ioi = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            joi++;
        }
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            ioi++;
        }
    }

    cout << joi << '\n' << ioi;

    return 0;
}
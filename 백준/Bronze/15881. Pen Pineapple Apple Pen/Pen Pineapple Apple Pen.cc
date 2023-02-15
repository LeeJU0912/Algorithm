#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 0; i < N - 3; i++) {
        if (s[i] == 'p' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'p') {
            i += 3;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
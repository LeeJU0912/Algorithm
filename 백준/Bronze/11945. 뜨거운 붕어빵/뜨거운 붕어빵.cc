#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = s.size() - 1; j >= 0; j--) {
            cout << s[j];
        }
        cout << '\n';
    }

    return 0;
}
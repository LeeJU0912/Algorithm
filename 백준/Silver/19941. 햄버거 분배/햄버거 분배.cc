#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;

bool table[20001];

int main() {
    FastIO

    cin >> N >> K;

    string s;
    cin >> s;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'H') {
            for (int j = -K; j <= K; j++) {
                if (i + j < 0 || i + j >= N) continue;
                if (table[i + j]) continue;
                if (s[i + j] == 'P') {
                    table[i + j] = true;
                    break;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'P' && table[i]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
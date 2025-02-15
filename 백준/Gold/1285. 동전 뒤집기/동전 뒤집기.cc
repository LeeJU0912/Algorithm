#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool board[20][20];
int status[20];

int ans = INT_MAX;

void solve(int idx) {
    if (idx == N) {
        int hap = 0;
        for (int i = 1; i <= 1 << (N - 1); i <<= 1) {
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (status[j] & i) cnt++;
            }
            hap += min(N - cnt, cnt);
        }
        ans = min(ans, hap);
        return;
    }

    for (int i = idx; i < N; i++) {
        status[i] = ~status[i];
        solve(i + 1);
        status[i] = ~status[i];
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int bit = 1;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'H') {
                status[i] |= bit;
            }
            bit <<= 1;
        }
    }

    solve(0);

    cout << ans;

    return 0;
}
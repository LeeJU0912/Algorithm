#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int DP[301][20];
int save[301][20];

int ans;
int ans2[20];
int realAns[20];

void solve(int idx, int hap, int cost) {
    if (hap == N) {
        if (ans < cost) {
            ans = cost;
            for (int i = 0; i < M; i++) {
                realAns[i] = ans2[i];
            }
        }
        return;
    }
    if (idx == M) return;
    if (DP[hap][idx] >= cost) return;
    DP[hap][idx] = cost;
    
    for (int i = 0; i <= N - hap; i++) {
        ans2[idx] = i;
        solve(idx + 1, hap + i, cost + save[i][idx]);
        ans2[idx] = 0;
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int cost;
        cin >> cost;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            save[i][j] = x;
        }
    }

    memset(DP, -1, sizeof(DP));

    for (int i = 0; i <= N; i++) {
        ans2[0] = i;
        solve(1, i, save[i][0]);
        ans2[0] = 0;
    }

    cout << ans << '\n';
    for (int i = 0; i < M; i++) {
        cout << realAns[i] << ' ';
    }

    return 0;
}
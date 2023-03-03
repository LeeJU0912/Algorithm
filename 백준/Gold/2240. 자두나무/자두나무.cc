#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T, moving;
vector<int> falling;
int ans;
int DP[2][1001][31];

void solve(int now_tree, int idx, int counter, int hap) {
    if (counter > moving) return;

    if (now_tree == falling[idx] - 1) hap++;
    if (idx == T) {
        ans = max(ans, hap);
        return;
    }

    if (DP[now_tree][idx][counter] == -1) {
        DP[now_tree][idx][counter] = hap;
    }
    else if (DP[now_tree][idx][counter] < hap) {
        DP[now_tree][idx][counter] = hap;
    }
    else return;

    solve(now_tree, idx + 1, counter, hap);
    if (idx < T - 1 && falling[idx] != falling[idx + 1]) {
        solve(!now_tree, idx + 1, counter + 1, hap);
    }
}

int main() {
    FastIO

    cin >> T >> moving;

    falling = vector<int>(T);

    for (int i = 0; i < T; i++) {
        cin >> falling[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= 1000; j++) {
            for (int k = 0; k <= 30; k++) {
                DP[i][j][k] = -1;
            }
        }
    }

    solve(0, 0, 0, 0);
    solve(1, 0, 1, 0);

    cout << ans;

    return 0;
}
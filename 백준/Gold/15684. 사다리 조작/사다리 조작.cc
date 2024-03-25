#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, H;
bool chk[11][11][31];

int ans = INT_MAX;

bool chk_ladder() {
    for (int i = 1; i <= N; i++) {
        int now_n = i;
        for (int j = 1; j <= H; j++) {
            if (now_n == 1) {
                if (chk[now_n][now_n + 1][j]) now_n++;
            }
            else if (now_n == N) {
                if (chk[now_n - 1][now_n][j]) now_n--;
            }
            else {
                if (chk[now_n][now_n + 1][j]) now_n++;
                else if (chk[now_n - 1][now_n][j]) now_n--;
            }
        }

        if (now_n != i) return false;
    }
    return true;
}

void build_ladder(int counter, int idx) {
    if (chk_ladder()) {
        ans = min(ans, counter);
        return;
    }

    if (counter == 3) return;

    for (int i = idx; i < N; i++) {
        for (int j = 1; j <= H; j++) {
            if (chk[i][i + 1][j]) continue;
            if (i > 1) {
                if (chk[i][i - 1][j]) continue;
            }

            chk[i][i + 1][j] = true;
            chk[i + 1][i][j] = true;

            build_ladder(counter + 1, i);

            chk[i][i + 1][j] = false;
            chk[i + 1][i][j] = false;
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        chk[b][b + 1][a] = true;
        chk[b + 1][b][a] = true;
    }

    build_ladder(0, 1);

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
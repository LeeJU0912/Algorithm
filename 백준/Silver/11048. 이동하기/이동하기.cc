#include <bits/stdc++.h>
using namespace std;

int N, M;

int maze[1001][1001];
int save[1001][1001];

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            save[i][j] = max(save[i - 1][j - 1], max(save[i - 1][j], save[i][j - 1])) + maze[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }

    solve();

    cout << save[N][M];

    return 0;
}
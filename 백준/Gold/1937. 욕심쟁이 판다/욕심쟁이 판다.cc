#include <bits/stdc++.h>
using namespace std;

int n;
int graph[500][500];
int save[500][500];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

int solve(int x, int y) {
    if (save[x][y]) return save[x][y];

    save[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
        if (graph[x][y] >= graph[next_x][next_y]) continue;

        save[x][y] = max(save[x][y], solve(next_x, next_y) + 1);
    }
    return save[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, solve(i, j));
        }
    }

    cout << ans;

    return 0;
}
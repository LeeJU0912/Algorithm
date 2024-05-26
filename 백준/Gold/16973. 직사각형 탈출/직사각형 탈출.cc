#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, H, W, Sr, Sc, Fr, Fc;
bool board[1001][1001];
bool visited[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = -1;

bool validation(int x, int y) {
    for (int i = x; i < x + H; i++) {
        if (board[i][y] || board[i][y + W - 1]) return true;
    }
    for (int j = y; j < y + W; j++) {
        if (board[x][j] || board[x + H - 1][j]) return true;
    }
    return false;
}

void solve() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{Sr, Sc}, 0});
    visited[Sr][Sc] = true;

    while(!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int now_counter = q.front().second;
        q.pop();

        if (now_x == Fr && now_y == Fc) {
            ans = now_counter;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x <= 0 || next_x > N - H + 1 || next_y <= 0 || next_y > M - W + 1) continue;
            if (visited[next_x][next_y]) continue;
            if (validation(next_x, next_y)) continue;
            visited[next_x][next_y] = true;
            q.push({{next_x, next_y}, now_counter + 1});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    cin >> H >> W;
    cin >> Sr >> Sc;
    cin >> Fr >> Fc;

    solve();

    cout << ans;

    return 0;
}
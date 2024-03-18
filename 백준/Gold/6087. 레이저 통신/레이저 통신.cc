#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int W, H;

int board[101][101];
int chk[101][101][4];
vector<pair<int, int>> C;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

void solve() {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < 4; i++) {
        int next_x = C[0].first + dx[i];
        int next_y = C[0].second + dy[i];

        if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
        if (board[next_x][next_y] == 1) continue;
        pq.push({{0, i}, {next_x, next_y}});
    }

    while(!pq.empty()) {
        int counter = pq.top().first.first;
        int dist = pq.top().first.second;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if (now_x == C[1].first && now_y == C[1].second) {
            ans = counter;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
            if (board[next_x][next_y] == 1) continue;
            if (dist == i) {
                if (chk[next_x][next_y][i] <= counter) continue;
                pq.push({{counter, i}, {next_x, next_y}});
                chk[next_x][next_y][i] = counter;
            }
            else {
                if (chk[next_x][next_y][i] <= counter + 1) continue;
                pq.push({{counter + 1, i}, {next_x, next_y}});
                chk[next_x][next_y][i] = counter + 1;
            }
        }
    }
}

int main() {
    FastIO

    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < W; j++) {
            if (s[j] == '*') {
                board[i][j] = 1;
            }
            else if (s[j] == 'C') {
                board[i][j] = 2;
                C.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                chk[i][j][k] = INT_MAX;
            }
        }
    }

    solve();

    cout << ans;

    return 0;
}
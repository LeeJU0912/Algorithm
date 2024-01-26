#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;

bool board[1500][1500];
bool visited[1500][1500];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> ducks;

queue<pair<int, int>> q, pre_q;
queue<pair<int, int>> water, pre_water;

void melt() {
    water = pre_water;
    pre_water = queue<pair<int, int>>();

    while(!water.empty()) {
        auto now = water.front();
        water.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
            if (!board[next_x][next_y]) continue;
            board[next_x][next_y] = false;
            pre_water.push({next_x, next_y});
        }
    }
}

bool connected() {
    q = pre_q;
    pre_q = queue<pair<int, int>>();

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.first == ducks[1].first && now.second == ducks[1].second) return true;

        for (int j = 0; j < 4; j++) {
            int next_x = now.first + dx[j];
            int next_y = now.second + dy[j];

            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (board[next_x][next_y]) {
                pre_q.push({next_x, next_y});
            }
            else {
                q.push({next_x, next_y});
            }
        }
    }

    return false;
}

int solve() {
    int ans = 0;

    pre_q.push(ducks[0]);
    visited[ducks[0].first][ducks[0].second] = true;

    while(!connected()) {
        melt();
        ans++;
    }

    return ans;
}

int main() {
    FastIO

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++) {
            if (s[j] == 'X') board[i][j] = true;
            else if (s[j] == 'L') ducks.push_back({i, j});

            if (!board[i][j]) {
                pre_water.push({i, j});
            }
        }
    }

    cout << solve();

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L, R;
int board[51][51];
bool visited[51][51];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans;

bool chk() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];
                if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > N) continue;
                if (abs(board[i][j] - board[next_x][next_y]) >= L && abs(board[i][j] - board[next_x][next_y]) <= R) return true;
            }
        }
    }
    return false;
}

void move(int x, int y) {
    int hap = board[x][y];
    vector<pair<int, int>> save;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        save.push_back({now_x, now_y});

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > N) continue;
            if (abs(board[next_x][next_y] - board[now_x][now_y]) < L || abs(board[next_x][next_y] - board[now_x][now_y]) > R) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            hap += board[next_x][next_y];
            q.push({next_x, next_y});
        }
    }

    if (!save.empty()) {
        hap /= save.size();

        for (int i = 0; i < save.size(); i++) {
            int now_x = save[i].first;
            int now_y = save[i].second;

            board[now_x][now_y] = hap;
        }
    }
}

int main() {
    FastIO

    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    while(chk()) {
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visited[i][j]) continue;
                if (board[i][j] == 0) continue;
                move(i, j);
            }
        }

        ans++;
    }

    cout << ans;

    return 0;
}
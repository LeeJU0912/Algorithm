#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[50][50];
bool visited[50][50];

bool chk[10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> virus;

int ans = INT_MAX;

int search() {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++) {
        if (chk[i]) {
            q.push(virus[i]);
            visited[virus[i].first][virus[i].second] = true;
        }
    }

    int tmp = 0;
    while(!q.empty()) {
        bool moved = false;

        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto now = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_x = now.first + dx[j];
                int next_y = now.second + dy[j];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
                if (board[next_x][next_y] == 1) continue;
                if (visited[next_x][next_y]) continue;
                visited[next_x][next_y] = true;

                moved = true;

                q.push({next_x, next_y});
            }
        }

        if (moved) tmp++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 1 && !visited[i][j]) {
                return INT_MAX;
            }
        }
    }

    return tmp;
}

void solve(int idx, int counter) {
    if (counter == M) {
        ans = min(ans, search());
        return;
    }

    for (int i = idx + 1; i < virus.size(); i++) {
        chk[i] = true;
        solve(i, counter + 1);
        chk[i] = false;
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
        }
    }

    for (int i = 0; i < virus.size(); i++) {
        chk[i] = true;
        solve(i, 1);
        chk[i] = false;
    }

    cout << ((ans == INT_MAX) ? -1 : ans);

    return 0;
}
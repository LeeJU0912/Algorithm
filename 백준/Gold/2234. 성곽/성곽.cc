#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int board[50][50];
bool visited[50][50];
pair<int, int> save[50][50];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int ans1, ans2, ans3;

void solve1(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    vector<pair<int, int>> tmp;
    int temp = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        temp++;
        tmp.push_back(now);

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if ((board[now.first][now.second] & (1 << i)) == (1 << i)) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            q.push({next_x, next_y});
        }
    }
    
    ans2 = max(ans2, temp);

    for (auto i : tmp) {
        save[i.first][i.second] = {ans1, temp};
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            ans1++;
            solve1(i, j);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];
                if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;
                if (save[i][j].first == save[next_x][next_y].first) continue;
                ans3 = max(ans3, save[i][j].second + save[next_x][next_y].second);
            }
        }
    }

    cout << ans1 << '\n' << ans2 << '\n' << max(ans2, ans3);

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int zero_count;

int board[51][51];
bool visited[51][51];
vector<pair<int, int>> virus;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = INT_MAX;

bool chk_virus() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void solve() {
    memset(visited, false, sizeof(visited));

    queue<pair<pair<int, int>, int>> q;

    int temp = 0;

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 3) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        auto now = q.front();
        q.pop();


        if (count == zero_count) {
            temp = max(temp, now.second);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.first.first + dx[i];
            int next_y = now.first.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (board[next_x][next_y] == 1) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (board[next_x][next_y] == 0) count++;

            q.push({{next_x, next_y}, now.second + 1});
        }
    }

    if (count != zero_count) return;

    ans = min(ans, temp);
}

void select_virus(int before, int counter) {
    if (counter == M) {
        solve();
        return;
    }

    for (int i = before + 1; i < virus.size(); i++) {
        int now_x = virus[i].first;
        int now_y = virus[i].second;
        board[now_x][now_y] = 3;
        select_virus(i, counter + 1);
        board[now_x][now_y] = 2;
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) zero_count++;
            if (board[i][j] == 2) virus.push_back({i, j});
        }
    }

    if (chk_virus()) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < virus.size(); i++) {
        int now_x = virus[i].first;
        int now_y = virus[i].second;
        board[now_x][now_y] = 3;
        select_virus(i, 1);
        board[now_x][now_y] = 2;
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
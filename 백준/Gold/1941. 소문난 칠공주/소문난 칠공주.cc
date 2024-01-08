#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool board[5][5];
bool visited[5][5];
bool visited2[5][5];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

int start_x, start_y;

int maxi;

void chk() {
    maxi = 1;

    queue<pair<int, int>> q;

    q.push({start_x, start_y});

    visited2[start_x][start_y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5) continue;
            if (!visited[next_x][next_y]) continue;
            if (visited2[next_x][next_y]) continue;
            visited2[next_x][next_y] = true;
            maxi++;
            q.push({next_x, next_y});
        }
    }
}

bool connected() {
    chk();
    if (maxi == 7) {
        return true;
    }
    else return false;
}

void solve(int counter, int dasom, int x) {

    if (counter - dasom >= 4) return;
    if (counter == 6) {

    }
    if (counter == 7) {
        memset(visited2, false, sizeof(visited2));
        if (connected()) ans++;
        return;
    }

    for (int i = x; i < 25; i++) {
        int next_x = i / 5;
        int next_y = i % 5;
        if (visited[next_x][next_y]) continue;
        visited[next_x][next_y] = true;
        solve(counter + 1, dasom + board[next_x][next_y], i);
        visited[next_x][next_y] = false;
    }
}

int main() {
    FastIO

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 5; j++) {
            if (s[j] == 'S') board[i][j] = true;
        }
    }

    for (int i = 0; i < 25; i++) {
        start_x = i / 5;
        start_y = i % 5;
        if (visited[start_x][start_y]) continue;
        visited[start_x][start_y] = true;
        solve(1, board[start_x][start_y], i);
        visited[start_x][start_y] = false;
    }

    cout << ans;

    return 0;
}
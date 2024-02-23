#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int w, h;
int board[21][21];
bool visited[21][21][(1 << 11)];

pair<int, int> init;

int dirty_counter;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = -1;

void solve() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, init});
    visited[init.first][init.second][0] = true;

    while(!q.empty()) {
        int now_counter = q.front().first.first;
        int now_cache = q.front().first.second;
        int now_x = q.front().second.first;
        int now_y = q.front().second.second;
        q.pop();

        //cout << now_cache << '\n';

        if (now_cache == (1 << dirty_counter) - 1) {
            ans = now_counter;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
            if (board[next_x][next_y] == -1) continue;
            else if (board[next_x][next_y]) {
                int next_cache = now_cache | board[next_x][next_y];
                if (visited[next_x][next_y][next_cache]) continue;
                visited[next_x][next_y][next_cache] = true;
                q.push({{now_counter + 1, next_cache}, {next_x, next_y}});
            }
            else {
                if (visited[next_x][next_y][now_cache]) continue;
                visited[next_x][next_y][now_cache] = true;
                q.push({{now_counter + 1, now_cache}, {next_x, next_y}});
            }
        }
    }
}

int main() {
    FastIO

    while(true) {
        memset(visited, false, sizeof(visited));
        memset(board, 0, sizeof(board));
        dirty_counter = 0;
        ans = -1;

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                if (s[j] == 'x') board[i][j] = -1;
                else if (s[j] == 'o') init = {i, j};
                else if (s[j] == '*') {
                    board[i][j] = (1 << dirty_counter);
                    dirty_counter++;
                }
            }
        }

        solve();

        cout << ans << '\n';
    }

    return 0;
}
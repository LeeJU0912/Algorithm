#include <bits/stdc++.h>
using namespace std;

int T;
int w, h;
char board[1001][1001];
int start_x;
int start_y;
bool visited[1001][1001];
int ans;

queue<pair<int, int>> fire;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<pair<int, int>, int>> q;

    q.push({{start_x, start_y}, 0});
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        int q_counter = q.size();
        int fire_counter = fire.size();

        for (int j = 0; j < fire_counter; j++) {
            int now_fire_x = fire.front().first;
            int now_fire_y = fire.front().second;
            fire.pop();


            for (int i = 0; i < 4; i++) {
                int fire_x = now_fire_x + dx[i];
                int fire_y = now_fire_y + dy[i];

                if (board[fire_x][fire_y] != '.') continue;
                board[fire_x][fire_y] = '*';

                fire.push({fire_x, fire_y});
            }
        }

        for (int j = 0; j < q_counter; j++) {
            int now_x = q.front().first.first;
            int now_y = q.front().first.second;
            int counter = q.front().second;
            q.pop();

            if (now_x == 0 || now_x == h - 1 || now_y == 0 || now_y == w - 1) {
                ans = counter + 1;
                return;
            }

            for (int i = 0; i < 4; i++) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];

                if (board[next_x][next_y] == '*' || board[next_x][next_y] == '#') continue;
                if (visited[next_x][next_y]) continue;
                if (next_x < 0 || next_x > h - 1 || next_y < 0 || next_y > w - 1) continue;

                visited[next_x][next_y] = true;
                q.push({{next_x, next_y}, counter + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        while(!fire.empty()) fire.pop();
        ans = 0;

        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '@') {
                    board[i][j] = '.';
                    start_x = i;
                    start_y = j;
                }
                if (board[i][j] == '*') {
                    fire.push({i, j});
                }
            }
        }

        bfs();

        if (!ans) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>

using namespace std;

struct INFO {
    int rx, ry, bx, by, count;
};

INFO start;

int N, M;
char board[11][11];
int visited[11][11][11][11];
int ans = -1;

int dx[4] = {1, 0, 0 , -1};
int dy[4] = {0, 1, -1, 0};

void solve() {
    queue<INFO> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = 1;

    while(!q.empty()) {
        INFO now = q.front();
        q.pop();

        if (now.count > 10) break;
        if (board[now.rx][now.ry] == 'O' && board[now.bx][now.by] != 'O') {
            ans = now.count;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_red_x = now.rx;
            int next_red_y = now.ry;
            int next_blue_x = now.bx;
            int next_blue_y = now.by;

            while(1) {
                if (board[next_red_x][next_red_y] != '#' && board[next_red_x][next_red_y] != 'O') {
                    next_red_x += dx[i];
                    next_red_y += dy[i];
                }
                else {
                    if (board[next_red_x][next_red_y] == '#') {
                        next_red_x -= dx[i];
                        next_red_y -= dy[i];
                    }
                    break;
                }
            }

            while(1) {
                if (board[next_blue_x][next_blue_y] != '#' && board[next_blue_x][next_blue_y] != 'O') {
                    next_blue_x += dx[i];
                    next_blue_y += dy[i];
                }
                else {
                    if (board[next_blue_x][next_blue_y] == '#') {
                        next_blue_x -= dx[i];
                        next_blue_y -= dy[i];
                    }
                    break;
                }
            }

            if (next_red_x == next_blue_x && next_red_y == next_blue_y) {
                if (board[next_red_x][next_red_y] != 'O') {
                    int red_moving = abs(next_red_x - now.rx) + abs(next_red_y - now.ry);
                    int blue_moving = abs(next_blue_x - now.bx) + abs(next_blue_y - now.by);

                    if (red_moving > blue_moving) {
                        next_red_x -= dx[i];
                        next_red_y -= dy[i];
                    }
                    else {
                        next_blue_x -= dx[i];
                        next_blue_y -= dy[i];
                    }
                }
            }
            if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y] == 0) {
                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = 1;
                INFO next;
                next.rx = next_red_x;
                next.ry = next_red_y;
                next.bx = next_blue_x;
                next.by = next_blue_y;
                next.count = now.count + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R'){
                start.rx = i;
                start.ry = j;
            }
            else if (board[i][j] == 'B'){
                start.bx = i;
                start.by = j;
            }
        }
    }

    start.count = 0;

    solve();

    cout << ans;

    return 0;
}
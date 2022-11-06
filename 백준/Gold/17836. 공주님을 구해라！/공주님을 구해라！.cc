#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int board[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solve1() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0] = true;

    int temp = -1;

    while (!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int counter = q.front().second;
        q.pop();


        if (counter > t) {
            if (temp != -1 && temp <= t) {
                return temp;
            }
            else {
                return -1;
            }
        }

        if (now_x == n - 1 && now_y == m - 1) {
            if (temp != -1 && temp <= t) {
                return min(temp, counter);
            }
            else {
                return counter;
            }
        }

        if (board[now_x][now_y] == 2) {
            temp = counter + ((n - 1) - now_x) + ((m - 1) - now_y);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] == 1) continue;

            visited[next_x][next_y] = true;

            q.push({{next_x, next_y}, counter + 1});
        }
    }
    if (temp != -1 && temp <= t) {
        return temp;
    }
    else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = solve1();

    if (ans == -1) {
        cout << "Fail";
    }
    else {
        cout << ans;
    }

    return 0;
}
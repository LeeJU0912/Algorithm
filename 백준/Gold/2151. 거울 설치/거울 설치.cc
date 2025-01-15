#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[50][50];
int DP[50][50][4];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> door;

void solve() {
    queue<pair<pair<int, int>, pair<int, int>>> q;

    for (int i = 0; i < 4; i++) {
        q.push({{0, i}, door[0]});
        DP[door[0].first][door[0].second][i] = 0;
    }

    while(!q.empty()) {
        int mirrorCnt = q.front().first.first;
        int nowDist = q.front().first.second;

        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        // 그대로 직진
        int nextX = nowX + dx[nowDist];
        int nextY = nowY + dy[nowDist];

        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
            // 문 도달
            if (nextX == door[1].first && nextY == door[2].second) {
                if (DP[nextX][nextY][nowDist] > mirrorCnt) {
                    DP[nextX][nextY][nowDist] = mirrorCnt;
                    continue;
                }
            }

            if (board[nextX][nextY] != 1) {
                if (DP[nextX][nextY][nowDist] > mirrorCnt) {
                    DP[nextX][nextY][nowDist] = mirrorCnt;
                    q.push({{mirrorCnt, nowDist}, {nextX, nextY}});
                }
            }
        }

        // 거울 설치
        if (board[nowX][nowY] == 3) {
            // 왼쪽 반사
            int nextDist = ((nowDist - 1) + 4) % 4;
            nextX = nowX + dx[nextDist];
            nextY = nowY + dy[nextDist];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                if (board[nextX][nextY] != 1) {
                    if (DP[nextX][nextY][nextDist] > mirrorCnt + 1) {
                        DP[nextX][nextY][nextDist] = mirrorCnt + 1;
                        q.push({{mirrorCnt + 1, nextDist}, {nextX, nextY}});
                    }
                }
            }

            // 오른쪽 반사
            nextDist = ((nowDist + 1) + 4) % 4;
            nextX = nowX + dx[nextDist];
            nextY = nowY + dy[nextDist];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                if (board[nextX][nextY] != 1) {
                    if (DP[nextX][nextY][nextDist] > mirrorCnt + 1) {
                        DP[nextX][nextY][nextDist] = mirrorCnt + 1;
                        q.push({{mirrorCnt + 1, nextDist}, {nextX, nextY}});
                    }
                }
            }
        }
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            if (s[j] == '*') {
                board[i][j] = 1;
            }
            else if (s[j] == '#') {
                board[i][j] = 2;
                door.push_back({i, j});
            }
            else if (s[j] == '!') {
                board[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                DP[i][j][k] = INT_MAX;
            }
        }
    }

    solve();

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, DP[door[1].first][door[1].second][i]);
    }

    cout << ans;

    return 0;
}
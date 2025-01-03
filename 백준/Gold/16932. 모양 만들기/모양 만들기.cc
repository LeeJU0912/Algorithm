#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
bool board[1001][1001];
bool visited[1001][1001];
pair<int, int> island[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

int islandId = 1;
void makeIsland(int x, int y) {
    int cnt = 0;

    stack<pair<int, int>> stk;
    queue<pair<int, int>> q;
    q.push({x, y});
    stk.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (board[nextX][nextY] == 0) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;
            q.push({nextX, nextY});
            stk.push({nextX, nextY});
        }
    }

    while(!stk.empty()) {
        int X = stk.top().first;
        int Y = stk.top().second;
        stk.pop();

        island[X][Y] = {islandId, cnt};
    }

    ans = max(ans, cnt);
    islandId++;
}

void solve(int x, int y) {
    int cnt = 0;
    set<int> visitedIsland;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
        if (visitedIsland.find(island[nextX][nextY].first) != visitedIsland.end()) continue;
        cnt += island[nextX][nextY].second;
        visitedIsland.insert(island[nextX][nextY].first);
    }

    ans = max(ans, cnt + 1);
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            if (board[i][j] == 0) continue;
            makeIsland(i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                solve(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}
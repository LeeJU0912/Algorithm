#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[50][50];
bool visited[50][50];
int dist[7][7];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> S, E;
vector<pair<int, int>> X;
map<pair<int, int>, int> boardToIdx;
int boardIdx;

int ans = INT_MAX;

void makeStoX() {
    int SNode = boardToIdx[S];
    queue<pair<int, pair<int, int>>> q;
    q.push({0, S});
    visited[S.first][S.second] = true;

    while(!q.empty()) {
        int nowDist = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        if (board[nowX][nowY] == 3) {
            dist[SNode][boardToIdx[{nowX, nowY}]] = nowDist;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowDist + 1, {nextX, nextY}});
        }
    }
}

void makeXtoX(int idx) {
    memset(visited, false, sizeof(visited));
    int SNode = boardToIdx[X[idx]];
    queue<pair<int, pair<int, int>>> q;
    q.push({0, X[idx]});
    visited[X[idx].first][X[idx].second] = true;

    while(!q.empty()) {
        int nowDist = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        if (board[nowX][nowY] == 3) {
            if (nowX != X[idx].first || nowY != X[idx].second) {
                dist[SNode][boardToIdx[{nowX, nowY}]] = nowDist;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowDist + 1, {nextX, nextY}});
        }
    }
}

void makeXtoE(int idx) {
    memset(visited, false, sizeof(visited));
    int SNode = boardToIdx[X[idx]];
    queue<pair<int, pair<int, int>>> q;
    q.push({0, X[idx]});
    visited[X[idx].first][X[idx].second] = true;

    while(!q.empty()) {
        int nowDist = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        if (board[nowX][nowY] == 4) {
            dist[SNode][boardToIdx[{nowX, nowY}]] = nowDist;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowDist + 1, {nextX, nextY}});
        }
    }
}

void makeStoE() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, S});
    visited[S.first][S.second] = true;

    while(!q.empty()) {
        int nowDist = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        if (board[nowX][nowY] == 4) {
            ans = nowDist;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowDist + 1, {nextX, nextY}});
        }
    }
}

bool visitedIdx[7];
void visiting(int hap, int cnt, int idx) {
    if (cnt == X.size()) {
        ans = min(ans, hap + dist[boardToIdx[X[idx]]][boardToIdx[E]]);
        return;
    }

    for (int i = 0; i < X.size(); i++) {
        if (visitedIdx[i]) continue;
        visitedIdx[i] = true;
        visiting(hap + dist[boardToIdx[X[idx]]][boardToIdx[X[i]]], cnt + 1, i);
        visitedIdx[i] = false;
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            if (s[j] == '#') {
                board[i][j] = 1;
            }
            else if (s[j] == 'S') {
                board[i][j] = 2;
                S = {i, j};
                boardToIdx[S] = boardIdx++;
            }
            else if (s[j] == 'X') {
                board[i][j] = 3;
                X.push_back({i, j});
                boardToIdx[{i, j}] = boardIdx++;
            }
            else if (s[j] == 'E') {
                board[i][j] = 4;
                E = {i, j};
                boardToIdx[E] = boardIdx++;
            }
        }
    }

    makeStoX();
    for (int i = 0; i < X.size(); i++) {
        makeXtoX(i);
        makeXtoE(i);
    }

    if (X.empty()) {
        makeStoE();
    }

    for (int i = 0; i < X.size(); i++) {
        visitedIdx[i] = true;
        visiting(dist[boardToIdx[S]][boardToIdx[X[i]]], 1, i);
        visitedIdx[i] = false;
    }

    cout << ans;

    return 0;
}
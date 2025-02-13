#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
bool board[101][101];
bool visited[101][101];
bool candidate[101][101];
vector<pair<int, int>> on[100101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    board[1][1] = true;
    visited[1][1] = true;

    while(true) {
        bool canFind = false;
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
            int nowX = q.front().first;
            int nowY = q.front().second;
            q.pop();

            if (candidate[nowX][nowY]) {
                if (!board[nowX][nowY]) {
                    q.push({nowX, nowY});
                    continue;
                }
            }

            int convert = nowX * 1000 + nowY;
            for (int j = 0; j < on[convert].size(); j++) {
                int onX = on[convert][j].first;
                int onY = on[convert][j].second;
                if (board[onX][onY]) continue;
                board[onX][onY] = true;
                canFind = true;
            }

            for (int j = 0; j < 4; j++) {
                int nextX = nowX + dx[j];
                int nextY = nowY + dy[j];

                if (nextX <= 0 || nextX > N || nextY <= 0 || nextY > N) continue;
                if (!candidate[nextX][nextY]) continue;
                if (visited[nextX][nextY]) continue;
                visited[nextX][nextY] = true;
                canFind = true;
                q.push({nextX, nextY});
            }
        }

        if (!canFind) break;
    }
}

int cntOn() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ret += board[i][j];
        }
    }
    return ret;
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        on[a * 1000 + b].push_back({c, d});
        candidate[c][d] = true;
    }

    solve();
    cout << cntOn();

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, P;
int S[10];
bool cannotExpand[10];
int board[1000][1000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> go[10];

bool allCannotExpand() {
    for (int i = 1; i <= P; i++) {
        if (!cannotExpand[i]) return false;
    }

    return true;
}

bool canExpand(int user) {
    bool expanded = false;

    vector<pair<int, int>> nextGo;

    queue<pair<int, pair<int, int>>> q;
    for (auto x: go[user]) {
        q.push({0, x});
    }

    while(!q.empty()) {
        int cnt = q.front().first;
        int now_x = q.front().second.first;
        int now_y = q.front().second.second;
        q.pop();

        if (cnt == S[user]) {
            nextGo.push_back({now_x, now_y});
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (board[next_x][next_y] != 0) continue;
            board[next_x][next_y] = user;

            q.push({cnt + 1, {next_x, next_y}});
            expanded = true;
        }
    }

    go[user] = nextGo;

    return expanded;
}

int main() {
    FastIO

    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] != '.') {
                if (s[j] == '#') {
                    board[i][j] = -1;
                }
                else {
                    int user = s[j] - '0';
                    board[i][j] = user;
                    go[user].push_back({i, j});
                }
            }
        }
    }

    int nowUser = 0;
    while(true) {
        if (allCannotExpand()) break;
        if (!canExpand(nowUser + 1)) {
            cannotExpand[nowUser + 1] = true;
        }
        nowUser = (nowUser + 1) % P;
    }

    vector<int> ans = vector<int>(P + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                ans[board[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= P; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
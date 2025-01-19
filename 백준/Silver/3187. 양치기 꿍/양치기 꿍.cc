#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;
int board[250][250];
bool visited[250][250];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int sheep, wolf;

void calc(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    int tmpSheep = 0;
    int tmpWolf = 0;
    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        if (board[nowX][nowY] == 1) tmpSheep++;
        else if (board[nowX][nowY] == 2) tmpWolf++;

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
            if (board[nextX][nextY] == 3) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nextX, nextY});
        }
    }

    if (tmpSheep > tmpWolf) sheep += tmpSheep;
    else wolf += tmpWolf;
}

int main() {
    FastIO

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'v') {
                board[i][j] = 2;
            }
            else if (s[j] == 'k') {
                board[i][j] = 1;
            }
            else if (s[j] == '#') {
                board[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] != 3) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                calc(i, j);
            }
        }
    }

    cout << sheep << ' ' << wolf;

    return 0;
}
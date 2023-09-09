#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;
int board[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> sheep;

bool chk_sheep_wolf() {
    bool ans = false;

    for (int i = 0; i < sheep.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int next_x = sheep[i].first + dx[j];
            int next_y = sheep[i].second + dy[j];
            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
            if (board[next_x][next_y] == 2) ans = true;
            else if (board[next_x][next_y] == 0) board[next_x][next_y] = -1;
        }
    }

    return ans;
}

int main() {
    FastIO

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++) {
            if (s[j] == 'S') {
                board[i][j] = 1;
                sheep.push_back({i, j});
            }
            else if (s[j] == 'W') {
                board[i][j] = 2;
            }
        }
    }

    if (chk_sheep_wolf()) {
        cout << 0;
        return 0;
    }
    else {
        cout << 1 << '\n';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == -1) {
                    cout << 'D';
                }
                else if (board[i][j] == 0) {
                    cout << '.';
                }
                else if (board[i][j] == 1) {
                    cout << 'S';
                }
                else if (board[i][j] == 2) {
                    cout << 'W';
                }
            }
            cout << '\n';
        }
    }


    return 0;
}
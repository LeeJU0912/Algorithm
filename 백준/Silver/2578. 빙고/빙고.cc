#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int board[5][5];
bool chk[5][5];

pair<int, int> idx[26];

int bingo_chk() {
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        if (chk[i][0] && chk[i][1] && chk[i][2] && chk[i][3] && chk[i][4]) counter++;
    }

    for (int i = 0; i < 5; i++) {
        if (chk[0][i] && chk[1][i] && chk[2][i] && chk[3][i] && chk[4][i]) counter++;
    }

    if (chk[0][0] && chk[1][1] && chk[2][2] && chk[3][3] && chk[4][4]) counter++;
    if (chk[0][4] && chk[1][3] && chk[2][2] && chk[3][1] && chk[4][0]) counter++;

    return counter;
}

int main() {
    FastIO

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
            idx[board[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int temp;
            cin >> temp;

            chk[idx[temp].first][idx[temp].second] = true;

            if (bingo_chk() >= 3) {
                cout << i * 5 + j;
                return 0;
            }
        }
    }

    return 0;
}
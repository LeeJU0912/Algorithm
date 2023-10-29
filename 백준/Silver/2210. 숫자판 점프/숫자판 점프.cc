#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int board[5][5];

set<int> st;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(int x, int y, int counter, int ans) {
    if (counter == 5) {
        st.insert(ans);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5) continue;
        solve(next_x, next_y, counter + 1, ans * 10 + board[next_x][next_y]);
    }
}

int main() {
    FastIO

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            solve(i, j, 0, board[i][j]);
        }
    }

    cout << st.size();

    return 0;
}
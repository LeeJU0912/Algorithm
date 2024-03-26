#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool board[101][101];

vector<int> save[11];

void save_dragon() {
    save[0].push_back(0);

    for (int i = 1; i <= 10; i++) {
        save[i] = save[i - 1];
        for (int j = save[i - 1].size() - 1; j >= 0; j--) {
            save[i].push_back((save[i - 1][j] + 1) % 4);
        }
    }
}

void drawing(int x, int y, int dist, int gen) {
    board[x][y] = true;

    int now_x = x;
    int now_y = y;
    for (int i = 0; i < save[gen].size(); i++) {
        int go = save[gen][i];
        go += dist;
        go %= 4;

        if (go == 0) {
            now_y++;
        }
        else if (go == 1) {
            now_x--;
        }
        else if (go == 2) {
            now_y--;
        }
        else {
            now_x++;
        }

        board[now_x][now_y] = true;
    }
}

int main() {
    FastIO

    save_dragon();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawing(y, x, d, g);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    }
    
    cout << ans;

    return 0;
}
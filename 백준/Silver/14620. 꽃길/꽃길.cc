#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[10][10];
bool visited[10][10];
int ans = INT_MAX;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool can_flower(int x, int y) {
    if (visited[x][y]) return false;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) return false;
        if (visited[next_x][next_y]) return false;
    }

    return true;
}

int do_flower(int x, int y) {
    int hap = board[x][y];
    visited[x][y] = !visited[x][y];
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        hap += board[next_x][next_y];
        visited[next_x][next_y] = !visited[next_x][next_y];
    }

    return hap;
}

void flower(int counter, int cost) {
    if (counter == 3) {
        ans = min(ans, cost);
        return;
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (can_flower(i, j)) {
                int hap = do_flower(i, j);
                flower(counter + 1, cost + hap);
                do_flower(i, j);
            }
        }
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            int hap = do_flower(i, j);
            flower(1, hap);
            do_flower(i, j);
        }
    }

    cout << ans;

    return 0;
}
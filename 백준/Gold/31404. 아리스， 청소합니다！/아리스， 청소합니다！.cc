#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int H, W;

int A[64][64];
int B[64][64];

int visited[64][64][4];
bool clean[64][64];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C, D;

int ans;

void solve(int x, int y, int dist, int counter) {
    bool is_A;

    if (clean[x][y]) {
        is_A = false;
    }
    else {
        clean[x][y] = true;
        is_A = true;
    }

    int next_x, next_y, next_turn;
    if (is_A) {
        ans = counter;
        next_turn = (dist + A[x][y]) % 4;
    }
    else {
        if (visited[x][y][dist] == H * W) return;
        visited[x][y][dist]++;
        next_turn = (dist + B[x][y]) % 4;
    }

    next_x = x + dx[next_turn];
    next_y = y + dy[next_turn];


    if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) return;
    solve(next_x, next_y, next_turn, counter + 1);
}

int main() {
    FastIO

    cin >> H >> W;
    cin >> R >> C >> D;

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < W; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < W; j++) {
            B[i][j] = s[j] - '0';
        }
    }

    solve(R, C, D, 0);

    cout << ans + 1;

    return 0;
}
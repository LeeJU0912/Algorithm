#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int rate[4];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool visited[30][30];

double ans;

void solve(int x, int y, int counter, double temp) {
    if (counter == N) {
        ans += temp;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (visited[next_x][next_y]) continue;
        visited[next_x][next_y] = true;
        solve(next_x, next_y, counter + 1, temp * ((double )rate[i] / 100));
        visited[next_x][next_y] = false;
    }
}

int main() {
    FastIO

    cin >> N >> rate[0] >> rate[1] >> rate[2] >> rate[3];

    visited[15][15] = true;
    solve(15, 15, 0, 1.0);

    cout << fixed;
    cout.precision(10);
    cout << ans;

    return 0;
}
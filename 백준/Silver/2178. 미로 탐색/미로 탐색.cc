#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>

using namespace std;

int n, m;
int route[101][101];
int visited[101][101];
int dist[101][101];

int dir_x[4] = { 1 , -1, 0, 0};
int dir_y[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

void solve(int a, int b) {
    visited[a][b] = 1;
    q.push({ a, b });
    dist[a][b]++;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dir_x[i];
            int next_y = y + dir_y[i];

            if ((0 <= next_x && next_x < n) && (0 <= next_y && next_y < m) && !visited[next_x][next_y] && route[next_x][next_y] == 1) {

                visited[next_x][next_y] = 1;
                q.push({ next_x, next_y });
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            route[i][j] = s[j] - '0';
        }
    }

    solve(0, 0);

    cout << dist[n - 1][m - 1];

    return 0;
}
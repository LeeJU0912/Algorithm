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
#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

int M, N, H;
int tomato[101][101][101];
int visited[101][101][101];
int ans;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

void bfs() {
    while(!q.empty()) {
        int x = get<2>(q.front());
        int y = get<1>(q.front());
        int z = get<0>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_z = z + dz[i];

            if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N && next_z > 0 && next_z <= H) {
                if (tomato[next_z][next_y][next_x] == 0) {
                    tomato[next_z][next_y][next_x] = tomato[z][y][x] + 1;
                    q.push({ next_z, next_y, next_x });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> H;

    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    q.push(make_tuple(k, i, j));
                }
            }
        }
    }

    bfs();

    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (tomato[k][i][j] == 0) {
                    cout << -1;
                    return 0;
                }
                if (ans < tomato[k][i][j]) {
                    ans = tomato[k][i][j];
                }
            }
        }
    }
    cout << ans - 1;


    return 0;
}
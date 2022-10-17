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
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>
#include <list>

using namespace std;

int N;
int board[101][101];
int visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int maxi;
int ans;

void bfs(int x, int y, int water) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] <= water) continue;
            visited[next_x][next_y] = 1;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            maxi = max(maxi, board[i][j]);
        }
    }

    for (int k = 0; k < maxi; k++) {
        memset(visited, 0, sizeof(visited));

        int temp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] <= k) continue;
                if (visited[i][j]) continue;
                temp++;
                bfs(i, j, k);
            }
        }
        ans = max(ans, temp);
    }

    cout << ans;


    return 0;
}
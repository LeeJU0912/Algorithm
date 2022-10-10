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

using namespace std;

int a, b;
int board[51][51];
int visited[51][51];
int ans;

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1 , 1, 1, -1, -1};

void bfs(int x, int y) {
    visited[x][y] = 1;
    ans++;

    queue<pair<int, int>> q;

    q.push({x, y});

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x <= 0 || next_x > b || next_y <= 0 || next_y > a) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] == 0) continue;

            visited[next_x][next_y] = 1;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b;

    while (a != 0 && b != 0) {
        memset(visited, 0, sizeof(visited));
        ans = 0;


        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= a; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= a; j++) {
                if (visited[i][j]) continue;
                if (board[i][j] == 0) continue;
                bfs(i, j);
            }
        }

        cout << ans << '\n';

        cin >> a >> b;
    }

    return 0;
}
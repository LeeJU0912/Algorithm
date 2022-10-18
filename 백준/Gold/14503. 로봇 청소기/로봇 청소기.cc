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

int N, M;
int x, y, d;
int board[51][51];
int visited[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 1;

void solve() {
    queue<pair<pair<int, int>, int>> q;

    q.push({{x, y}, d});

    visited[x][y] = 1;

    while (!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int go = q.front().second;
        q.pop();

        int temp = 0;
        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (visited[next_x][next_y] || board[next_x][next_y] == 1) temp++;
        }

        if (temp == 4) {
            int next_x = now_x - dx[go];
            int next_y = now_y - dy[go];
            if (board[next_x][next_y] == 1) {
                cout << ans << '\n';
                break;
            }
            else {
                q.push({{next_x, next_y}, go});
            }
        }
        else {
            while (true) {
                go -= 1;
                if (go == -1) {
                    go = 3;
                }
                int next_x = now_x + dx[go];
                int next_y = now_y + dy[go];

                if (board[next_x][next_y] == 1 || visited[next_x][next_y] != 0) {
                    continue;
                }
                visited[next_x][next_y] = 1;
                ans++;
                q.push({{next_x, next_y}, go});
                break;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    cin >> x >> y >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    return 0;
}
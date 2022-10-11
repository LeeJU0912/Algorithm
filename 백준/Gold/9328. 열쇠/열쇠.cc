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

int T;
int a, b;
char board[102][102];
int visited[102][102];
int key[26];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans;

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> door[26];

    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();


        if (board[now_x][now_y] >= 'a' && board[now_x][now_y] <= 'z') {
            key[board[now_x][now_y] - 'a'] = 1;
            for (auto i : door[board[now_x][now_y] - 'a']) {
                q.push({i.first, i.second});
            }
        }

        if (board[now_x][now_y] >= 'A' && board[now_x][now_y] <= 'Z') {
            if (!key[board[now_x][now_y] - 'A']) {
                door[board[now_x][now_y] - 'A'].emplace_back(now_x, now_y);
                continue;
            }
        }

        if (board[now_x][now_y] == '$') ans++;


        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x > a + 1 || next_y < 0 || next_y > b + 1) continue;
            if (board[next_x][next_y] == '*') continue;
            if (visited[next_x][next_y]) continue;

            visited[next_x][next_y] = 1;

            q.push({next_x, next_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
        memset(key, 0, sizeof(key));
        ans = 0;

        cin >> a >> b;

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                cin >> board[i][j];
            }
        }
        string k;
        cin >> k;

        if (k[0] != '0') {
            for (int i = 0; i < k.length(); i++) {
                key[k[i] - 'a'] = 1;
            }
        }


        BFS(0, 0);


        cout << ans <<'\n';

    }

    return 0;
}
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
int board[8][8];
int visited[64];
int temp[8][8];
int ans;

vector<pair<int, int>> start;
vector<pair<int, int>> zero;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < start.size(); i++) {
        q.push({start[i].first, start[i].second});
    }

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;

            if(temp[next_x][next_y] == 0) {
                temp[next_x][next_y] = 2;
                q.push({next_x, next_y});
            }
        }
    }
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) tmp++;
        }
    }
    ans = max(ans, tmp);
}

void copy (int from[8][8], int to[8][8]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void make_wall(int counter, int now) {
    if (counter == 3) {
        copy(board, temp);
        int cnt = 0;
        for (int i = 0; i < zero.size(); i++) {
            if (cnt == 3) break;
            if(visited[i]) {
                int x = zero[i].first;
                int y = zero[i].second;
                temp[x][y] = 1;
                cnt++;
            }
        }
        bfs();
        return;
    }
    for (int i = now; i < zero.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        make_wall(counter + 1, i);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                start.push_back({i, j});
            }
            if (board[i][j] == 0) {
                zero.push_back({i, j});
            }
        }
    }

    make_wall(0, 0);

    cout << ans;

    return 0;
}
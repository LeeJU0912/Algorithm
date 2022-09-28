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
int board[100][100];
int visited[100][100];
int outAir[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void spreadAir() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (visited[next_x][next_y]) continue;

            if (board[next_x][next_y]) {
                outAir[next_x][next_y]++;
            }
            else if (!visited[next_x][next_y]) {
                visited[next_x][next_y] = 1;
                q.push({next_x, next_y});
            }
        }
    }
}

bool melt() {
    bool ismelted = false;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (outAir[i][j] >= 2) {
                board[i][j] = 0;
                ismelted = true;
            }
        }
    }
    return ismelted;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        memset(outAir, 0, sizeof(outAir));

        spreadAir();
        bool isMelted = melt();

        if (isMelted) ans++;
        else break;
    }

    cout << ans;

    return 0;
}
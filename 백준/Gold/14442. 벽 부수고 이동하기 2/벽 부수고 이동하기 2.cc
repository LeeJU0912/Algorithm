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

int N, M, K;
int board[1000][1000];
bool visited[1000][1000][10];

int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 1}, {0, 0}});
    visited[0][0][0] = true;

    while(!q.empty()) {
        int chance = q.front().first.first;
        int go = q.front().first.second;
        int now_x = q.front().second.first;
        int now_y = q.front().second.second;
        q.pop();

        if (now_x == N - 1 && now_y == M - 1) {
            cout << go;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (visited[next_x][next_y][chance]) continue;

            if (board[next_x][next_y] == 0) {
                visited[next_x][next_y][chance] = true;
                q.push({{chance, go + 1}, {next_x, next_y}});
            }
            else {
                if (chance < K) {
                    visited[next_x][next_y][chance + 1] = true;
                    q.push({{chance + 1, go + 1}, {next_x, next_y}});
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j] - '0';
        }
    }

    bfs();

    return 0;
}
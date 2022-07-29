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
int route[1001][1001];
int visited[1001][1001][2];
int dist[1001][1001];

int dir_x[4] = { 1 , -1, 0, 0 };
int dir_y[4] = { 0, 0, 1, -1 };

queue<pair<pair<int, int>, pair<int, int>>> q; // { x, y }, { chance, dist }

int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({{ a, b }, {c, 1}});

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int chance = q.front().second.first;
        int distance = q.front().second.second;
        q.pop();

        if (y == n - 1 && x == m - 1) {
            return distance;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + dir_x[i];
            int next_y = y + dir_y[i];

            if ((0 <= next_x && next_x < m) && (0 <= next_y && next_y < n)) {
                if (route[next_y][next_x] == 1 && chance == 0) {
                    visited[next_y][next_x][1] = 1;
                    q.push({{ next_y, next_x }, { 1, distance + 1 }});
                }
                else if (route[next_y][next_x] == 0 && visited[next_y][next_x][chance] == 0) {
                    visited[next_y][next_x][chance] = 1;
                    q.push({{ next_y, next_x }, { chance, distance + 1}});
                }
            }
        }
    }
    return 0;
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

    int answer = solve(0, 0, 0);

    if (answer == 0) {
        cout << "-1";
    }
    else {
        cout << answer;
    }

    return 0;
}
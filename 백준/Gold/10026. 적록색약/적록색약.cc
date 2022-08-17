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

int N;
string s[101];
int visited[101][101];
int normal;
int abnormal;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
            if (!visited[next_x][next_y] && s[x][y] == s[next_x][next_y]) {
                visited[next_x][next_y] = 1;
                dfs(next_x, next_y);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                normal++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }


    for (int i = 0; i < N; i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == 'R') {
                s[i][j] = 'G';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                abnormal++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }

    cout << normal << ' ' << abnormal;

    return 0;
}
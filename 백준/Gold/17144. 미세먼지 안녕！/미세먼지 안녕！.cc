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

using namespace std;

int R, C, T;
int clean[51][51];
int cleantemp[51][51];
int cleantemp2[51][51];

vector<pair<int, int>> care;
queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[51][51];

int check(int x, int y) {
    if (x > R || y > C || x <= 0 || y <= 0 || clean[x][y] == -1) {
        return 0;
    }
    else return 1;
}

void spread() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y] || clean[x][y] / 5 == 0) continue;
        visited[x][y] = 1;

        int counter = 0;
        for (int k = 0; k < 4; k++) {
            int a = dx[k];
            int b = dy[k];
            if (check(x + a, y + b)) {
                cleantemp[x + a][y + b] += clean[x][y] / 5;
                counter++;
            }
        }
        clean[x][y] -= clean[x][y] / 5 * counter;
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cleantemp[i][j] > 0) {
                clean[i][j] += cleantemp[i][j];
            }
        }
    }
}

void sweep() {
    int x = care[0].first;
    int x2 = care[1].first;

    for (int i = 2; i < C; i++) {
        cleantemp2[x][i + 1] += clean[x][i];
        clean[x][i] = 0;
    }
    for (int i = x; i > 1; i--) {
        cleantemp2[i - 1][C] += clean[i][C];
        clean[i][C] = 0;
    }
    for (int i = C; i > 1; i--) {
        cleantemp2[1][i - 1] += clean[1][i];
        clean[1][i] = 0;
    }
    for (int i = 1; i < x; i++) {
        if (clean[i + 1][1] == -1) {
            clean[i][1] = 0;
        }
        else {
            cleantemp2[i + 1][1] += clean[i][1];
            clean[i][1] = 0;
        }
    }


    for (int i = 2; i < C; i++) {
        cleantemp2[x2][i + 1] += clean[x2][i];
        clean[x2][i] = 0;
    }
    for (int i = x2; i < R; i++) {
        cleantemp2[i + 1][C] += clean[i][C];
        clean[i][C] = 0;
    }
    for (int i = C; i > 1; i--) {
        cleantemp2[R][i - 1] += clean[R][i];
        clean[R][i] = 0;
    }
    for (int i = R; i > x2; i--) {
        if (clean[i - 1][1] == -1) {
            clean[i][1] = 0;
        }
        else {
            cleantemp2[i - 1][1] += clean[i][1];
            clean[i][1] = 0;
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cleantemp2[i][j] > 0) {
                clean[i][j] += cleantemp2[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C >> T;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> clean[i][j];
            if (clean[i][j] > 0) {
                q.push({i, j});
            }
            if (clean[i][j] == -1) {
                care.push_back({i , j});
            }
        }
    }

    while(T--) {
        spread();
        sweep();
        memset(cleantemp, 0 , sizeof(cleantemp));
        memset(cleantemp2, 0, sizeof(cleantemp2));
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (clean[i][j] > 0) {
                    q.push({i, j});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (clean[i][j] > 0) {
                ans += clean[i][j];
            }
        }
    }

    cout << ans;

    return 0;
}
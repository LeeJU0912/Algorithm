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

using namespace std;

int N, M;
string s[1000];
vector<pair<int, int>> parent[1000][1000];
int answer[1000][1000];
int visited[1000][1000];
int ans;

void Find_parent(int x, int y) {


    int dx = parent[x][y][0].first;
    int dy = parent[x][y][0].second;

    if (visited[dx][dy] == 2) return;

    if (visited[dx][dy]) {
        answer[dx][dy] = 1;
        return;
    }
    visited[x][y] = 1;

    Find_parent(dx, dy);
    visited[x][y] = 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == 'U') {
                parent[i][j].emplace_back(i - 1, j);
            }
            else if (s[i][j] == 'D') {
                parent[i][j].emplace_back(i + 1, j);
            }
            else if (s[i][j] == 'L') {
                parent[i][j].emplace_back(i, j - 1);
            }
            else if (s[i][j] == 'R') {
                parent[i][j].emplace_back(i, j + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Find_parent(i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (answer[i][j]) ans++;
        }
    }

    cout << ans;

    return 0;
}
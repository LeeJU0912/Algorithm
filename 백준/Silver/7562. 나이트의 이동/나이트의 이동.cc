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
#include <list>

using namespace std;

int T;
int N;
int start_x;
int start_y;
int end_x;
int end_y;
int ans;

int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, -1, -2, 1, 2};

int visited[301][301];

void solve(int x, int y) {
    queue<pair<pair<int, int>, int>> q;
    visited[x][y] = 1;
    q.push({{x, y}, 0});

    while (!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int counter = q.front().second;
        q.pop();

        if (now_x == end_x && now_y == end_y) {
            cout << counter << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = 1;
            q.push({{next_x, next_y}, counter + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        memset(visited, 0, sizeof(visited));
        //ans = INT_MAX;

        cin >> N;
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        solve(start_x, start_y);
    }


    return 0;
}
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

int n, m, r;
int point[101];
vector<pair<int, int>> route[101];
int d[101];
int ans;

void bfs(int start) {
    int temp = 0;
    queue<int> q;
    q.push(start);
    d[start] = 0;

    while(!q.empty()) {
        int now = q.front();
        int dist = d[now];
        q.pop();


        for (int i = 0; i < route[now].size(); i++) {
            int next = route[now][i].first;
            int length = route[now][i].second;
            if (dist + length < d[next]) {
                d[next] = dist + length;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] <= m) {
            temp += point[i];
        }
    }

    ans = max(ans, temp);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> point[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        route[a].push_back({b, c});
        route[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++) {
        fill(d, d + 101, 1000000);
        bfs(i);
    }

    cout << ans;

    return 0;
}
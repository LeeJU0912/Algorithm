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

int n;
int one;
int two;
int m;
vector<int> graph[101];
int visited[101];
int ans = -1;

void bfs() {
    queue<pair<int, int>> q;
    q.push({one, 0});
    visited[one] = 1;

    while(!q.empty()) {
        int now = q.front().first;
        int counter = q.front().second;
        q.pop();

        if (now == two) {
            ans = counter;
            return;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next]) continue;
            visited[next] = 1;
            q.push({next, counter + 1});

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    cin >> one >> two;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    cout << ans;

    return 0;
}
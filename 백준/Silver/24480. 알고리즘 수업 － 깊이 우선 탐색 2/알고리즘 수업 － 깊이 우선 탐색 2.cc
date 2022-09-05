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

int N, M, R;
vector<pair<int, int>> v[100001];
int visited[100001];
int ans[100001];
int counter;

void dfs(int start) {
    if (visited[start]) return;
    counter++;
    ans[start] = counter;
    visited[start] = 1;
    sort(v[start].rbegin(), v[start].rend());

    for (int i = 0; i < v[start].size(); i++) {
        int next = v[start][i].first;
        dfs(next);
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, 1});
        v[b].push_back({a, 1});
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
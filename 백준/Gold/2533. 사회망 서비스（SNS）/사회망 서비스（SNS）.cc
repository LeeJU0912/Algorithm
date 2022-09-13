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

using namespace std;

int N;

int dp[1000001][2];
vector<int> connect[1000001];
int visited[1000001];

void dfs(int start) {
    visited[start] = 1;
    dp[start][0] = 0;
    dp[start][1] = 1;

    for (int i = 0; i < connect[start].size(); i++) {
        int next = connect[start][i];
        if (!visited[next]) {
            dfs(next);
            dp[start][0] += dp[next][1];
            dp[start][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}
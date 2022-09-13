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
int dp[10001][2];
int visited[10001];
int point[10001];
vector<int> connect[10001];

void dfs(int start) {
    visited[start] = 1;

    dp[start][0] = 0;
    dp[start][1] = point[start];

    for (int i = 0; i < connect[start].size(); i++) {
        int next = connect[start][i];
        if (!visited[next]) {
            dfs(next);
            dp[start][0] += max(dp[next][0], dp[next][1]);
            dp[start][1] += dp[next][0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> point[i];
    }
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (connect[i].size() == 1) {
            dfs(i);
            cout << max(dp[i][0], dp[i][1]);
            break;
        }
    }
    
    return 0;
}
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

int Test;
int Building, Road;
int Time[1001];
int X, Y;
int dp[1001];

int Win;
vector<int> go[1001];
int indegree[1001];

void solve() {
    queue<int> q;
    for (int i = 1; i <= Building; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = Time[i];
        }
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < go[now].size(); i++) {
            int next = go[now][i];
            dp[next] = max(dp[next], dp[now] + Time[next]);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << dp[Win] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> Test;

    while(Test--) {
        cin >> Building >> Road;
        for (int i = 1; i <= Building; i++) {
            cin >> Time[i];
        }
        for (int i = 1; i <= Road; i++) {
            cin >> X >> Y;
            go[X].push_back(Y);
            indegree[Y]++;
        }
        cin >> Win;
        solve();

        memset(indegree, 0, sizeof(indegree));
        memset(go, 0, sizeof(go));
        memset(Time, 0, sizeof(Time));
        memset(dp, 0, sizeof(dp));
    }

    return 0;
}
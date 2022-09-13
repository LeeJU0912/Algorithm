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
int point[10001];
vector<int> connect[10001];
int visited[10001];
priority_queue<int, vector<int>, greater<>> ans;

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

void road(int start, int chk) {
    visited[start] = 1;

    if(chk) {
        ans.push(start);
        for (int i = 0; i < connect[start].size(); i++) {
            int next = connect[start][i];
            if (!visited[next]) {
                road(next, 0);
            }
        }
    }
    else {
        for (int i = 0; i < connect[start].size(); i++) {
            int next = connect[start][i];
            if (!visited[next]) {
                if (dp[next][0] > dp[next][1]) {
                    road(next, 0);
                }
                else {
                    road(next, 1);
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> point[i];
    }

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    int root;
    for (int i = 1; i <= N; i++) {
        if (connect[i].size() == 1) {
            root = i;
            break;
        }
    }
    
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << '\n';

    memset(visited, 0, sizeof(visited));
    if (dp[root][0] < dp[root][1]) road(root, 1);
    else {
        road(root, 0);
    }


    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
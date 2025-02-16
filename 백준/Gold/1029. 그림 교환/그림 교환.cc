#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> graph[16];
bool visited[16];
int DP[(1 << 15) + 1][16];

int ans;

void solve(int visit, int idx, int price, int cnt) {
    if (DP[visit][idx] <= price) return;
    DP[visit][idx] = price;

    ans = max(ans, cnt);

    for (int i = 0; i < graph[idx].size(); i++) {
        int nextPrice = graph[idx][i].first;
        int nextNode = graph[idx][i].second;

        if (nextPrice < price) continue;
        if (visited[nextNode]) continue;

        visited[nextNode] = true;
        solve(visit | (1 << (nextNode - 1)), nextNode, nextPrice, cnt + 1);
        visited[nextNode] = false;
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            graph[i].push_back({s[j] - '0', j + 1});
        }
    }

    for (int i = 1; i <= (1 << N); i++) {
        for (int j = 1; j <= 15; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    visited[1] = true;
    solve(1, 1, 0, 1);

    cout << ans;

    return 0;
}
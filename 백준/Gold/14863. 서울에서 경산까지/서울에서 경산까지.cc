#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;

vector<pair<int, int>> graph[101];
int DP[100001];

int ans;

void solve(int idx, int nowTime, int nowMoney) {
    if (nowTime > K) return;
    if (nowTime + DP[idx] > K) return;
    if (idx == N) {
        ans = max(ans, nowMoney);
        return;
    }

    solve(idx + 1, nowTime + graph[idx][0].first, nowMoney + graph[idx][0].second);
    solve(idx + 1, nowTime + graph[idx][1].first, nowMoney + graph[idx][1].second);
}

int main() {
    FastIO

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int walk, walkMoney, bicycle, bicycleMoney;
        cin >> walk >> walkMoney >> bicycle >> bicycleMoney;

        graph[i].emplace_back(walk, walkMoney);
        graph[i].emplace_back(bicycle, bicycleMoney);
    }

    for (int i = N - 1; i >= 0; i--) {
        DP[i] = DP[i + 1] + min(graph[i][0].first, graph[i][1].first);
    }

    solve(0, 0, 0);

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;

pair<int, int> graph[101][2];
int DP[100][100001];

int solve(int idx, int nowTime, int nowMoney) {
    if (nowTime > K) return -1e7;
    if (idx == N) {
        return 0;
    }
    if (DP[idx][nowTime]) return DP[idx][nowTime];

    int first = solve(idx + 1, nowTime + graph[idx][0].first, nowMoney + graph[idx][0].second);
    int second = solve(idx + 1, nowTime + graph[idx][1].first, nowMoney + graph[idx][1].second);

    return DP[idx][nowTime] = max(first + graph[idx][0].second, second + graph[idx][1].second);
}

int main() {
    FastIO

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int walk, walkMoney, bicycle, bicycleMoney;
        cin >> walk >> walkMoney >> bicycle >> bicycleMoney;

        graph[i][0] = {walk, walkMoney};
        graph[i][1] = {bicycle, bicycleMoney};
    }

    solve(0, 0, 0);

    cout << DP[0][0];

    return 0;
}
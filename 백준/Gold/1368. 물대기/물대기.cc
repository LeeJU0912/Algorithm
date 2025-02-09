#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int W[300];
int cost[300][300];
bool visited[300];

int ans;

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        pq.push({W[i], i});
    }

    while(!pq.empty()) {
        int nowCost = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (visited[nowNode]) continue;
        visited[nowNode] = true;
        ans += nowCost;

        for (int i = 0; i < N; i++) {
            if (W[i] <= cost[nowNode][i]) continue;
            pq.push({cost[nowNode][i], i});
        }
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}
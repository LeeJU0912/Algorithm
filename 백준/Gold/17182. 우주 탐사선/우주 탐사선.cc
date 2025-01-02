#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<pair<int, int>> graph[10];
int dist[10][(1 << 10)];

int solve() {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
    pq.push({{0, K}, (1 << K)});

    dist[K][(1 << K)] = 0;

    while(!pq.empty()) {
        int nowDist = pq.top().first.first;
        int nowNode = pq.top().first.second;
        int chkList = pq.top().second;
        pq.pop();

        if (chkList == (1 << N) - 1) {
            return nowDist;
        }

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = graph[nowNode][i].first;
            int nextNode = graph[nowNode][i].second;

            if (dist[nextNode][chkList] <= nowDist + nextDist) continue;
            dist[nextNode][chkList] = nowDist + nextDist;

            pq.push({{nowDist + nextDist, nextNode}, chkList | (1 << nextNode)});
        }
    }

    return 0;
}

int main() {
    FastIO

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 0) continue;
            graph[i].push_back({x, j});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dist[i][j] = INT_MAX;
        }
    }

    cout << solve();

    return 0;
}
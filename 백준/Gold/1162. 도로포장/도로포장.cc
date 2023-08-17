#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
vector<pair<int, int>> graph[10001];

long long dist[10001][21];

void dijkstra() {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 1}});
    dist[1][0] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.first > dist[now.second.second][now.second.first]) continue;

        for (int i = 0; i < graph[now.second.second].size(); i++) {
            auto next = graph[now.second.second][i];
            long long next_dist = next.first + now.first;

            if (next_dist < dist[next.second][now.second.first]) {
                dist[next.second][now.second.first] = next_dist;
                pq.push({next_dist, {now.second.first, next.second}});
            }

            if (now.second.first < K) {
                if (dist[next.second][now.second.first + 1] > now.first) {
                    dist[next.second][now.second.first + 1] = now.first;
                    pq.push({now.first, {now.second.first + 1, next.second}});
                }
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 20; j++) {
            dist[i][j] = LLONG_MAX / 2;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra();

    long long ans = LLONG_MAX;

    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[N][i]);
    }

    cout << ans;

    return 0;
}
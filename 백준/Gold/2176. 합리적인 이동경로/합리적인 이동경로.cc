#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];

int dist[1001];
int DP[1001];

int ans;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 2});
    dist[2] = 0;
    DP[2] = 1;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (dist[now.second] < now.first) continue;

        for (int i = 0; i < graph[now.second].size(); i++) {
            auto next = graph[now.second][i];

            if (now.first + next.first < dist[next.second]) {
                dist[next.second] = now.first + next.first;
                pq.push({now.first + next.first, next.second});
            }

            if (now.first > dist[next.second]) {
                DP[now.second] += DP[next.second];
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra();

    cout << DP[1];

    return 0;
}
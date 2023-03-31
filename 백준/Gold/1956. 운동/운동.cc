#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int V, E;

vector<pair<int, int>> graph[401];

int dist[401][401];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    dist[start][start] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        for (int i = 0; i < graph[now.second].size(); i++) {
            auto next = graph[now.second][i];

            if (dist[start][next.second] > now.first + next.first) {
                dist[start][next.second] = now.first + next.first;
                pq.emplace(dist[start][next.second], next.second);
            }
        }
    }
}

int main() {
    FastIO

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INT_MAX;
        }
        dijkstra(i);
    }

    int ans = INT_MAX;

    for (int i = 1; i < V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (dist[i][j] == INT_MAX || dist[j][i] == INT_MAX) continue;
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
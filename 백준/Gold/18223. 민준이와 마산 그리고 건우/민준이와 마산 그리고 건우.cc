#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int V, E, P;
vector<pair<int, int>> graph[5001];

int dist[5001];

int min_dist;

void dijkstra(int start, int end) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int now_node = pq.top().second;
        pq.pop();

        if (now_node == end) return;

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_node = graph[now_node][i].second;
            int next_dist = graph[now_node][i].first;

            if (dist[now_node] + next_dist > dist[next_node]) continue;
            dist[next_node] = dist[now_node] + next_dist;

            pq.push({dist[next_node], next_node});
        }
    }
}

int main() {
    FastIO

    cin >> V >> E >> P;
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra(1, V);

    min_dist = dist[V];

    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }

    dijkstra(1, P);

    int temp = dist[P];
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }

    dijkstra(P, V);
    
    if (dist[V] + temp > min_dist) {
        cout << "GOOD BYE";
    }
    else {
        cout << "SAVE HIM";
    }

    return 0;
}
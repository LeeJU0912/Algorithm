#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<pair<int, int>> graph[5001];
int s, t;

int dist[5001];

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, s}});

    dist[s] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        int now_cost = now.first;
        int now_max = now.second.first;
        int now_node = now.second.second;
        pq.pop();

        if (dist[now_node] < now_cost) continue;

        for (int i = 0; i < graph[now_node].size(); i++) {
            auto next = graph[now_node][i];
            int next_cost = now_cost + next.first + now_max - max(now_max, next.first);
            if (dist[next.second] <= next_cost) continue;

            dist[next.second] = next_cost;
            pq.push({next_cost, {max(now_max, next.first), next.second}});
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    int hap = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        hap += c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cin >> s >> t;

    dijkstra();

    cout << hap - dist[t];

    return 0;
}
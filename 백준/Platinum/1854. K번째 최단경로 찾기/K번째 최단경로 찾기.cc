#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m, k;
vector<pair<int, int>> graph[1001];
priority_queue<int> dist[1001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1].push(0);

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();


        for (int i = 0; i < graph[now.second].size(); i++) {
            auto next = graph[now.second][i];

            if (dist[next.second].size() == k) {
                if (dist[next.second].top() > now.first + next.first) {
                    dist[next.second].pop();
                    dist[next.second].push(now.first + next.first);
                    pq.push({now.first + next.first, next.second});
                }
            }
            else {
                dist[next.second].push(now.first + next.first);
                pq.push({now.first + next.first, next.second});
            }
        }
    }
}

int main() {
    FastIO

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) {
            cout << -1 << '\n';
            continue;
        }
        cout << dist[i].top() << '\n';
    }

    return 0;
}
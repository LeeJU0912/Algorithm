#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> graph[5001];
int dist[5001];

int main() {
    FastIO

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int s, t;
    cin >> s >> t;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second == t) {
            cout << now.first;
            return 0;
        }

        for (auto next : graph[now.second]) {
            if (dist[next.second] <= dist[now.second] + next.first) continue;
            dist[next.second] = dist[now.second] + next.first;

            pq.push({now.first + next.first, next.second});
        }
    }

    return 0;
}
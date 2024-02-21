#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m, t, s, g, h;

vector<pair<int, int>> graph[2001];
int dist[2001];

set<int> ans;

void dijkstra(int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int now_dist = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (now_node == end) {
            if (now_dist % 2) ans.insert(now_node);
            return;
        }

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_dist = graph[now_node][i].first;
            int next_node = graph[now_node][i].second;

            if (dist[next_node] <= dist[now_node] + next_dist) continue;
            dist[next_node] = dist[now_node] + next_dist;

            pq.push({now_dist + next_dist, next_node});
        }
    }
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        ans.clear();
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;

            if ((a == g && b == h) || (a == h && b == g)) {
                graph[a].push_back({d * 2 - 1, b});
                graph[b].push_back({d * 2 - 1, a});
            }
            else {
                graph[a].push_back({d * 2, b});
                graph[b].push_back({d * 2, a});
            }
        }

        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;

            for (int j = 1; j <= n; j++) {
                dist[j] = 1e9;
            }
            dijkstra(x);
        }

        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
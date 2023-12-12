#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> graph[10001];
int dist[10001];

int ans1, ans2;

void solve(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, start});

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (dist[now.second] <= now.first) continue;
        dist[now.second] = now.first;

        ans1++;
        ans2 = max(ans2, now.first);

        for (int i = 0; i < graph[now.second].size(); i++) {
            int next_dist = graph[now.second][i].first + now.first;
            int next_node = graph[now.second][i].second;

            pq.push({next_dist, next_node});
        }
    }
}

int main() {
    FastIO

    int t;
    cin >> t;

    while(t--) {
        ans1 = 0;
        ans2 = 0;

        for (int i = 1; i <= 10000; i++) {
            graph[i].clear();
            dist[i] = INT_MAX;
        }

        int n, d, c;
        cin >> n >> d >> c;

        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;

            graph[b].push_back({s, a});
        }

        solve(c);

        cout << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;

vector<pair<int, int>> graph[201];

int length[201];
int road[201];
int ans[201][201];

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second == end) break;

        for (int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            int next_length = graph[now.second][i].first;

            if (now.first + next_length >= length[next]) continue;
            road[next] = now.second;
            length[next] = now.first + next_length;
            pq.push({now.first + next_length, next});
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 1; k <= n; k++) {
                length[k] = INT_MAX;
            }

            dijkstra(i, j);

            int trace = j;

            while(length[j] != INT_MAX && road[trace] != i) {
                trace = road[trace];
            }

            ans[i][j] = trace;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << '-' << ' ';
            }
            else {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
bool visited[100000];
long long dist[100000];

vector<pair<long long, int>> graph[100000];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

void solve() {
    dist[0] = 0;

    for (int i = 0; i < graph[0].size(); i++) {
        int& next_node = graph[0][i].second;
        long long& next_length = graph[0][i].first;

        if (visited[next_node]) continue;
        if (dist[next_node] <= next_length) continue;
        dist[next_node] = next_length;
        pq.push(graph[0][i]);
    }

    while(!pq.empty()) {
        long long now_length = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (dist[now_node] < now_length) continue;
        if (now_node == N - 1) return;

        for (int i = 0; i < graph[now_node].size(); i++) {
            int& next_node = graph[now_node][i].second;
            long long& next_length = graph[now_node][i].first;

            if (visited[next_node]) continue;
            if (dist[next_node] <= now_length + next_length) continue;
            dist[next_node] = now_length + next_length;

            pq.push({now_length + next_length, next_node});
        }

    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> visited[i];
        dist[i] = LLONG_MAX;
    }
    visited[N - 1] = false;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    solve();

    cout << (dist[N - 1] == LLONG_MAX ? -1 : dist[N - 1]);

    return 0;
}
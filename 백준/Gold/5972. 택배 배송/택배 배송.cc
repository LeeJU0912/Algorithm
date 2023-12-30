#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<pair<int, int>> graph[50001];
int dist[50001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second == N) {
            cout << now.first;
            return;
        }

        for (int i = 0; i < graph[now.second].size(); i++) {
            auto next = graph[now.second][i];

            if (dist[next.second] <= now.first + next.first) continue;
            dist[next.second] = now.first + next.first;

            pq.push({now.first + next.first, next.second});
        }
    }

}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra();

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
int S, D;
vector<pair<int, int>> graph[1001];
int dist[1001][1001];

int ans;

void dijkstra(int start) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, start}});

    dist[start][0] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second.first >= N) continue;
        if (dist[now.second.second][now.second.first] < now.first) continue;

        for (int i = 0; i < graph[now.second.second].size(); i++) {
            auto& next = graph[now.second.second][i];

            if (now.first + next.first >= dist[next.second][now.second.first + 1]) continue;
            dist[next.second][now.second.first + 1] = now.first + next.first;

            pq.push({now.first + next.first, {now.second.first + 1, next.second}});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;
    cin >> S >> D;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i][j] = 1e9;
        }
    }

    dijkstra(S);

    int mini = INT_MAX;
    for (int i = 0; i <= N; i++) {
        mini = min(mini, dist[D][i]);
    }

    cout << mini << '\n';

    int hap = 0;
    for (int i = 1; i <= K; i++) {
        int temp;
        cin >> temp;
        hap += temp;

        mini = INT_MAX;
        for (int j = 0; j < N; j++) {
            mini = min(mini, dist[D][j] + hap * j);
        }

        cout << mini << '\n';
    }

    return 0;
}
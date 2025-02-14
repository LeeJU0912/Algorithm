#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> links;
bool cantGo[1001][1001];
int dist[1001];

int mini;
int ans;

void firstDijkstra() {
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int nowDist = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (nowNode == N) {
            mini = nowDist;
            return;
        }

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = graph[nowNode][i].first;
            int nextNode = graph[nowNode][i].second;

            if (nowDist + nextDist >= dist[nextNode]) continue;
            dist[nextNode] = nowDist + nextDist;

            pq.push({dist[nextNode], nextNode});
        }
    }
}

void dijkstra() {
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int nowDist = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (nowNode == N) {
            ans = max(ans, nowDist - mini);
            return;
        }

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = graph[nowNode][i].first;
            int nextNode = graph[nowNode][i].second;

            if (cantGo[nowNode][nextNode]) continue;
            if (nowDist + nextDist >= dist[nextNode]) continue;
            dist[nextNode] = nowDist + nextDist;

            pq.push({dist[nextNode], nextNode});
        }
    }

    if (dist[N] == 1e9) {
        ans = INT_MAX;
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        graph[a].push_back({t, b});
        graph[b].push_back({t, a});

        links.push_back({a, b});
    }

    firstDijkstra();

    for (int i = 0; i < M; i++) {
        cantGo[links[i].first][links[i].second] = true;
        cantGo[links[i].second][links[i].first] = true;

        dijkstra();

        cantGo[links[i].first][links[i].second] = false;
        cantGo[links[i].second][links[i].first] = false;
    }

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
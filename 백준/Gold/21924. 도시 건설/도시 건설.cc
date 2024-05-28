#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[100001];
bool visited[100001];

long long hap;
long long shortest;

void mst() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        long long now_dist = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (visited[now_node]) continue;
        visited[now_node] = true;

        shortest += now_dist;

        for (int i = 0; i < graph[now_node].size(); i++) {
            long long next_dist = graph[now_node][i].first;
            int next_node = graph[now_node][i].second;

            pq.push({next_dist, next_node});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});

        hap += c;
    }

    mst();

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << hap - shortest;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
vector<pair<long long, int>> graph[100001];
long long dist[100001];

int ansCity = INT_MAX;
long long ansDist;

void go(int start) {
    queue<pair<int, long long>> q;
    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        int now = q.front().first;
        long long nowDist = q.front().second;
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].second;
            long long nextDist = graph[now][i].first;

            if (dist[next] <= dist[now] + nextDist) continue;
            dist[next] = dist[now] + nextDist;
            q.push({next, nowDist + nextDist});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e11;
    }

    for (int i = 0; i < M; i++) {
        int U, V, C;
        cin >> U >> V >> C;
        graph[V].push_back({C, U});
    }

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        go(x);
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] > ansDist) {
            ansDist = dist[i];
            ansCity = i;
        }
    }

    cout << ansCity << '\n' << ansDist;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
int dist[1001];
bool visited[1001];
int ans;

void mst() {
    dist[1] = 0;
    visited[1] = true;

    for (int i = 0; i < graph[1].size(); i++) {
        int next = graph[1][i].second;
        int distance = graph[1][i].first;
        dist[next] = distance;
    }

    for (int i = 2; i <= N; i++) {
        int min_cost = INT_MAX;
        int min_idx = -1;

        for (int j = 1; j <= N; j++) {
            if (visited[j]) continue;
            if (min_cost > dist[j]) {
                min_cost = dist[j];
                min_idx = j;
            }
        }
        
        visited[min_idx] = true;
        ans += min_cost;

        for (int j = 0; j < graph[min_idx].size(); j++) {
            int next = graph[min_idx][j].second;
            int distance = graph[min_idx][j].first;
            if (visited[next]) continue;
            if (dist[next] > distance) dist[next] = distance;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    for (int i = 1; i < 1001; i++) {
        dist[i] = INT_MAX;
    }

    mst();

    cout << ans;

    return 0;
}
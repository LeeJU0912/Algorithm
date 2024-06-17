#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
vector<pair<int, int>> graph[301];
int dist[301][301];

void dijkstra() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 1});

    while(!q.empty()) {
        int now_node = q.front().first.second;
        int counter = q.front().second;
        q.pop();

        if (counter > M) continue;

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_node = graph[now_node][i].second;
            int next_dist = graph[now_node][i].first;

            if (dist[now_node][counter] + next_dist <= dist[next_node][counter + 1]) continue;
            dist[next_node][counter + 1] = dist[now_node][counter] + next_dist;

            q.push({{dist[next_node][counter + 1], next_node}, counter + 1});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) continue;

        graph[a].push_back({c, b});
    }

    dijkstra();

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans = max(ans, dist[N][i]);
    }
    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

vector<pair<pair<int, int>, int>> graph[501];
int dist[501][501];
bool visited[501][501];

int FindNode(int k) {
    int mini = INT_MAX;
    int idx = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i][k]) continue;
        if (dist[i][k] < mini) {
            mini = dist[i][k];
            idx = i;
        }
    }

    return idx;
}

void dijkstra() {
    dist[1][0] = 0;

    for (int k = 0; k <= K; k++) {
        for (int i = 0; i < N; i++) {
            int new_node = FindNode(k);
            visited[new_node][k] = true;
            
            if (k < K) {
                for (auto next : graph[new_node]) {
                    if (visited[next.second][k + 1]) continue;
                    if (dist[next.second][k + 1] > dist[new_node][k] + next.first.first) {
                        dist[next.second][k + 1] = dist[new_node][k] + next.first.first;
                    }
                }
            }

            for (auto next : graph[new_node]) {
                if (dist[new_node][k] % next.first.second == 0) {
                    if (visited[next.second][k]) continue;
                    if (dist[next.second][k] > dist[new_node][k] + next.first.first) {
                        dist[next.second][k] = dist[new_node][k] + next.first.first;
                    }
                }
                else {
                    if (visited[next.second][k]) continue;
                    if (dist[next.second][k] > dist[new_node][k] + next.first.first + next.first.second - (dist[new_node][k] % next.first.second)) {
                        dist[next.second][k] = dist[new_node][k] + next.first.first + next.first.second - (dist[new_node][k] % next.first.second);
                    }
                }
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        int s, e, t, g;
        cin >> s >> e >> t >> g;

        graph[s].push_back({{t, g}, e});
    }

    dijkstra();

    int ans = INT_MAX;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[N][i]);
    }

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
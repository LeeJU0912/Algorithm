#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> graph[202];

int capacity[202][202];
int flow[202][202];
int cost[202][202];

int before[202];
int dist[202];
bool inQueue[202];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 101; i <= 100 + N; i++) {
        cin >> capacity[i][201];
        graph[i].push_back(201);
        graph[201].push_back(i);
    }
    for (int i = 1; i <= M; i++) {
        cin >> capacity[0][i];
        graph[0].push_back(i);
        graph[i].push_back(0);
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 101; j <= 100 + N; j++) {
            cin >> cost[i][j];

            cost[j][i] = -cost[i][j];
            capacity[i][j] = INT_MAX;

            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }

    int ans = 0;
    while(true) {
        memset(inQueue, false, sizeof(inQueue));
        memset(before, -1, sizeof(before));
        fill(dist, dist + 202, INT_MAX);

        queue<int> q;
        dist[0] = 0;
        inQueue[0] = true;
        q.push(0);

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            inQueue[now] = false;

            for (int next : graph[now]) {
                if (capacity[now][next] - flow[now][next] > 0 && dist[next] > dist[now] + cost[now][next]) {
                    dist[next] = dist[now] + cost[now][next];
                    before[next] = now;

                    if (!inQueue[next]) {
                        q.push(next);
                        inQueue[next] = true;
                    }
                }
            }
        }

        if (before[201] == -1) break;

        int f = INT_MAX;
        for (int i = 201; i != 0; i = before[i]) {
            f = min(f, capacity[before[i]][i] - flow[before[i]][i]);
        }

        for (int i = 201; i != 0; i = before[i]) {
            ans += f * cost[before[i]][i];
            flow[before[i]][i] += f;
            flow[i][before[i]] -= f;
        }
    }

    cout << ans;

    return 0;
}
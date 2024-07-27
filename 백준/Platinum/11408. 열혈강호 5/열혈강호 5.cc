#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> graph[802];

int capacity[802][802];
int flow[802][802];
int cost[802][802];

int before[802];
int dist[802];
bool inQueue[802];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        capacity[0][i] = 1;
        graph[0].push_back(i);
        graph[i].push_back(0);

        for (int j = 0; j < x; j++) {
            int a, b;
            cin >> a >> b;
            cost[i][a + 400] = b;
            cost[a + 400][i] = -b;
            capacity[i][a + 400] = INT_MAX;
            graph[i].push_back(a + 400);
            graph[a + 400].push_back(i);
        }
    }
    for (int i = 1; i <= M; i++) {
        capacity[400 + i][801] = 1;
        graph[400 + i].push_back(801);
        graph[801].push_back(400 + i);
    }

    int ans = 0;
    int ans2 = 0;
    while(true) {
        memset(inQueue, false, sizeof(inQueue));
        memset(before, -1, sizeof(before));
        fill(dist, dist + 802, INT_MAX);

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

        if (before[801] == -1) break;

        for (int i = 801; i != 0; i = before[i]) {
            ans += cost[before[i]][i];
            flow[before[i]][i]++;
            flow[i][before[i]]--;
        }
        ans2++;
    }

    cout << ans2 << '\n' << ans;

    return 0;
}
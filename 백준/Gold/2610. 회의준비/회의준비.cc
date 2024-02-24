#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int dist[101][101];
vector<int> graph[101];
bool visited[101];

set<int> ans;

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        vector<int> group;

        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            group.push_back(now);

            for (int j = 0; j < graph[now].size(); j++) {
                int next = graph[now][j];

                if (visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }

        int mini = INT_MAX;
        int to_insert;

        for (int j = 0; j < group.size(); j++) {
            int now = group[j];

            int maxi = 0;
            for (int k = 0; k < group.size(); k++) {
                if (now == group[k]) continue;
                int next = group[k];

                maxi = max(maxi, dist[now][next]);
            }

            if (maxi < mini) {
                mini = maxi;
                to_insert = now;
            }
        }
        ans.insert(to_insert);
    }

    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << '\n';
    }

    return 0;
}
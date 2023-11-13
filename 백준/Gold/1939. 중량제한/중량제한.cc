#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int x, y;

bool solve(int constraint) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;

    for (int i = 0; i < graph[x].size(); i++) {
        if (graph[x][i].first < constraint) continue;
        if (visited[graph[x][i].second]) continue;
        visited[graph[x][i].second] = true;
        q.push(graph[x][i]);
    }

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.second == y) {
            return true;
        }

        for (int i = 0; i < graph[now.second].size(); i++) {
            if (graph[now.second][i].first < constraint) continue;
            if (visited[graph[now.second][i].second]) continue;
            visited[graph[now.second][i].second] = true;

            q.push({min(now.first, graph[now.second][i].first), graph[now.second][i].second});
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cin >> x >> y;

    int s = 1;
    int e = 1000000000;

    int ans;

    while(s <= e) {
        int mid = (s + e) / 2;

        if (solve(mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
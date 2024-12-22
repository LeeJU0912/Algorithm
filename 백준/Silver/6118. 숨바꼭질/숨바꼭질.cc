#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> graph[20001];
int dist[20001];

void solve() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (dist[now] + 1 >= dist[next]) continue;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
}

int main() {
    FastIO

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve();

    int maxi = 0;
    for (int i = 1; i <= N; i++) {
        maxi = max(maxi, dist[i]);
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == maxi) ans.push_back(i);
    }

    cout << ans[0] << ' ' << maxi << ' ' << ans.size() << '\n';

    return 0;
}
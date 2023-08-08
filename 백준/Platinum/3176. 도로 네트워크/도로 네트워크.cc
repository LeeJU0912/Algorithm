#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> graph[100001];
int depth[100001];
int lca[1000001][21][3];
int K;

void dfs(int now, int parent) {
    for (int i = 0; i < graph[now].size(); i++) {
        auto next = graph[now][i];
        if (next.second == parent) continue;

        depth[next.second] = depth[now] + 1;

        lca[next.second][0][0] = now;
        lca[next.second][0][1] = lca[next.second][0][2] = next.first;

        for (int j = 1; j < 21; j++) {
            lca[next.second][j][0] = lca[lca[next.second][j - 1][0]][j - 1][0];
            lca[next.second][j][1] = min(lca[lca[next.second][j - 1][0]][j - 1][1], lca[next.second][j - 1][1]);
            lca[next.second][j][2] = max(lca[lca[next.second][j - 1][0]][j - 1][2], lca[next.second][j - 1][2]);
        }

        dfs(next.second, now);
    }
}

pair<int, int> find(int a, int b) {
    pair<int, int> ans;
    ans.first = INT_MAX;
    ans.second = 0;

    if (depth[a] > depth[b]) swap(a, b);

    for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= depth[b] - depth[a]) {
            ans.first = min(ans.first, lca[b][i][1]);
            ans.second = max(ans.second, lca[b][i][2]);
            b = lca[b][i][0];
        }
    }

    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (lca[a][i][0] != lca[b][i][0]) {
                ans.first = min(ans.first, min(lca[b][i][1], lca[a][i][1]));
                ans.second = max(ans.second, max(lca[b][i][2], lca[a][i][2]));
                a = lca[a][i][0];
                b = lca[b][i][0];
            }
        }
        ans.first = min(ans.first, min(lca[b][0][1], lca[a][0][1]));
        ans.second = max(ans.second, max(lca[b][0][2], lca[a][0][2]));
    }

    return ans;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dfs(1, 0);

    cin >> K;

    for (int i = 0; i < K; i++) {
        int d, e;
        cin >> d >> e;

        auto ans = find(d, e);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
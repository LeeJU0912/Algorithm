#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[40001];
int depth[40001];
int ancestor[40001][20];
int dist[40001];

int max_level;

void getTree(int now, int parent, int Plus) {
    depth[now] = depth[parent] + 1;

    dist[now] = dist[parent] + Plus;

    ancestor[now][0] = parent;

    max_level = (int)floor(log2(40000));

    for (int i = 1; i <= max_level; i++) {
        int temp = ancestor[now][i - 1];
        ancestor[now][i] = ancestor[temp][i - 1];
    }

    for (int i = 0; i < graph[now].size(); i++) {
        auto next = graph[now][i];
        if (next.second != parent) {
            getTree(next.second, now, next.first);
        }
    }
}

int find_lca(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        for (int i = max_level; i >= 0; i--) {
            if (depth[a] <= depth[ancestor[b][i]]) {
                b = ancestor[b][i];
            }
        }
    }

    int lca = a;

    if (a != b) {
        for (int i = max_level; i >= 0; i--) {
            if (ancestor[a][i] != ancestor[b][i]) {
                a = ancestor[a][i];
                b = ancestor[b][i];
            }
        }
        lca = ancestor[a][0];
    }

    return lca;
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

    depth[0] = -1;
    getTree(1, 0, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << dist[a] + dist[b] - 2 * dist[find_lca(a, b)] << '\n';
    }

    return 0;
}
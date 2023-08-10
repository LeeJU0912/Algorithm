#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<int> graph[30001];
int depth[30001];
int ancestor[30001][20];
int dist[30001];
bool visited[30001];

void make_tree(int now, int parent, int count) {
    visited[now] = true;
    depth[now] = depth[parent] + 1;
    ancestor[now][0] = parent;
    dist[now] = count;

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (visited[next]) continue;
        make_tree(next, now, count + 1);
    }
}

int find_lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    for (int i = 19; i >= 0; i--) {
        if (depth[a] <= depth[ancestor[b][i]]) {
            b = ancestor[b][i];
        }
    }

    int lca = a;

    if (a != b) {
        for (int i = 19; i >= 0; i--) {
            if (ancestor[a][i] != ancestor[b][i]) {
                a = ancestor[a][i];
                b = ancestor[b][i];
            }
            lca = ancestor[a][i];
        }
    }

    return lca;
}

int main() {
    FastIO

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    make_tree(1, 0, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
        }
    }

    int m;
    cin >> m;

    vector<int> city;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        city.push_back(temp);
    }

    int ans = 0;

    ans += dist[city[0]];

    for (int i = 1; i < m; i++) {
        ans += dist[city[i - 1]] + dist[city[i]] - 2 * dist[find_lca(city[i - 1], city[i])];
    }

    cout << ans;

    return 0;
}
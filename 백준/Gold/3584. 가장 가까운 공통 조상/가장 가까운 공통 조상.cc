#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int depth[10001];
int ancestor[10001][20];
int parent[10001];

vector<int> graph[10001];

int max_level;

void makeTree(int now, int before) {
    depth[now] = depth[before] + 1;

    ancestor[now][0] = before;

    max_level = (int)floor(log2(10001));

    for (int i = 1; i <= max_level; i++) {
        int temp = ancestor[now][i - 1];
        ancestor[now][i] = ancestor[temp][i - 1];
    }

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (next != before) {
            makeTree(next, now);
        }
    }
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        memset(depth, 0, sizeof(depth));
        memset(ancestor, 0, sizeof(ancestor));
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i <= 10000; i++) {
            graph[i].clear();
        }

        int N;
        cin >> N;
        for (int i = 1; i < N; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            parent[b] = a;
        }

        int root;
        for (int i = 1; i <= N; i++) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }

        depth[0] = -1;

        makeTree(root, 0);

        int x, y;
        cin >> x >> y;

        if (depth[x] != depth[y]) {
            if (depth[x] > depth[y]) {
                swap(x, y);
            }

            for (int i = max_level; i >= 0; i--) {
                if (depth[x] <= depth[ancestor[y][i]])
                    y = ancestor[y][i];
            }
        }

        int lca = x;

        if (x != y) {
            for (int i = max_level; i >= 0; i--) {
                if (ancestor[x][i] != ancestor[y][i]) {
                    x = ancestor[x][i];
                    y = ancestor[y][i];
                }
                lca = ancestor[x][i];
            }
        }

        cout << lca << '\n';
    }

    return 0;
}
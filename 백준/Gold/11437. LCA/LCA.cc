#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph[50001];
int depth[50001];
int ancestor_save[50001][20];

int max_level;

void make_tree(int now, int parent) {
    depth[now] = depth[parent] + 1;

    ancestor_save[now][0] = parent;

    max_level = (int)floor(log2(50001));

    for (int i = 1; i <= max_level; i++) {
        int temp = ancestor_save[now][i - 1];
        ancestor_save[now][i] = ancestor_save[temp][i - 1];
    }

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (next != parent) make_tree(next, now);
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int root_node = 1;

    depth[0] = -1;
    make_tree(root_node, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b]) {
                swap(a, b);
            }
            for (int j = max_level; j >= 0; j--) {
                if (depth[a] <= depth[ancestor_save[b][j]])
                    b = ancestor_save[b][j];
            }
        }

        int ans = a;

        if (a != b) {
            for (int j = max_level; j >= 0; j--) {
                if (ancestor_save[a][j] != ancestor_save[b][j]) {
                    a = ancestor_save[a][j];
                    b = ancestor_save[b][j];
                }
                ans = ancestor_save[a][j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
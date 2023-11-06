#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, C;
vector<int> graph[200001];
vector<long long> tree;

pair<int, int> range[200001];
int depth[200001];

int dfs_counter;

void dfs(int now, int before, int depth_counter) {
    range[now].first = ++dfs_counter;

    depth[now] = depth_counter;

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];

        if (next == before) continue;
        dfs(next, now, depth_counter + 1);
    }

    range[now].second = dfs_counter;
}

void update(int node, int left, int right, int target) {
    if (target > right || target < left) return;
    tree[node]++;

    if (left == right) return;

    update(node * 2, left, (left + right) / 2, target);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target);
}

long long query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N >> C;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(C, 0, 1);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int order, A;
        cin >> order >> A;

        if (order == 1) {
            update(1, 1, N, range[A].first);
        }
        else {
            cout << query(1, 1, N, range[A].first, range[A].second) * depth[A] << '\n';
        }
    }

    return 0;
}
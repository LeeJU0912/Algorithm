#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> tree;
vector<int> lazy;
vector<int> graph[100001];
pair<int, int> save[100001];

int dfs_counter;
void dfs(int now, int before) {
    dfs_counter++;

    save[now].first = dfs_counter;

    for (int i : graph[now]) {
        if (i == before) continue;
        dfs(i, now);
    }

    save[now].second = dfs_counter;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int start, int end, int val) {
    update_lazy(node, left, right);
    if (right < start || left > end) return;
    if (start <= left && right <= end) {
        lazy[node] += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, start, end, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int start, int end) {
    update_lazy(node, left, right);
    if (right < start || end < left) return 0;
    if (start <= left && right <= end) return tree[node];

    int l = query(node * 2, left, (left + right) / 2, start, end);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N >> M;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);
    lazy = vector<int>(tree_size);

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        if (i != 1) {
            graph[temp].push_back(i);
        }
    }

    dfs(1, 0);

    for (int i = 0; i < M; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int a, b;
            cin >> a >> b;
            update(1, 1, N, save[a].first, save[a].second, b);
        }
        else if (order == 2) {
            int a;
            cin >> a;
            cout << query(1, 1, N, save[a].first, save[a].first) << '\n';
        }
    }

    return 0;
}
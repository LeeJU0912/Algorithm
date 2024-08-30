#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<pair<int, int>> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {save[left], 0};
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = {max(tree[node * 2].first, tree[node * 2 + 1].first), max(max(tree[node * 2].second, tree[node * 2 + 1].second), tree[node * 2].first + tree[node * 2 + 1].first)};
}

void update(int node, int left, int right, int target, int val) {
    if (right < target || left > target) return;
    if (left == right) {
        tree[node] = {val, 0};
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = {max(tree[node * 2].first, tree[node * 2 + 1].first), max(max(tree[node * 2].second, tree[node * 2 + 1].second), tree[node * 2].first + tree[node * 2 + 1].first)};
}

pair<int, int> query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return {0, 0};
    if (start <= left && right <= end) {
        return tree[node];
    }

    pair<int, int> l = query(node * 2, left, (left + right) / 2, start, end);
    pair<int, int> r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return {max(l.first, r.first), max(max(l.second, r.second), l.first + r.first)};
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    save = vector<int>(N + 1);
    tree = vector<pair<int, int>>(tree_size);

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    init(1, 1, N);

    cin >> M;
    for (int x = 0; x < M; x++) {
        int order;
        cin >> order;

        if (order == 1) {
            int i, v;
            cin >> i >> v;

            update(1, 1, N, i, v);
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, N, l, r).second << '\n';
        }
    }

    return 0;
}
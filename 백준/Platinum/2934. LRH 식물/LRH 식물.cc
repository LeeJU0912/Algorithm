#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> tree;
vector<int> lazy;

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

int query(int node, int left, int right, int target) {
    update_lazy(node, left, right);
    if (right < target || target < left) return 0;
    if (left == right) return tree[node];

    int l = query(node * 2, left, (left + right) / 2, target);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, target);

    return l + r;
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(100000));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);
    lazy = vector<int>(tree_size);

    for (int i = 1; i <= N; i++) {
        int L, R;
        cin >> L >> R;

        int l = query(1, 1, 100000, L);
        int r = query(1, 1, 100000, R);

        cout << l + r << '\n';

        update(1, 1, 100000, L, L, -l);
        update(1, 1, 100000, R, R, -r);

        if (L + 1 != R) {
            update(1, 1, 100000, L + 1, R - 1, 1);
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> A;
vector<long long> tree;
vector<long long> lazy;
int Q;

void propagate(int node, int left, int right) {
    if (lazy[node] != 0) {
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] += (right - left + 1) * lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int start, int end, int val) {
    propagate(node, left, right);
    if (right < start || left > end) return;
    if (start <= left && right <= end) {
        lazy[node] = val;
        propagate(node, left, right);
        return;
    }

    update(node * 2, left, (left + right) / 2, start, end, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    propagate(node, left, right);
    if (right < start || end < left) return 0;
    if (start <= left && right <= end) {
        return tree[node];
    }

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N;
    A = vector<int>(N + 1);
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);
    lazy = vector<long long>(tree_size);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        update(1, 1, N, i, i, A[i] - A[i - 1]);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int l, r;
            cin >> l >> r;
            update(1, 1, N, l, r, 1);
            update(1, 1, N, r + 1, r + 1, -(r - l + 1));
        }
        else if (order == 2) {
            int X;
            cin >> X;
            cout << query(1, 1, N, 1, X) << '\n';
        }
    }

    return 0;
}
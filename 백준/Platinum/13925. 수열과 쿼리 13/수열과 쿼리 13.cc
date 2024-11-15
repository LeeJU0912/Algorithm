#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000007

int N, M;
vector<long long> save;
vector<long long> tree;
vector<long long> lazy_plus;
vector<long long> lazy_multiply;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = save[left];
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void update_lazy_plus(int node, int start, int end) {
    if (lazy_plus[node] != 0) {
        if (start != end) {
            lazy_plus[node * 2] += lazy_plus[node];
            lazy_plus[node * 2] %= MOD;
            lazy_plus[node * 2 + 1] += lazy_plus[node];
            lazy_plus[node * 2 + 1] %= MOD;
        }

        tree[node] += (lazy_plus[node] * (end - start + 1)) % MOD;
        tree[node] %= MOD;
        lazy_plus[node] = 0;
    }
}

void update_lazy_multiply(int node, int start, int end) {
    if (lazy_multiply[node] != 1) {
        if (start != end) {
            lazy_plus[node * 2] *= lazy_multiply[node];
            lazy_plus[node * 2] %= MOD;
            lazy_multiply[node * 2] *= lazy_multiply[node];
            lazy_multiply[node * 2] %= MOD;

            lazy_plus[node * 2 + 1] *= lazy_multiply[node];
            lazy_plus[node * 2 + 1] %= MOD;
            lazy_multiply[node * 2 + 1] *= lazy_multiply[node];
            lazy_multiply[node * 2 + 1] %= MOD;
        }

        tree[node] *= lazy_multiply[node];
        tree[node] %= MOD;
        lazy_multiply[node] = 1;
    }
}

void update_range_plus(int node, int left, int right, int start, int end, int val) {
    update_lazy_plus(node, left, right);

    if (right < start || end < left) return;
    if (start <= left && right <= end) {
        lazy_plus[node] += val;
        lazy_plus[node] %= MOD;

        update_lazy_plus(node, left, right);
        return;
    }
    update_range_plus(node * 2, left, (left + right) / 2, start, end, val);
    update_range_plus(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void update_range_multiply(int node, int left, int right, int start, int end, int val) {
    update_lazy_multiply(node, left, right);
    update_lazy_plus(node, left, right);

    if (right < start || end < left) return;
    if (start <= left && right <= end) {
        lazy_plus[node] *= val;
        lazy_plus[node] %= MOD;
        lazy_multiply[node] *= val;
        lazy_multiply[node] %= MOD;

        update_lazy_multiply(node, left, right);
        update_lazy_plus(node, left, right);
        return;
    }

    update_range_multiply(node * 2, left, (left + right) / 2, start, end, val);
    update_range_multiply(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

long long query(int node, int left, int right, int start, int end) {
    update_lazy_multiply(node, left, right);
    update_lazy_plus(node, left, right);

    if (start > right || end < left) return 0;
    if (start <= left && right <= end) return tree[node] % MOD;

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return (l + r) % MOD;
}

int main() {
    FastIO

    cin >> N;
    save = vector<long long>(N);

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);
    lazy_plus = vector<long long>(tree_size, 0);
    lazy_multiply = vector<long long>(tree_size, 1);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    init(1, 0, N - 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int order;
        cin >> order;

        if (order == 4) {
            int x, y;
            cin >> x >> y;
            cout << query(1, 0, N - 1, x - 1, y - 1) << '\n';
        }
        else {
            int x, y, v;
            cin >> x >> y >> v;

            if (order == 1) {
                update_range_multiply(1, 0, N - 1, x - 1, y - 1, 1);
                update_range_plus(1, 0, N - 1, x - 1, y - 1, v);
            }
            else if (order == 2) {
                update_range_multiply(1, 0, N - 1, x - 1, y - 1, v);
                update_range_plus(1, 0, N - 1, x - 1, y - 1, 0);
            }
            else if (order == 3) {
                update_range_multiply(1, 0, N - 1, x - 1, y - 1, 0);
                update_range_plus(1, 0, N - 1, x - 1, y - 1, v);
            }
        }
    }

    return 0;
}
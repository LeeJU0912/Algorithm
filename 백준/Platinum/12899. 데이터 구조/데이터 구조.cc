#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> tree;

void update(int node, int left, int right, int target, int val) {
    if (left > target || right < target) return;
    if (left == right) {
        tree[node] += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int kth) {
    if (left == right) return left;

    if (kth <= tree[2 * node]) return query(node * 2, left, (left + right) / 2, kth);
    else return query(node * 2 + 1, (left + right) / 2 + 1, right, kth - tree[2 * node]);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(2000000));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    for (int i = 0; i < N; i++) {
        int T, X;
        cin >> T >> X;

        if (T == 1) {
            update(1, 1, 2000000, X , 1);
        }
        else {
            int idx = query(1, 1, 2000000, X);
            cout << idx << '\n';
            update(1, 1, 2000000, idx, -1);
        }
    }

    return 0;
}
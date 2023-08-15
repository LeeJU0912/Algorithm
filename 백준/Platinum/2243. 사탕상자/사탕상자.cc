#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<int> tree;

void update(int node, int left, int right, int target, int val) {
    if (target < left || target > right) return;
    if (left == right) {
        tree[node] += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int nth) {
    if (left == right) return left;

    if (nth <= tree[node * 2]) return query(node * 2, left, (left + right) / 2, nth);
    else return query(node * 2 + 1, (left + right) / 2 + 1, right, nth - tree[node * 2]);
}

int main() {
    FastIO

    int tree_depth = (int)ceil(log2(1000000));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int a;
            cin >> a;

            int now = query(1, 1, 1000000, a);
            cout << now << '\n';
            update(1, 1, 1000000, now, -1);
        }
        else {
            int a, b;
            cin >> a >> b;

            update(1, 1, 1000000, a, b);
        }
    }

    return 0;
}
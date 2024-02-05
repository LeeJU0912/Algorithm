#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct Node {
    long long all_sum;
    long long left_sum;
    long long right_sum;
    long long max_sum;
    int left;
    int right;
};

Node merge(Node a, Node b) {
    Node c;

    c.left = a.left;
    c.right = b.right;

    if (a.right == b.left) {
        c.all_sum = -1e9;
        c.left_sum = a.left_sum;
        c.right_sum = b.right_sum;
        c.max_sum = max(a.max_sum, b.max_sum);

        return c;
    }

    c.all_sum = a.all_sum + b.all_sum;
    c.right_sum = max(b.right_sum, a.right_sum + b.all_sum);
    c.left_sum = max(a.left_sum, a.all_sum + b.left_sum);
    c.max_sum = max(max(a.max_sum, b.max_sum), a.right_sum + b.left_sum);

    return c;
}

int N, Q;
vector<Node> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {1, 1, 1, 1, 0, 0};
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int left, int right, int target) {
    if (right < target || left > target) return;
    if (left == right) {
        tree[node].left = !tree[node].left;
        tree[node].right = !tree[node].right;
        return;
    }

    update(node * 2, left, (left + right) / 2, target);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    FastIO

    cin >> N >> Q;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<Node>(tree_size);

    init(1, 0, N - 1);

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        update(1, 0, N - 1, x - 1);

        cout << tree[1].max_sum << '\n';
    }

    return 0;
}
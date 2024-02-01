#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct Node {
    long long all_sum;
    long long left_sum;
    long long right_sum;
    long long max_sum;
};

Node merge(Node a, Node b) {
    Node X;
    X.all_sum = a.all_sum + b.all_sum;
    X.left_sum = max(a.left_sum, a.all_sum + b.left_sum);
    X.right_sum = max(b.right_sum, b.all_sum + a.right_sum);
    X.max_sum = max(max(a.max_sum, b.max_sum), a.right_sum + b.left_sum);

    return X;
}

int N, M;
vector<int> A;
vector<Node> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {A[left], A[left], A[left], A[left]};
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    if (start <= left && right <= end) return tree[node];

    Node L = query(node * 2, left, (left + right) / 2, start, end);
    Node R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return merge(L, R);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<Node>(tree_size);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        A.push_back(a);
    }

    init(1, 0, N - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(1, 0, N - 1, a - 1, b - 1).max_sum << '\n';
    }

    return 0;
}
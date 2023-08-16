#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
vector<int> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = 1;
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

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

int query(int node, int left, int right, int kth) {
    if (left == right) return left;

    if (kth < tree[node * 2]) return query(node * 2, left, (left + right) / 2, kth);
    else return query(node * 2 + 1, (left + right) / 2 + 1, right, kth - tree[node * 2]);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);
    save = vector<int>(N + 1);

    init(1, 1, N);

    vector<int> input(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }

    for (int i = N; i >= 1; i--) {

        int val = query(1, 1, N, input[i]);
        save[val] = i;
        update(1, 1, N, val, -1);
    }

    for (int i = N; i >= 1; i--) {
        cout << save[i] << '\n';
    }

    return 0;
}
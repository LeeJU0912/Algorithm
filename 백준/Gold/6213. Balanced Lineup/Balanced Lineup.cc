#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
vector<int> save;
vector<pair<int, int>> tree;

void init(int node, int left, int right) {
    if (left > right) return;
    if (left == right) {
        tree[node] = {save[left], save[left]};
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second);
}

pair<int, int> query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return {0, INT_MAX};
    if (start <= left && right <= end) return tree[node];

    pair<int, int> L = query(node * 2, left, (left + right) / 2, start, end);
    pair<int, int> R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return {max(L.first, R.first), min(L.second, R.second)};
}

int main() {
    FastIO

    cin >> N >> Q;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<pair<int, int>>(tree_size);
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        auto now = query(1, 0, N - 1, A - 1, B - 1);
        cout << now.first - now.second << '\n';
    }

    return 0;
}
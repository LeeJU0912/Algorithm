#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;
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

    cin >> N >> K;
    int tree_depth = (int)ceil(log2(65537));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    for (int i = 0; i < K - 1; i++) {
        update(1, 0, 65536, save[i], 1);
    }

    long long ans = 0;
    for (int i = K - 1; i < N; i++) {
        update(1, 0, 65536, save[i], 1);
        ans += query(1, 0, 65536, (K + 1) / 2);
        update(1, 0, 65536, save[i - K + 1], -1);
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;
vector<int> tree;

void update(int node, int left, int right, int target) {
    if (right < target || left > target) return;
    if (left == right) {
        tree[node]++;
        return;
    }

    update(node * 2, left, (left + right) / 2, target);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node];

    int l = query(node * 2, left, (left + right) / 2, start, end);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N;
    save = vector<pair<int, int>>(N + 1);

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        save[i] = {temp, i};
    }

    sort(save.begin() + 1, save.end());

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            cout << save[(i / 2) + 1].second - 1 - query(1, 1, N, 1, save[i / 2 + 1].second - 1) << '\n';
            update(1, 1, N, save[(i / 2) + 1].second);
        }
        else {
            cout << N - save[N - (i / 2)].second - query(1, 1, N, save[N - (i / 2)].second + 1, N) << '\n';
            update(1, 1, N, save[N - (i / 2)].second);
        }
    }

    return 0;
}
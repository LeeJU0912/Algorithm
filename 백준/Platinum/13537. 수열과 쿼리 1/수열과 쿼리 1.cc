#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> tree[400001];

void update(int node, int left, int right, int target, int val) {
    if (right < target || left > target) return;
    tree[node].push_back(val);

    if (left != right) {
        update(node * 2, left, (left + right) / 2, target, val);
        update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);
    }
}

int query(int node, int left, int right, int start, int end, int val) {
    if (end < left || right < start) return 0;
    if (start <= left && right <= end) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);

    int l = query(node * 2, left, (left + right) / 2, start, end, val);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);

    return l + r;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        update(1, 1, N, i, temp);
    }

    for (int i = 1; i <= N * 4; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << query(1, 1, N, a, b, c) << '\n';
    }

    return 0;
}
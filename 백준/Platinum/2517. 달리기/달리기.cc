#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;
vector<int> tree;
int ans[500001];

void update(int node, int start, int end, int idx) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;

    if (idx <= mid) update(node * 2, start,  mid, idx);
    else update(node * 2 + 1, mid + 1, end, idx);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    long long mid = (start + end) / 2;
    long long left_sum = query(node * 2, start, mid, left, right);
    long long right_sum = query(node * 2 + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

int main() {
    FastIO

    cin >> N;

    int tree_depth = 1 << ((int) ceil(log2(N)) + 1);
    tree = vector<int>(tree_depth);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        save.emplace_back(temp, i);
    }

    sort(save.begin(), save.end(), greater<>());

    for (int i = 0; i < N; i++) {
        int idx = save[i].second;

        ans[idx] = query(1, 0, N - 1, 0, idx - 1) + 1;
        update(1, 0, N - 1, idx);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
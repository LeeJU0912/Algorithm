#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> tree; // 학생에 대한 세그트리

struct INFO {
    int a, b, c;

    bool operator < (const INFO &x) const {
        return a < x.a;
    }
};

vector<INFO> inputs;

void update(int node, int left, int right, int target, int value) {
    if (left > target || right < target) {
        return;
    }

    if (left == right) {
        tree[node] = value;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, value);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, value);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) {
        return 1e9;
    }
    if (start <= left && right <= end) {
        return tree[node];
    }

    int l = query(node * 2, left, (left + right) / 2, start, end);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return min(l, r);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size, 1e9);

    inputs = vector<INFO>(N + 1);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        inputs[x].a = i;
    }
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        inputs[x].b = i;
    }
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        inputs[x].c = i;
    }

    sort(++inputs.begin(), inputs.end());

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int q = query(1, 1, N, 1, inputs[i].b - 1);

        if (q >= inputs[i].c) {
            ans++;
        }

        update(1, 1, N, inputs[i].b, inputs[i].c);
    }

    cout << ans;

    return 0;
}
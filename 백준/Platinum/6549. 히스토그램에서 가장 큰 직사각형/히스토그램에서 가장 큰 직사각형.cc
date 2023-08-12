#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<long long> save;
vector<int> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    if (save[tree[node * 2]] < save[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    }
    else {
        tree[node] = tree[node * 2 + 1];
    }
}

int query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return -1;
    if (start <= left && right <= end) return tree[node];

    int l = query(node * 2, left, (left + right) / 2, start, end);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    if (l == -1) return r;
    if (r == -1) return l;
    if (save[l] < save[r]) return l;
    else return r;
}

long long solve(int start, int end) {
    if (start == end) return save[start];

    int min_idx = query(1, 0, n - 1, start, end);
    long long ans = save[min_idx] * (end - start + 1);

    if (min_idx > start) {
        ans = max(ans, solve(start, min_idx - 1));
    }
    if (min_idx < end) {
        ans = max(ans, solve(min_idx + 1, end));
    }

    return ans;
}

int main() {
    FastIO

    while(true) {
        cin >> n;
        if (n == 0) break;

        int tree_height = (int)ceil(log2(n));
        int tree_size = (1 << (tree_height + 1));
        tree = vector<int>(tree_size);
        save.clear();

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            save.push_back(temp);
        }

        init(1, 0, n - 1);

        cout << solve(0, n - 1) << '\n';
    }

    return 0;
}
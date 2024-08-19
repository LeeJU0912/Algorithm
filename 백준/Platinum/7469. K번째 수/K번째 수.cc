#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int save[100001];
vector<int> tree[400001];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node].push_back(save[left]);
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
}

int query(int node, int left, int right, int start, int end, int target) {
    if (right < start || end < left) return 0;
    if (start <= left && right <= end) {
        return lower_bound(tree[node].begin(), tree[node].end(), target) - tree[node].begin();
    }

    int l = query(node * 2, left, (left + right) / 2, start, end, target);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end, target);

    return l + r;
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> save[i];
    }

    init(1, 1, n);

    // 5000회 시행
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int start = -1e9;
        int end = 1e9;
        int ans;

        while(start <= end) {
            int mid = (start + end) / 2;

            int calc = query(1, 1, n, a, b, mid);

            if (calc < c) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        cout << ans <<'\n';
    }

    return 0;
}
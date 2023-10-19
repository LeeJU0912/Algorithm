#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<long long> tree;
vector<pair<int, int>> q;
vector<pair<int, pair<int, int>>> two[100001];

vector<pair<int, long long>> ans;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = save[left];
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int left, int right, int target, int val) {
    if (target < left || target > right) return;
    if (left == right) {
        tree[node] = val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N;

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    init(1, 0, N - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int a, b;
            cin >> a >> b;
            q.push_back({a, b});
        }
        else if (order == 2) {
            int a, b, c;
            cin >> a >> b >> c;
            two[a].push_back({i, {b, c}});
        }
    }

    for (int i = 0; i < two[0].size(); i++) {
        ans.push_back({two[0][i].first, query(1, 0, N - 1, two[0][i].second.first - 1, two[0][i].second.second - 1)});
    }

    for (int i = 0; i < q.size(); i++) {
        update(1, 0, N - 1, q[i].first - 1, q[i].second);

        for (int j = 0; j < two[i + 1].size(); j++) {
            ans.push_back({two[i + 1][j].first, query(1, 0, N - 1, two[i + 1][j].second.first - 1, two[i + 1][j].second.second - 1)});
        }
    }

    sort(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i.second << '\n';
    }

    return 0;
}
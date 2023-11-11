#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<long long> tree;
vector<long long> lazy;
vector<int> graph[500001];
pair<int, int> save[500001];
vector<int> salary;
vector<int> salary_sorted;

int dfs_counter;
void dfs(int now, int before) {
    dfs_counter++;

    salary_sorted[dfs_counter] = salary[now];
    save[now].first = dfs_counter;

    for (int i : graph[now]) {
        if (i == before) continue;
        dfs(i, now);
    }

    save[now].second = dfs_counter;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = salary_sorted[start];
        return;
    }

    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int start, int end, int val) {
    update_lazy(node, left, right);
    if (right < start || left > end) return;
    if (start <= left && right <= end) {
        lazy[node] += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, start, end, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int target) {
    update_lazy(node, left, right);
    if (right < target || target < left) return 0;
    if (left == right) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, target);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, target);

    return l + r;
}

int main() {
    FastIO

    cin >> N >> M;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);
    lazy = vector<long long>(tree_size);
    salary = vector<int>(N + 1);
    salary_sorted = vector<int>(N + 1);

    int temp;
    cin >> temp;

    salary[1] = temp;

    for (int i = 2; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        graph[b].push_back(i);
        salary[i] = a;
    }

    dfs(1, 0);

    init(1, 1, N);

    for (int i = 0; i < M; i++) {
        char order;
        cin >> order;

        if (order == 'p') {
            int a, b;
            cin >> a >> b;
            if (save[a].first + 1 <= save[a].second) {
                update(1, 1, N, save[a].first + 1, save[a].second, b);
            }
        }
        else if (order == 'u') {
            int a;
            cin >> a;
            cout << query(1, 1, N, save[a].first) << '\n';
        }
    }

    return 0;
}
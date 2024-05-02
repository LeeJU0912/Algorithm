#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int tree[10001][2];
int nodes[10001];
int dist[10001][2];

int root;

int ans_level = 1;
int ans = 1;

void solve(int node, int level, int idx, bool go_right) {
    if (node == -1) return;

    dist[level][0] = min(dist[level][0], idx + nodes[tree[node][0]]);
    dist[level][1] = max(dist[level][1], idx - nodes[tree[node][1]]);

    if (go_right) {
        int now_right = idx;

        now_right += nodes[tree[node][0]];
        dist[level][1] = max(dist[level][1], now_right);

        solve(tree[node][1], level + 1, now_right + 1, true);
        solve(tree[node][0], level + 1, now_right - 1, false);

    }
    else {
        int now_left = idx;

        now_left -= nodes[tree[node][1]];
        dist[level][0] = min(dist[level][0], now_left);

        solve(tree[node][0], level + 1, now_left - 1, false);
        solve(tree[node][1], level + 1, now_left + 1, true);
    }


    if (ans == dist[level][1] - dist[level][0] + 1) {
        ans_level = min(ans_level, level);
    }
    else if (ans < dist[level][1] - dist[level][0] + 1) {
        ans = dist[level][1] - dist[level][0] + 1;
        ans_level = level;
    }
}

int get_node(int idx) {
    if (idx == -1) return 0;

    nodes[idx] = get_node(tree[idx][0]) + get_node(tree[idx][1]) + 1;

    return nodes[idx];
}

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][0] = b;
        tree[a][1] = c;

        dist[i][0] = INT_MAX;
        dist[i][1] = INT_MIN;
    }

    if (N == 1) {
        cout << 1 << ' ' << 1;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (nodes[i] != 0) continue;
        get_node(i);

        if (nodes[i] == N) {
            root = i;
            break;
        }
    }

    solve(tree[root][0], 2, -1, false);
    solve(tree[root][1], 2, 1, true);

    cout << ans_level << ' ' << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<pair<int, int>> graph[100001];
int depth[100001];
int ancestor[100001][20][3];

void make_tree(int now, int before, int shortest, int longest) {
    depth[now] = depth[before] + 1;
    ancestor[now][0][0] = before;
    ancestor[now][0][1] = shortest;
    ancestor[now][0][2] = longest;

    for (int i = 0; i < graph[now].size(); i++) {
        auto next = graph[now][i];

        if (next.second == before) continue;

        make_tree(next.second, now, next.first, next.first);
    }
}

pair<int, int> get_minmax(int a, int b) {
    int mini = INT_MAX;
    int maxi = 0;

    if (depth[a] > depth[b]) swap(a, b);

    for (int i = 19; i >= 0; i--) {
        if (depth[a] <= depth[ancestor[b][i][0]]) {
            mini = min(mini, ancestor[b][i][1]);
            maxi = max(maxi, ancestor[b][i][2]);
            b = ancestor[b][i][0];
        }
    }

    if (a != b) {
        for (int i = 19; i >= 0; i--) {
            if (ancestor[a][i][0] != ancestor[b][i][0]) {
                mini = min(mini, ancestor[a][i][1]);
                maxi = max(maxi, ancestor[a][i][2]);

                mini = min(mini, ancestor[b][i][1]);
                maxi = max(maxi, ancestor[b][i][2]);

                a = ancestor[a][i][0];
                b = ancestor[b][i][0];
            }
        }
        mini = min(mini, ancestor[a][0][1]);
        maxi = max(maxi, ancestor[a][0][2]);

        mini = min(mini, ancestor[b][0][1]);
        maxi = max(maxi, ancestor[b][0][2]);
    }

    return {mini, maxi};
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    make_tree(1, 0, INT_MAX, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= N; j++) {
            ancestor[j][i][0] = ancestor[ancestor[j][i - 1][0]][i - 1][0];
            ancestor[j][i][1] = min(ancestor[ancestor[j][i - 1][0]][i - 1][1], ancestor[j][i - 1][1]);
            ancestor[j][i][2] = max(ancestor[ancestor[j][i - 1][0]][i - 1][2], ancestor[j][i - 1][2]);
        }
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        auto ans = get_minmax(a, b);

        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
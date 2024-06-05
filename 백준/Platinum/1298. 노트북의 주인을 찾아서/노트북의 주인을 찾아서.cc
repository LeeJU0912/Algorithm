#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> save[101];
bool visited[101];
int node[5001];

bool solve(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;

    for (int i = 0; i < save[idx].size(); i++) {
        int now = save[idx][i];

        if (node[now] == 0 || solve(node[now])) {
            node[now] = idx;
            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        save[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        ans += solve(i);
    }

    cout << ans;

    return 0;
}
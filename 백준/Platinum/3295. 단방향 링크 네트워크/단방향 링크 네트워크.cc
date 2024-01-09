#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> graph[1001];
int matching[1001];
bool visited[1001];

int ans;

bool dfs(int A) {
    if (visited[A]) return false;
    visited[A] = true;

    for (int B : graph[A]) {
        if (matching[B] == -1 || dfs(matching[B])) {
            matching[B] = A;

            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        ans = 0;

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        memset(matching, -1, sizeof(matching));
        for (int i = 0; i < n; i++) {
            memset(visited, false, sizeof(visited));
            if (dfs(i)) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
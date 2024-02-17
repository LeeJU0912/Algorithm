#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, P;

int graph[401][401];
int visited[401];

bool dfs(int start, int end, int flow) {
    if (start == end) return true;
    visited[start] = flow;
    for (int i = 1; i <= N; i++) {
        if (graph[start][i] == 0 || visited[i] == flow) continue;
        if (dfs(i, end, flow)) {
            graph[start][i]--;
            graph[i][start]++;
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N >> P;

    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    int ans = 0;
    while(dfs(1, 2, ans + 1)) ans++;

    cout << ans;

    return 0;
}
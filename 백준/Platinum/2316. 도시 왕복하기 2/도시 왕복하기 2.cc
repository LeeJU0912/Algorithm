#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, P;

unordered_set<int> graph[801];
int visited[801];

bool dfs(int start, int end, int flow) {
    if (start == end) return true;
    visited[start] = flow;

    for (int next : graph[start]) {
        if (visited[next] == flow) continue;
        if (dfs(next, end, flow)) {
            graph[start].erase(next);
            graph[next].insert(start);
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N >> P;

    for (int i = 2; i <= N; i++) {
        graph[i + N].insert(i);
    }

    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b + N);
        graph[b].insert(a + N);
    }

    int ans = 0;
    while(dfs(1, 2 + N, ans + 1)) ans++;

    cout << ans;

    return 0;
}
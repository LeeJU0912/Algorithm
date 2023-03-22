#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[2001];
bool visited[2001];
int ans;

void dfs(int now, int counter) {
    if (ans) return;
    if (counter == 5) {
        ans = 1;
        return;
    }
    for (int i = 0; i < graph[now].size(); i++) {
        if (visited[graph[now][i]]) continue;
        visited[graph[now][i]] = true;
        dfs(graph[now][i], counter + 1);
        visited[graph[now][i]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (graph[i].empty()) continue;
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    cout << ans;

    return 0;
}
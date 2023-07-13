#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K, X;
vector<int> graph[300001];
int visited[300001];
vector<int> ans;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (visited[now] == K) {
            ans.push_back(now);
            continue;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next] != -1) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
}

int main() {
    FastIO

    memset(visited, -1, sizeof(visited));

    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    bfs(X);

    if (ans.empty()) {
        cout << -1;
    }
    else {
        sort(ans.begin(), ans.end());

        for (auto i : ans) {
            cout << i << '\n';
        }
    }

    return 0;
}
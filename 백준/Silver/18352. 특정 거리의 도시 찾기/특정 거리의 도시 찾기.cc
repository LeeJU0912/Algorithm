#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K, X;
vector<int> graph[300001];
bool visited[300001];
vector<int> ans;

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.second == K) {
            ans.push_back(now.first);
            continue;
        }

        for (int i = 0; i < graph[now.first].size(); i++) {
            int next = graph[now.first][i];

            if (visited[next]) continue;
            visited[next] = true;
            q.push({next, now.second + 1});
        }
    }
}

int main() {
    FastIO

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
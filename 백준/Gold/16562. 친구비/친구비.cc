#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, k;
int money[10001];

vector<int> graph[10001];
bool visited[10001];

int ans;

int solve(int start) {
    int mini = money[start];

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        mini = min(mini, money[now]);

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next]) continue;
            visited[next] = true;

            q.push(next);
        }
    }

    return mini;
}

int main() {
    FastIO

    cin >> N >> M >> k;

    for (int i = 1; i <= N; i++) {
        cin >> money[i];
    }

    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        ans += solve(i);
    }

    if (ans > k) {
        cout << "Oh no";
    }
    else {
        cout << ans;
    }

    return 0;
}
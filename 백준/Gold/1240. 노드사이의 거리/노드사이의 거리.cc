#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> graph[10001];

bool visited[10001];
int x, y;
int temp;

void solve(int now, int ans) {
    if (now == y) {
        temp = ans;
        return;
    }

    for (int i = 0; i < graph[now].size(); i++) {
        auto next = graph[now][i];
        if (visited[next.first]) continue;
        visited[next.first] = true;
        solve(next.first, ans + next.second);
    }
}

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    for (int i = 0; i < M; i++) {
        memset(visited, false, sizeof(visited));
        cin >> x >> y;

        visited[x] = true;
        solve(x, 0);

        cout << temp << '\n';
    }

    return 0;
}
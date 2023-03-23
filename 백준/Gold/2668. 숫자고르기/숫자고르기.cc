#include <bits/stdc++.h>
using namespace std;

int N;

bool visited[101];
vector<int> graph[101];

int ans;
set<int> ans_list;

void bfs(int now, int start) {
    if (visited[now] && now == start) {
        ans_list.insert(now);
        ans++;
        return;
    }

    if (visited[graph[now][0]]) return;
    visited[graph[now][0]] = true;
    bfs(graph[now][0], start);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        graph[i].push_back(temp);
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        bfs(i, i);
    }

    cout << ans << '\n';
    for (auto i : ans_list) {
        cout << i << '\n';
    }

    return 0;
}
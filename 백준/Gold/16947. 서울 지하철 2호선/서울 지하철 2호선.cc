#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> graph[3001];
bool is_cycle[3001];
int visited[3001];
int ans[3001];

bool find_cycle(int node, int before_node) {
    if (visited[node]) {
        is_cycle[node] = true;
        return true;
    }

    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];

        if (next_node == before_node) continue;

        if (find_cycle(next_node, node)) {
            if (is_cycle[node]) return false;

            is_cycle[node] = true;
            return true;
        }
    }

    return false;
}

void get_dist(int start) {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, start});

    while(!q.empty()) {
        int now_count = q.front().first;
        int now_node = q.front().second;
        q.pop();

        if (is_cycle[now_node]) {
            ans[start] = now_count;
            return;
        }

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_node = graph[now_node][i];

            if (visited[next_node]) continue;
            visited[next_node] = true;
            q.push({now_count + 1, next_node});
        }
    }
}

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    find_cycle(1, 0);

    for (int i = 1; i <= N; i++) {
        if (is_cycle[i]) {
            cout << 0 << ' ';
            continue;
        }

        memset(visited, 0, sizeof(visited));
        get_dist(i);

        cout << ans[i] << ' ';
    }

    return 0;
}
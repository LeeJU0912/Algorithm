#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<int> graph[20001];
int visited[20001];
bool err;

void solve(int start) {
    queue<pair<int, bool>> q;
    q.emplace(start, true);

    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now.second) visited[now.first] = 1;
        else visited[now.first] = 2;

        int next_visited = !now.second;

        for (int i = 0; i < graph[now.first].size(); i++) {
            int next = graph[now.first][i];
            if (visited[next]) {
                if (now.first != next && visited[next] == visited[now.first]) {
                    err = true;
                    break;
                }
                continue;
            }
            q.emplace(next, next_visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;

    while(K--) {
        err = false;
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= 20000; i++) {
            graph[i].clear();
        }

        cin >> V >> E;

        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (V == 1) {
            cout << "NO" << '\n';
            continue;
        }

        for (int i = 1; i <= V; i++) {
            if (err) break;
            if (graph[i].empty() || visited[i]) continue;
            solve(i);
        }

        if (err) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }

    }

    return 0;
}
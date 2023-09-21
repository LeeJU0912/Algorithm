#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<int> graph[501];
bool visited[501];

bool find_tree(int x) {
    queue<pair<int, int>> q;
    q.push({0, x});
    visited[x] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i];

            if (next == now.first) continue;
            if (visited[next]) return false;
            visited[next] = true;

            q.push({now.second, next});
        }
    }

    return true;
}

int main() {
    FastIO

    int T = 0;

    while(true) {
        T++;

        memset(visited, false, sizeof(visited));

        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        int trees = 0;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            if (find_tree(i)) {
                trees++;
            }
        }

        if (trees == 0) {
            cout << "Case " << T << ": No trees." << '\n';
        }
        else if (trees == 1) {
            cout << "Case " << T << ": There is one tree." << '\n';
        }
        else {
            cout << "Case " << T << ": A forest of " << trees << " trees." << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<pair<int, int>> graph[101];
bool canGo[101];
bool visited[101];
int dist[101];
int path[101];

void initDist(int val) {
    for (int i = 1; i <= n; i++) {
        dist[i] = val;
    }
}

void goCheck(int node) {
    if (node == n) {
        canGo[node] = true;
        return;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i].second;

        if (visited[nextNode]) {
            if (canGo[nextNode]) {
                canGo[node] = true;
            }
            continue;
        }
        visited[nextNode] = true;

        goCheck(nextNode);

        if (canGo[nextNode]) {
            canGo[node] = true;
        }
    }
}

bool minusCycleCheck() {
    initDist(1e9);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!canGo[j]) continue;
            for (int k = 0; k < graph[j].size(); k++) {
                int nextDist = graph[j][k].first;
                int nextNode = graph[j][k].second;

                if (!canGo[nextNode]) continue;

                if (dist[nextNode] > dist[j] + nextDist) {
                    dist[nextNode] = dist[j] + nextDist;
                    path[nextNode] = j;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (!canGo[j]) continue;
        for (int k = 0; k < graph[j].size(); k++) {
            int nextDist = graph[j][k].first;
            int nextNode = graph[j][k].second;

            if (!canGo[nextNode]) continue;

            if (dist[nextNode] > dist[j] + nextDist) {
                return true;
            }
        }
    }

    return false;
}

void trace() {
    stack<int> stk;

    int nowNode = n;

    while(nowNode != 0) {
        stk.push(nowNode);
        nowNode = path[nowNode];
    }

    if (stk.top() != 1) {
        cout << -1;
        return;
    }

    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({-w, v});
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        goCheck(1);
    }

    if (minusCycleCheck()) {
        cout << -1;
    }
    else {
        trace();
    }

    return 0;
}
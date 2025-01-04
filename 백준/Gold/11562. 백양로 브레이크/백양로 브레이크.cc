#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m, k;
vector<pair<bool, int>> graph[251];
int DP[251][251];

void calc(int start) {
    queue<pair<int, int>> q;
    q.push({0, start});
    DP[start][start] = 0;

    while(!q.empty()) {
        int nowCnt = q.front().first;
        int nowNode = q.front().second;
        q.pop();

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextNode = graph[nowNode][i].second;
            bool nextInfo = graph[nowNode][i].first;

            if (nextInfo) {
                if (DP[start][nextNode] <= nowCnt) continue;
                DP[start][nextNode] = nowCnt;
                q.push({nowCnt, nextNode});
            }
            else {
                int nextCnt = nowCnt + 1;
                if (DP[start][nextNode] <= nextCnt) continue;
                DP[start][nextNode] = nextCnt;
                q.push({nextCnt, nextNode});
            }

        }
    }
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        if (b) {
            graph[u].push_back({b, v});
            graph[v].push_back({b, u});
        }
        else {
            graph[u].push_back({!b, v});
            graph[v].push_back({b, u});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        calc(i);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;

        cout << DP[s][e] << '\n';
    }

    return 0;
}
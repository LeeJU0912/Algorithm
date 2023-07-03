#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> graph[200001];
vector<bool> visited(200001, false);

int main() {
    FastIO

    int m, n;
    while(true) {
        for (int i = 0; i <= 200000; i++) {
            graph[i].clear();
            visited[i] = false;
        }

        cin >> m >> n;

        if (m == 0 && n == 0) break;

        int hap = 0;

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            hap += c;
            graph[a].emplace_back(c, b);
            graph[b].emplace_back(c, a);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> start;

        int ans = 0;
        for (int i = 0; i < graph[0].size(); i++) {
            int next = graph[0][i].second;
            int next_length = graph[0][i].first;

            start.emplace(next_length, next);
        }
        visited[0] = true;

        while(!start.empty()) {
            auto now = start.top();
            start.pop();
            if (visited[now.second]) continue;
            ans += now.first;

            visited[now.second] = true;

            for (int i = 0; i < graph[now.second].size(); i++) {
                int next = graph[now.second][i].second;
                int next_length = graph[now.second][i].first;

                start.emplace(next_length, next);
            }
        }

        cout << hap - ans << '\n';
    }

    return 0;
}
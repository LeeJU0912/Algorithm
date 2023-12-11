#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<int> graph[10001];
int node_time[10001];
int max_time[10001];
int indegree[10001];

int ans;

void solve() {
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push({node_time[i], i});
            max_time[i] = node_time[i];
        }
    }

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        ans = max(ans, max_time[now.second]);

        for (int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i];


            max_time[next] = max(max_time[next], now.first + node_time[next]);

            indegree[next]--;
            if (indegree[next] == 0) {
                q.push({max_time[next], next});
            }
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int time, K;
        cin >> time >> K;

        for (int j = 0; j < K; j++) {
            int temp;
            cin >> temp;
            graph[temp].push_back(i);
        }

        node_time[i] = time;
        indegree[i] = K;
    }

    solve();

    cout << ans;

    return 0;
}
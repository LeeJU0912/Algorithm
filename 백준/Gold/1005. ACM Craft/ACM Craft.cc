#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
int const_time[1001];
int W;
int DP[1001];
int indegree[1001];
vector<int> graph[1001];
vector<int> start_q;

void solve() {
    queue<int> q;

    for (int i : start_q) {
        q.push(i);
        DP[i] = const_time[i];
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            DP[next] = max(DP[next], DP[now] + const_time[next]);

            indegree[next]--;


            if (indegree[next]) {
                continue;
            }
            else {
                q.push(next);
            }
        }
    }
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        cin >> N >> K;

        start_q.clear();
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }

        for (int i = 1; i <= N; i++) {
            cin >> const_time[i];
        }

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;

            graph[x].push_back(y);
            indegree[y]++;
        }

        cin >> W;

        for (int i = 1; i <= N; i++) {
            if (!indegree[i]) {
                start_q.push_back(i);
            }
        }

        solve();

        cout << DP[W] << '\n';
    }

    return 0;
}
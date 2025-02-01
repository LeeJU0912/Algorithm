#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K, M, P;

vector<int> graph[1001];
int indegree[1001];

int maxStrahler[1001];
int cnt[1001];
int nodeStrahler[1001];

vector<int> start;

void solve() {
    queue<int> q;

    for (int node : start) {
        nodeStrahler[node] = 1;
        q.push(node);
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (cnt[now] == 1) {
            nodeStrahler[now] = maxStrahler[now];
        }
        else if (cnt[now] >= 2) {
            nodeStrahler[now] = maxStrahler[now] + 1;
        }

        for (int next : graph[now]) {
            indegree[next]--;

            if (maxStrahler[next] == nodeStrahler[now]) {
                cnt[next]++;
            }
            else if (maxStrahler[next] < nodeStrahler[now]) {
                maxStrahler[next] = nodeStrahler[now];
                cnt[next] = 1;
            }

            if (indegree[next] == 0) {
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
        memset(indegree, 0, sizeof(indegree));
        memset(maxStrahler, 0, sizeof(maxStrahler));
        memset(cnt, 0, sizeof(cnt));
        start.clear();

        cin >> K >> M >> P;
        for (int i = 1; i <= M; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < P; i++) {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            indegree[B]++;
        }

        for (int i = 1; i <= M; i++) {
            if (indegree[i] == 0) {
                start.push_back(i);
            }
        }

        solve();

        cout << K << ' ' << nodeStrahler[M] << '\n';
    }

    return 0;
}
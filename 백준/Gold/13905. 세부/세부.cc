#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int s, e;
vector<pair<int, int>> graph[100001];
bool visited[100001];

bool solve(int limit) {
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int nowNode = q.front();
        q.pop();

        if (nowNode == e) {
            return true;
        }

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextNode = graph[nowNode][i].second;
            int nextDist = graph[nowNode][i].first;

            if (limit > nextDist) continue;
            if (visited[nextNode]) continue;
            visited[nextNode] = true;
            q.push(nextNode);
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> N >> M;
    cin >> s >> e;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int start = 1;
    int end = 1000000;
    int ans = 0;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (solve(mid)) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, M;
vector<int> graph[101001];
int visited[101001];
int ans = INT_MAX;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1] = true;

    while(!q.empty()) {
        int nowCnt = q.front().first;
        int nowNode = q.front().second;
        q.pop();

        if (nowNode == N) {
            ans = nowCnt;
            return;
        }

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextNode = graph[nowNode][i];

            if (visited[nextNode]) continue;
            visited[nextNode] = true;
            if (nextNode > 100000) {
                q.push({nowCnt + 1, nextNode});
            }
            else {
                q.push({nowCnt, nextNode});
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            graph[100000 + i].push_back(x);
            graph[x].push_back(100000 + i);
        }
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    bfs();

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
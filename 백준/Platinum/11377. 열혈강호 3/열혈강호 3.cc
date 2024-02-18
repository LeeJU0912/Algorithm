#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

unordered_map<int, int> graph[2003];
int visited[2003];

bool dfs(int start, int end, int flow) {
    if (start == end) return true;
    visited[start] = flow;

    for (auto next : graph[start]) {
        if (graph[start][next.first] == 0 || visited[next.first] == flow) continue;
        if (dfs(next.first, end, flow)) {
            graph[start][next.first]--;
            graph[next.first][start]++;
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N >> M >> K;

    graph[0][2002] = K;

    for (int i = 1; i <= N; i++) {
        graph[0][i] = 1;
        graph[2002][i] = 1;

        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int temp;
            cin >> temp;

            graph[i][N + temp] = 1;
            graph[N + temp][N + M + 1] = 1;
        }
    }
    
    int ans = 0;
    while(dfs(0, N + M + 1, ans + 1)) ans++;

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, D;

int graph[302][302];
int visited[302];

bool dfs(int start, int end, int plate) {
    if (start == end) return true;
    visited[start] = plate;
    for (int i = 0; i <= 301; i++) {
        if (graph[start][i] == 0 || visited[i] == plate) continue;
        if (dfs(i, end, plate)) {
            graph[start][i]--;
            graph[i][start]++;
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N >> K >> D;

    for (int i = 1; i <= N; i++) {
        graph[0][i] = K;
    }

    for (int i = 1; i <= D; i++) {
        int temp;
        cin >> temp;
        graph[N + i][N + D + 1] = temp;
    }

    for (int i = 1; i <= N; i++) {
        int Z;
        cin >> Z;

        for (int j = 0; j < Z; j++) {
            int temp;
            cin >> temp;
            graph[i][N + temp] = 1;
        }
    }

    int ans = 0;
    while(dfs(0, N + D + 1, ans + 1)) ans++;

    cout << ans;

    return 0;
}
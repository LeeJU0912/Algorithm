#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int V, E;
int graph[401][401];


int main() {
    FastIO

    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            graph[i][j] = 1e9;
        }
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                if (graph[j][k] > graph[j][i] + graph[i][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            if (graph[i][j] == 1e9 || graph[j][i] == 1e9) continue;
            ans = min(ans, graph[i][j] + graph[j][i]);
        }
    }

    if (ans == 1e9) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    
    return 0;
}
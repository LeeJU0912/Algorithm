#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int dist[101][101];

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int x, y, ans = INT_MAX;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int temp = 0;
            for (int k = 1; k <= N; k++) {
                if (i == k || j == k) continue;
                temp += min(dist[k][i], dist[k][j]);
            }

            if (temp < ans) {
                x = i;
                y = j;
                ans = temp;
            }
        }
    }

    cout << x << ' ' << y << ' ' << ans * 2;

    return 0;
}
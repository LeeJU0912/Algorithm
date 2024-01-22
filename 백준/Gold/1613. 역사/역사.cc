#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, k;

int dist[401][401];

int main() {
    FastIO

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int x = 1; x <= n; x++) {
        for (int i= 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
            }
        }
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] == 1e9) {
            if (dist[b][a] == 1e9) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
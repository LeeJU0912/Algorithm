#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int dist1[100][100];
int dist2[100][100];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            dist1[i][j] = 1e9;
            dist2[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        dist1[b][a] = 1;
        dist2[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
            }
        }
    }

    int ans = 0;

    int mid = (N + 1) / 2;

    for (int i = 1; i <= N; i++) {
        int temp1 = 0;
        int temp2 = 0;

        for (int j = 1; j <= N; j++) {
            if (dist1[i][j] > 0 && dist1[i][j] < 1e9) temp1++;
            if (dist2[i][j] > 0 && dist2[i][j] < 1e9) temp2++;
        }

        if (max(temp1, temp2) >= mid) ans++;
    }

    cout << ans;

    return 0;
}
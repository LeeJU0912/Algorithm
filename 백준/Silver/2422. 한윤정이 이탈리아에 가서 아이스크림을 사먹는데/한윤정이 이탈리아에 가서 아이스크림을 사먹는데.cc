#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    int cannot[201][201];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cannot[a][b] = 1;
        cannot[b][a] = 1;
    }

    int ans = 0;

    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (cannot[i][j] || cannot[i][k] || cannot[j][k]) continue;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}

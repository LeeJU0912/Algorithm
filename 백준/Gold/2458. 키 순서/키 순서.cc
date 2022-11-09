#include <bits/stdc++.h>
using namespace std;

int N, M;
int length[501][501];
int counting[501];
int ans;

void floyd() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                length[j][k] = min(length[j][k], (length[j][i] + length[i][k]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;



    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            length[i][j] = 100000000;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        length[a][b] = 1;
    }

    floyd();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (length[i][j] != 100000000) {
                counting[i]++;
                counting[j]++;

                if (counting[i] == N - 1) ans++;
                if (counting[j] == N - 1) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int chk[101][101];
int DP[101][101];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        chk[a][b] = 1;
        chk[b][a] = 1;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = j; k < i; k++) {
                DP[j][i] = max(DP[j][i], DP[j][k] + DP[k][i] + chk[j][i]);
            }
        }
    }

    cout << DP[1][100];

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int damage[21];
int happy[21];
int DP[21][100];

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> damage[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> happy[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 99; j++) {
            if (j - damage[i] >= 0) {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - damage[i]] + happy[i]);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << DP[N][99];

    return 0;
}
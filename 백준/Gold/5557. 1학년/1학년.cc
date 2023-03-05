#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[100];
long long DP[100][21];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    DP[0][save[0]] = 1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (DP[i - 1][j]) {
                for (int k = -1; k <= 1; k += 2) {
                    long long next = j + k * save[i];
                    if (next < 0 || next > 20) continue;
                    DP[i][next] += DP[i - 1][j];
                }
            }
        }
    }

    cout << DP[N - 2][save[N - 1]];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int A[2001];
int B[2001];
int DP[2001][2001];

int main() {
    FastIO

    cin >> N;
    for (int i = N; i >= 1; i--) {
        cin >> A[i];
    }
    for (int i = N; i >= 1; i--) {
        cin >> B[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]);
            if (A[i] > B[j]) DP[i][j] = max(DP[i][j], DP[i][j - 1] + B[j]);
        }
    }

    cout << DP[N][N];

    return 0;
}
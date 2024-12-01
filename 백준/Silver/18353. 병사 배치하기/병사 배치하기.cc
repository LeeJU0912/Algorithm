#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[2001];
int DP[2001];

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP[i], 1);
        for (int j = i + 1; j <= N; j++) {
            if (save[i] > save[j]) {
                DP[j] = max(DP[j], DP[i] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, DP[i]);
    }

    cout << N - ans;

    return 0;
}
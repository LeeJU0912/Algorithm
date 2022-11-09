#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans[201][201];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        ans[i][1] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (i + j > N) break;
                ans[i + j][k] = (ans[i][k - 1] + ans[i + j][k]) % 1000000000;
            }
        }
    }

    cout << ans[N][K];

    return 0;
}
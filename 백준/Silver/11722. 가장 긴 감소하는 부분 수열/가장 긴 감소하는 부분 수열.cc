#include <bits/stdc++.h>
using namespace std;

int N;
int num[1001];
int DP[1001];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    for (int i = 1; i <= N; i++) {
        DP[i] = 1;
        for (int j = 1; j < i; j++) {
            if (num[j] > num[i] && DP[i] < DP[j] + 1) {
                DP[i] = DP[j] + 1;
            }
        }
        ans = max(ans, DP[i]);
    }

    cout << ans;

    return 0;
}
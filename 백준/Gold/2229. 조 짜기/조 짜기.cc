#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[1001];
int DP[1001];

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    for (int i = 2; i <= N; i++) {
        int mini = save[i];
        int maxi = save[i];

        for (int j = i - 1; j >= 0; j--) {
            maxi = max(maxi, save[j + 1]);
            mini = min(mini, save[j + 1]);

            DP[i] = max(DP[i], DP[j] + maxi - mini);
        }
    }

    cout << DP[N];
    
    return 0;
}
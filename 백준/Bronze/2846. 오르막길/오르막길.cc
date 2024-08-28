#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    int ans = 0;
    int mini = INT_MAX;
    int maxi = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x > mini) {
            if (x <= maxi) {
                mini = x;
                maxi = x;
            }
            else {
                maxi = x;
                ans = max(ans, x - mini);
            }
        }
        else {
            mini = x;
            maxi = x;
        }
    }

    cout << ans;

    return 0;
}
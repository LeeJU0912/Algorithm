#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = INT_MAX;

    for (int i = 0; i * 5 <= N; i++) {
        if ((N - (i * 5)) % 3 == 0) {
            ans = min(ans, i + (N - (i * 5)) / 3);
        }
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
        
    return 0;
}

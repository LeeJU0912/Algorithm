#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int ans = 0;

        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            ans += temp;
        }

        cout << ans << '\n';
    }

    return 0;
}
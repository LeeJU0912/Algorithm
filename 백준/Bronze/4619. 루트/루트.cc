#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int B, N;


    while(true) {
        cin >> B >> N;
        if (B == 0 && N == 0) break;

        int ans = 1;

        while(true) {
            if (pow(ans, N) > B) break;
            ans++;
        }
        if (abs(B - pow(ans, N)) > abs(B - pow(ans - 1, N))) {
            cout << ans - 1 << '\n';
        }
        else {
            cout << ans << '\n';
        }

    }

    return 0;
}
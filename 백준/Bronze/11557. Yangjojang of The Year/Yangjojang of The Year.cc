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

        int cur = -1;
        string ans;
        for (int i = 0; i < N; i++) {
            string a;
            int b;

            cin >> a >> b;

            if (b > cur) {
                ans = a;
                cur = b;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
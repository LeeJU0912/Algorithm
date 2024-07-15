#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int ans = 0;

        for (int i = 0; i < 9; i++) {
            int Y, K;
            cin >> Y >> K;

            ans += (Y - K);
        }

        if (ans > 0) {
            cout << "Yonsei" << '\n';
        }
        else if (ans < 0) {
            cout << "Korea" << '\n';
        }
        else {
            cout << "Draw" << '\n';
        }
    }

    return 0;
}
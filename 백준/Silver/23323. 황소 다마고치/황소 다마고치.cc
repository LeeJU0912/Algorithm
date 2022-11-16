#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        long long n, m;
        int ans = 0;
        int zero = 0;
        cin >> n >> m;



        cout << m + 1 + (int)floor(log2(n)) << '\n';


//        while (n != 0) {
//            if (n & 1) {
//                ans++;
//            }
//            else {
//                zero++;
//            }
//            n = n >> 1;
//        }
//
//        cout << m + ans << '\n';


    }

    return 0;
}
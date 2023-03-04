#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b;
    cin >> a >> b;

    int ans1 = 0;
    int ans2 = INT_MAX;

    int lcmgcd = b / a; // lcm = x * gcd + y * gcd -> (x, y)를 구해야 한다.

    for (int i = 1; i <= sqrt(lcmgcd); i++) { // lcmgcd 약수 구하기
        if (lcmgcd % i == 0) {
            if (gcd(i, lcmgcd / i) == 1) {
                ans1 = i * a;
                ans2 = lcmgcd / i * a;
            }
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
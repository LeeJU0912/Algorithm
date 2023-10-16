#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

unsigned long long n;

int main() {
    FastIO

    cin >> n;

    unsigned long long start = 0;
    unsigned long long end = 3037000500;

    unsigned long long ans = LLONG_MAX;
    while(start <= end) {
        unsigned long long mid = (start + end) / 2;

        if (mid * mid > n) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else if (mid * mid == n) {
            ans = mid;
            break;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
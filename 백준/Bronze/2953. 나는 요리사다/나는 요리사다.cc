#include <bits/stdc++.h>

using namespace std;

int L, P;
int ans;
int ans_sum;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    for (int i = 1; i <= 5; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = 0;
        sum += a;
        sum += b;
        sum += c;
        sum += d;

        if (ans_sum < sum) {
            ans_sum = sum;
            ans = i;
        }
    }

    cout << ans << ' ' << ans_sum;

    return 0;
}
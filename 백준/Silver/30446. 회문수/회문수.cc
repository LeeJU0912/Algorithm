#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long n;
int ans;

bool make_ans(int now, int plus) {
    long long calc = now;
    calc *= 10;
    calc += plus;

    int temp = now;

    while(temp) {
        calc *= 10;
        calc += temp % 10;
        temp /= 10;
    }

    if (calc <= n) return true;
    else return false;
}

void solve(int now, int count) {
    if (count == 5) return;

    long long calc = now;

    int temp = now;
    while(temp) {
        calc *= 10;
        calc += temp % 10;
        temp /= 10;
    }

    if (calc <= n) ans++;
    else return;

    for (int i = 0; i <= 9; i++) {
        if (make_ans(now, i)) {
            ans++;
            solve(now * 10 + i, count + 1);
        }
    }
}

int main() {
    FastIO

    cin >> n;

    if (n <= 9) {
        cout << n;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        solve(i, 0);
    }

    cout << ans + 9;

    return 0;
}
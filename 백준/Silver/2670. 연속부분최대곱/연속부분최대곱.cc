#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    double ans = 0;
    double ans2 = 0;
    for (int i = 0; i < N; i++) {
        double temp;
        cin >> temp;
        if (temp > ans * temp) {
            ans = temp;
        }
        else {
            ans = ans * temp;
        }
        ans2 = max(ans, ans2);
    }

    cout << fixed << setprecision(3) << ans2;

    return 0;
}
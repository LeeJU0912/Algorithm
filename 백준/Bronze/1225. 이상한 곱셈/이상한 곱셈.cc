#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long ans = 0;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans += (a[i] - '0') * (b[j] - '0');
        }
    }

    cout << ans;

    return 0;
}
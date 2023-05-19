#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    vector<int> save(n);
    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }

    int div = save[0];
    for (int i = 1; i < n; i++) {
        div = gcd(div, save[i]);
    }

    for (int i = 1; i <= div; i++) {
        if (div % i == 0) {
            cout << i << '\n';
        }
    }

    return 0;
}
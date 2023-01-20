#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int hap[] = {0, 0};

    for (int i = 0; i < 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        hap[i] = a + b + c + d;
    }

    cout << max(hap[0], hap[1]);

    return 0;
}
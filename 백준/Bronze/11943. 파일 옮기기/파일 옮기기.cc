#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << min(a + d, b + c);

    return 0;
}
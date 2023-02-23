#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b, c;
    while(cin >> a >> b >> c) {
        cout << max(c - b, b - a) - 1 << '\n';
    }
    

    return 0;
}
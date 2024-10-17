#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int S, T, D;
    cin >> S >> T >> D;

    cout << T * (D / (S * 2));

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B, C;
    cin >> A >> B >> C;

    cout << max((B - A - 1), (C - B - 1));

    return 0;
}
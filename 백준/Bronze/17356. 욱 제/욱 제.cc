#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    double A, B;
    cin >> A >> B;
    cout << 1 / (1 + pow(10, (B - A) / 400));

    return 0;
}
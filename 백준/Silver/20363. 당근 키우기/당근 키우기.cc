#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int X, Y;

int main() {
    FastIO

    cin >> X >> Y;

    if (X < Y) swap(X, Y);

    X += Y / 10;

    cout << X + Y;

    return 0;
}
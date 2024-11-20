#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int H, I, A, R, C;
    cin >> H >> I >> A >> R >> C;
    cout << H * I - A * R * C;

    return 0;
}
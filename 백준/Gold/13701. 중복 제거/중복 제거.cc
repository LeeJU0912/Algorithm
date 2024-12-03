#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bitset<33554432> chk;

int main() {
    FastIO

    int A;
    while(cin >> A) {
        if (chk[A]) continue;
        chk.set(A, true);
        cout << A << ' ';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int x, y;
    if (A % C == 0) {
        x = A / C;
    }
    else {
        x = A / C + 1;
    }
    if (B % D == 0) {
        y = B / D;
    }
    else {
        y = B / D + 1;
    }

    cout << L - max(x, y);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int DP[102][102][102];

int w(int a, int b, int c) {
    if (DP[a + 51][b + 51][c + 51]) return DP[a + 51][b + 51][c + 51];
    if (a <= 0 || b <= 0 || c <= 0) {
        DP[a + 51][b + 51][c + 51] = 1;
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        DP[71][71][71] = w(20, 20, 20);
        return DP[71][71][71];
    }
    if (a < b && b < c) {
        DP[a + 51][b + 51][c + 50] = w(a, b, c - 1);
        DP[a + 51][b + 50][c + 50] = w(a, b - 1, c - 1);
        DP[a + 51][b + 50][c + 51] = w(a, b - 1, c);
        return DP[a + 51][b + 51][c + 50] + DP[a + 51][b + 50][c + 50] - DP[a + 51][b + 50][c + 51];
    }
    else {
        DP[a + 50][b + 51][c + 51] = w(a - 1, b, c);
        DP[a + 50][b + 50][c + 51] = w(a - 1, b - 1, c);
        DP[a + 50][b + 51][c + 50] = w(a - 1, b, c - 1);
        DP[a + 50][b + 50][c + 50] = w(a - 1, b - 1, c - 1);
        return DP[a + 50][b + 51][c + 51] + DP[a + 50][b + 50][c + 51] + DP[a + 50][b + 51][c + 50] - DP[a + 50][b + 50][c + 50];
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a = 0;
    int b = 0;
    int c = 0;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';

    }

    return 0;
}
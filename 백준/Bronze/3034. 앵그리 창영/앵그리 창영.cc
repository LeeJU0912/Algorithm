#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, W, H;

int main() {
    FastIO

    cin >> N >> W >> H;

    double size = pow(W, 2) + pow(H, 2);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x * x <= size) {
            cout << "DA" << '\n';
        }
        else {
            cout << "NE" << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int D, H, W;

int main() {
    FastIO

    cin >> D >> H >> W;

    double D2 = D * D;
    double H2 = H * H;
    double W2 = W * W;

    double one = D2 / (H2 + W2);

    cout << (int)(H * sqrt(one)) << ' ' << (int)(W * sqrt(one));

    return 0;
}
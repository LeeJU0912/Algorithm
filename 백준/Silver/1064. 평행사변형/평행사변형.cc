#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

double xa, ya, xb, yb, xc, yc;

vector<double> length;

int main() {
    FastIO

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    if ((ya - yb) / (xa - xb) == (yc - yb) / (xc - xb)) {
        cout << -1;
        return 0;
    }

    length.push_back(sqrt(pow(xa - xb, 2) + pow(ya - yb, 2)));
    length.push_back(sqrt(pow(xa - xc, 2) + pow(ya - yc, 2)));
    length.push_back(sqrt(pow(xb - xc, 2) + pow(yb - yc, 2)));

    sort(length.begin(), length.end());

    cout << fixed;
    cout.precision(9);
    cout << 2 * (length[2] + length[1]) - 2 * (length[0] + length[1]);

    return 0;
}
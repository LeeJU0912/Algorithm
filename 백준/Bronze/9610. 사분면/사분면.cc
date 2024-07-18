#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int Q1, Q2, Q3, Q4, axis;

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0 || b == 0) axis++;
        else if (a > 0 && b > 0) Q1++;
        else if (a < 0 && b > 0) Q2++;
        else if (a < 0 && b < 0) Q3++;
        else if (a > 0 && b < 0) Q4++;
    }

    cout << "Q1: " << Q1 << '\n';
    cout << "Q2: " << Q2 << '\n';
    cout << "Q3: " << Q3 << '\n';
    cout << "Q4: " << Q4 << '\n';
    cout << "AXIS: " << axis;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

double S[2];
double N[2];
double U[2];

int main() {
    FastIO

    cin >> S[0] >> S[1];
    cin >> N[0] >> N[1];
    cin >> U[0] >> U[1];

    double x, y, z;
    if (S[0] * 10 >= 5000) {
        x = S[0] * 10 - 500;
    }
    else {
        x = S[0] * 10;
    }
    if (N[0] * 10 >= 5000) {
        y = N[0] * 10 - 500;
    }
    else {
        y = N[0] * 10;
    }
    if (U[0] * 10 >= 5000) {
        z = U[0] * 10 - 500;
    }
    else {
        z = U[0] * 10;
    }

    double one = S[1] / x;
    double two = N[1] / y;
    double three = U[1] / z;

    if (one > two && one > three) {
        cout << 'S';
    }
    else if (two > one && two > three) {
        cout << 'N';
    }
    else if (three > one && three > two) {
        cout << 'U';
    }

    return 0;
}
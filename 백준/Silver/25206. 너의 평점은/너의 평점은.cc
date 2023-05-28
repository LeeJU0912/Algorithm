#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    double gop_hap = 0;
    int hap = 0;

    for (int i = 0; i < 20; i++) {
        string save[3];
        for (int j = 0; j < 3; j++) {
            cin >> save[j];
        }

        if (save[2] == "P") continue;

        int now = save[1][0] - '0';
        hap += now;

        if (save[2] == "A+") {
            gop_hap += now * 4.5;
        }
        else if (save[2] == "A0") {
            gop_hap += now * 4.0;
        }
        else if (save[2] == "B+") {
            gop_hap += now * 3.5;
        }
        else if (save[2] == "B0") {
            gop_hap += now * 3.0;
        }
        else if (save[2] == "C+") {
            gop_hap += now * 2.5;
        }
        else if (save[2] == "C0") {
            gop_hap += now * 2.0;
        }
        else if (save[2] == "D+") {
            gop_hap += now * 1.5;
        }
        else if (save[2] == "D0") {
            gop_hap += now * 1.0;
        }
        else if (save[2] == "F") {
            gop_hap += now * 0.0;
        }
    }

    cout << fixed;
    cout.precision(6);

    cout << gop_hap / hap;

    return 0;
}
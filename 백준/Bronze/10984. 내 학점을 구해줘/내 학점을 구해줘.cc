#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T;

int main() {
    FastIO

    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int point = 0;
        double hap = 0;
        for (int i = 0; i < N; i++) {
            int a;
            double b;
            cin >> a >> b;
            point += a;
            hap += b * a;
        }

        cout << fixed;
        cout.precision(1);
        cout << point << ' ' << hap / point << '\n';
    }


    return 0;
}
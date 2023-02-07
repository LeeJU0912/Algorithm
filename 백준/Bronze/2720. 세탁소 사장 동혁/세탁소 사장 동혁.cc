#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int C;
        cin >> C;

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;

        while(C >= 25) {
            a++;
            C -= 25;
        }
        while(C >= 10) {
            b++;
            C -= 10;
        }
        while(C >= 5) {
            c++;
            C -= 5;
        }
        while(C >= 1) {
            d++;
            C -= 1;
        }

        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }


    return 0;
}
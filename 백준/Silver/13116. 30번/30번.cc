#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int a, b;
        cin >> a >> b;

        while(a != b) {
            if (a > b) {
                a /= 2;
            }
            else {
                b /= 2;
            }
        }

        cout << a * 10 << '\n';
    }

    return 0;
}
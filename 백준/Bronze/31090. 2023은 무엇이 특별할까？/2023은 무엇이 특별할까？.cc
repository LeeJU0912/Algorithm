#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        int div = n % 100;

        cout << ((n + 1) % div ? "Bye" : "Good") << '\n';
    }

    return 0;
}
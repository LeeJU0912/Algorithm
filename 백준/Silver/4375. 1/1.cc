#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    while(cin >> N) {
        long long save = 1;
        int ans = 1;
        while(save % N != 0) {
            ans++;
            save *= 10;
            save++;
            save %= N;
        }
        cout << ans << '\n';
    }


    return 0;
}
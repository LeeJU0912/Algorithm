#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int save[8] = {0, 0, 1, 7, 4, 2, 0, 8};
long long DP[101];

int main() {
    FastIO

    for (int i = 0; i <= 100; i++) {
        DP[i] = 1e15;
    }

    DP[2] = 1;
    DP[3] = 7;
    DP[4] = 4;
    DP[5] = 2;
    DP[6] = 6;
    DP[7] = 8;

    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            DP[i] = min(DP[i], DP[i - j] * 10 + save[j]);
        }
    }

    int T;
    cin >> T;
    while(T--) {
        string maxi;
        cin >> n;

        int calc = n;
        if (calc % 2) {
            maxi += '7';
            calc -= 3;
        }
        while(calc) {
            maxi += '1';
            calc -= 2;
        }

        cout << DP[n] << ' ' << maxi << '\n';
    }

    return 0;
}
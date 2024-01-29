#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[1000001];

int main() {
    FastIO

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            DP[j] += i;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        DP[i] += DP[i - 1];
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        cout << DP[N] << '\n';
    }

    return 0;
}
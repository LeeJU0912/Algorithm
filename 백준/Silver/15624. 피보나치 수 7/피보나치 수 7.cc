#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[1000001];

int main(){
    FastIO

    int n;
    cin >> n;

    DP[1] = 1;

    for (int i = 2; i <= n; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;
    }

    cout << DP[n];

    return 0;
}
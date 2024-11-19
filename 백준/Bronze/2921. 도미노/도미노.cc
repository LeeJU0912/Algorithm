#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            ans += i + j;
        }
    }
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 0;

    for (int i = 1; i < N; i++) {
        for (int j = i + 2; i + j < N; j++) {
            if ((N - i - j) % 2 == 0) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
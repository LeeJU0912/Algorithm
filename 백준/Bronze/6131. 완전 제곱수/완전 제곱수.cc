#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= 499; i++) {
        for (int j = i; j <= 500; j++) {
            if (i * i + N == j * j) {
                ans++;
                break;
            }
            else if (i * i + N < j * j) {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
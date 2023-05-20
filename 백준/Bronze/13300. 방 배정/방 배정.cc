#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;

int female[6];
int male[6];

int ans;

int main() {
    FastIO

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (a) {
            male[b - 1]++;
        }
        else {
            female[b - 1]++;
        }
    }

    for (int j = 0; j < 6; j++) {
        if (male[j] % K) {
            ans += male[j] / K + 1;
        }
        else {
            ans += male[j] / K;
        }

        if (female[j] % K) {
            ans += female[j] / K + 1;
        }
        else {
            ans += female[j] / K;
        }
    }

    cout << ans;

    return 0;
}
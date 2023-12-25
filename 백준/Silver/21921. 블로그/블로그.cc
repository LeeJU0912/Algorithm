#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int save[250001];
int hap[250001];

int ans;
int ans2;

int main() {
    FastIO

    int N, X;
    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    for (int i = 1; i <= N; i++) {
        hap[i] = hap[i - 1] + save[i];
    }

    for (int i = X; i <= N; i++) {
        int now = hap[i] - hap[i - X];

        if (now > ans) {
            ans = now;
            ans2 = 1;
        }
        else if (now == ans) {
            ans2++;
        }
    }

    if (ans == 0) {
        cout << "SAD";
    }
    else {
        cout << ans << '\n' << ans2;
    }

    return 0;
}
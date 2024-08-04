#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool chk[101];
int ans;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (chk[tmp]) ans++;
        else chk[tmp] = true;
    }

    cout << ans;

    return 0;
}
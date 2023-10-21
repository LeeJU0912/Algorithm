#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool chk[1000001];
vector<int> sosu;

int main() {
    FastIO

    for (int i = 2; i * i <= 1000000; i++) {
        if (chk[i]) continue;
        for (int j = 2; i * j <= 1000000; j++) {
            chk[i * j] = true;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (!chk[i]) sosu.push_back(i);
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int ans = 0;

        for (int i = 0; i < sosu.size(); i++) {
            if (sosu[i] > N / 2) break;

            if (!chk[N - sosu[i]]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
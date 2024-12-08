#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<long long> save;
long long cluster;

long long ans;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        save.push_back(X);
    }

    cin >> cluster;

    for (int i = 0; i < N; i++) {
        if (save[i] == 0) continue;
        if (save[i] % cluster) {
            ans += cluster * (save[i] / cluster + 1);
        }
        else {
            ans += cluster * (save[i] / cluster);
        }
    }

    cout << ans;

    return 0;
}
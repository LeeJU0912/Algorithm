#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N, K;
vector<long long> save;
long long hap[200001];

map<long long, long long> mp;

long long ans;

int main() {
    FastIO

    cin >> N >> K;
    save = vector<long long>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
        hap[i + 1] = hap[i] + save[i];
    }

    for (int i = 1; i <= N; i++) {
        if (hap[i] == K) ans++;
        ans += mp[hap[i] - K];
        mp[hap[i]]++;
    }

    cout << ans;

    return 0;
}
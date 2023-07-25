#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<long long> save[4];
vector<long long> mp[2];

long long ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        save[0].push_back(a);
        save[1].push_back(b);
        save[2].push_back(c);
        save[3].push_back(d);
    }

    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            mp[0].push_back(save[0][k] + save[1][l]);
            mp[1].push_back(save[2][k] + save[3][l]);
        }
    }

    sort(mp[1].begin(), mp[1].end());

    for (auto& j : mp[0]) {
        ans += upper_bound(mp[1].begin(), mp[1].end(), -j) - lower_bound(mp[1].begin(), mp[1].end(), -j);
    }

    cout << ans;

    return 0;
}
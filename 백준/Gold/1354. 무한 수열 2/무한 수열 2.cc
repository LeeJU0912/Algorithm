#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N;
int P, Q, X, Y;

unordered_map<long long, long long> mp;

long long solve(long long now) {
    if (mp[now]) {
        return mp[now];
    }

    if (now <= 0) {
        return 1;
    }
    else {
        mp[now] = solve(now / P - X) + solve(now / Q - Y);
        return mp[now];
    }
}

int main() {
    FastIO

    cin >> N >> P >> Q >> X >> Y;

    cout << solve(N);

    return 0;
}
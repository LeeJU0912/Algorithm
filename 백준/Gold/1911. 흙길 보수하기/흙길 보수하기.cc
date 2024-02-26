#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L;

vector<pair<int, int>> pool;

int ans = 0;
int last = 0;

void exclude_last(int i) {
    if ((pool[i].second - pool[i].first + 1) % L) {
        ans += (pool[i].second - pool[i].first + 1) / L + 1;
        last = (pool[i].first - 1) + ((pool[i].second - pool[i].first + 1) / L + 1) * L;
    }
    else {
        ans += (pool[i].second - pool[i].first + 1) / L;
    }
}

void include_last(int i) {
    if ((pool[i].second - last) % L) {
        ans += (pool[i].second - last) / L + 1;
        last += ((pool[i].second - last) / L + 1) * L;
    }
    else {
        ans += (pool[i].second - last) / L;
        last = 0;
    }
}

int main() {
    FastIO

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        pool.push_back({a, b - 1});
    }

    sort(pool.begin(), pool.end());

    for (int i = 0; i < N; i++) {
        if (pool[i].second <= last) {
            continue;
        }
        if (last) {
            if (pool[i].first > last) exclude_last(i);
            else include_last(i);
        }
        else {
            exclude_last(i);
        }
        //cout << i << ' ' << last << '\n';
    }

    cout << ans;

    return 0;
}
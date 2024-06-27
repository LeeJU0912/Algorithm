#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<pair<long long, long long>, long long>> save;

int ans;

long long solve(long long target) {
    long long hap = 0;

    for (int i = 0; i < N; i++) {
        if (target < save[i].first.first) continue;

        long long tmp = min(target, save[i].first.second) - save[i].first.first;
        hap += tmp / save[i].second + 1;
    }

    return hap;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        long long from, to, plus;
        cin >> from >> to >> plus;
        save.push_back({{from, to}, plus});
    }

    long long start = 1;
    long long end = INT_MAX;

    while(start <= end) {
        long long mid = (start + end) / 2;

        if (solve(mid) % 2) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    if (ans == 0) {
        cout << "NOTHING";
    }
    else {
        cout << ans << ' ' << solve(ans) - solve(ans - 1);
    }

    return 0;
}
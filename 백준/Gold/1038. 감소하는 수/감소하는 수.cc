#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<long long> DP;

int len;

void solve(int now_len, long long now, int now_last) {
    if (now_len > len) {
        DP.push_back(now);
        return;
    }

    int temp = now_last;
    for (int i = 0; i < temp; i++) {
        long long temp2 = now * 10 + i;
        now_last = i;
        solve(now_len + 1, temp2, now_last);
    }
}

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 1; i <= 10; i++) {
        len = i;
        solve(1, 0, 10);
    }

    if (N >= DP.size()) {
        cout << -1;
    }
    else {
        cout << DP[N];
    }

    return 0;
}
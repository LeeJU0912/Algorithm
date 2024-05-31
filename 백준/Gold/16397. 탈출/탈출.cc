#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, T, G;
int DP[100000];

int ans = INT_MAX;

void solve(int counter, int now) {
    queue<pair<int, int>> q;
    q.push({counter, now});

    while(!q.empty()) {
        int now_counter = q.front().first;
        int now_number = q.front().second;
        q.pop();

        if (now_number >= 100000) continue;
        if (DP[now_number] <= now_counter) continue;
        if (now_counter > T) continue;

        DP[now_number] = now_counter;

        if (now_number == G) {
            ans = min(ans, DP[now_number]);
            continue;
        }

        q.push({now_counter + 1, now_number + 1});

        if (now_number * 2 >= 100000 || now_number == 0) continue;

        int next = now_number * 2;
        int minus = 1;
        while(next >= 10) {
            next /= 10;
            minus *= 10;
        }

        q.push({now_counter + 1, now_number * 2 - minus});
    }
}

int main() {
    FastIO

    cin >> N >> T >> G;

    for (int i = 0; i < 100000; i++) {
        DP[i] = INT_MAX;
    }

    solve(0, N);

    if (ans == INT_MAX) {
        cout << "ANG";
    }
    else {
        cout << ans;
    }

    return 0;
}
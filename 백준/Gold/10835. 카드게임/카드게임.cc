#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int A[2001];
int B[2001];

int ans;

void solve() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 1}});

    while(!q.empty()) {
        int now_counter = q.front().first;
        int now_left = q.front().second.first;
        int now_right = q.front().second.second;
        q.pop();

        ans = max(ans, now_counter);
        if (now_left == N + 1 || now_right == N + 1) continue;

        if (A[now_left] > B[now_right]) {
            q.push({now_counter + B[now_right], {now_left, now_right + 1}});
        }
        q.push({now_counter, {now_left + 1, now_right + 1}});
        q.push({now_counter, {now_left + 1, now_right}});
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    solve();

    cout << ans;

    return 0;
}
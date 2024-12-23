#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;
set<int> chk;

int ans = INT_MAX;

int change(int val, int idx) {
    int ret = 0;
    vector<int> partial;
    for (int i = 0; i < N; i++) {
        partial.push_back(val % 10);
        val /= 10;
    }

    reverse(partial.begin(), partial.end());

    for (int i = 0; i < K / 2; i++) {
        int tmp = partial[idx + K - 1 - i];
        partial[idx + K - 1 - i] = partial[i + idx];
        partial[i + idx] = tmp;
    }

    for (int i = 0; i < N; i++) {
        ret *= 10;
        ret += partial[i];
    }

    return ret;
}

bool same(int val) {
    int comp = 0;
    for (int i = 1; i <= N; i++) {
        comp *= 10;
        comp += i;
    }

    if (val == comp) return true;
    else return false;
}

void solve(int init) {
    queue<pair<int, int>> q;
    q.push({init, 0});
    chk.insert(init);

    while(!q.empty()) {
        int now = q.front().first;
        int nowCnt = q.front().second;
        q.pop();

        if (same(now)) {
            ans = min(ans, nowCnt);
            continue;
        }

        for (int i = 0; i <= N - K; i++) {
            int next = change(now, i);

            if (chk.find(next) != chk.end()) continue;
            q.push({next, nowCnt + 1});
            chk.insert(next);
        }
    }
}

int main() {
    FastIO

    cin >> N >> K;
    int init = 0;
    save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
        init *= 10;
        init += save[i];
    }

    solve(init);

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> graph[123457];
long long DP[123457];

void solve(int before, int now) {
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (next == before) continue;
        solve(now, next);
        DP[now] += max(0LL, DP[next]);
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 2; i <= N; i++) {
        char t;
        int a, p;
        cin >> t >> a >> p;

        if (t == 'W') {
            DP[i] -= a;
        }
        else if (t == 'S') {
            DP[i] += a;
        }

        graph[i].push_back(p);
        graph[p].push_back(i);
    }

    solve(0, 1);

    cout << DP[1];

    return 0;
}
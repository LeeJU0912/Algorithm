#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int DP[2001][2001];

int calc(int a, int b) {
    return abs(save[a] - save[b]);
}

int solve(int idx, int one, int two) {
    if (idx == N + 1) {
        return 0;
    }

    if (DP[one][two] != -1) return DP[one][two];

    int calc1 = (one == 0 ? 0 : calc(one, idx)) + solve(idx + 1, idx, two);
    int calc2 = (two == 0 ? 0 : calc(two, idx)) + solve(idx + 1, one, idx);

    DP[one][two] = min(calc1, calc2);

    return DP[one][two];
}

int main() {
    FastIO

    cin >> N;

    save.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        save.push_back(x);
    }

    memset(DP, -1, sizeof(DP));
    cout << solve(1, 0, 0);

    return 0;
}
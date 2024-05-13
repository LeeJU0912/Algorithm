#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, W;
vector<pair<int, int>> save;
int DP[1001][1001];

int calc(int a, int b) {
    if (a == 0) {
        return abs(1 - save[b].first) + abs(1 - save[b].second);
    }
    else if (b == 0) {
        return abs(save[a].first - N) + abs(save[a].second - N);
    }
    else {
        return abs(save[a].first - save[b].first) + abs(save[a].second - save[b].second);
    }
}

int solve(int idx, int one, int two) {
    if (idx == W + 1) return 0;
    if (DP[one][two] != -1) return DP[one][two];

    int calc1 = calc(one, idx) + solve(idx + 1, idx, two);
    int calc2 = calc(idx, two) + solve(idx + 1, one, idx);

    DP[one][two] = min(calc1, calc2);

    return DP[one][two];
}

void road(int idx, int one, int two) {
    if (idx == W + 1) return;

    int calc1 = calc(one, idx);
    int calc2 = calc(idx, two);

    if (DP[idx][two] + calc1 < DP[one][idx] + calc2) {
        cout << 1 << '\n';
        road(idx + 1, idx, two);
    }
    else {
        cout << 2 << '\n';
        road(idx + 1, one, idx);
    }
}

int main() {
    FastIO

    cin >> N >> W;

    save.push_back({0, 0});
    for (int i = 0; i < W; i++) {
        int x, y;
        cin >> x >> y;
        save.push_back({x, y});
    }

    memset(DP, -1, sizeof(DP));

    cout << solve(1, 0, 0) << '\n';
    road(1, 0, 0);

    return 0;
}
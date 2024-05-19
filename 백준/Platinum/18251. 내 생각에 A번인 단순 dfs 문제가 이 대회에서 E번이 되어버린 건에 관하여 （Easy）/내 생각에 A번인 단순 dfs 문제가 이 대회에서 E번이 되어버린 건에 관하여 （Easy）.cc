#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<long long> W;

int tree_depth;

int counter;
vector<pair<int, int>> DP;

void dfs(int idx, int depth) {
    if (idx > N) return;

    dfs(idx * 2, depth + 1);

    counter++;
    DP[counter] = {depth, W[idx]};
    tree_depth = max(tree_depth, depth);

    dfs(idx * 2 + 1, depth + 1);
}

int main() {
    FastIO

    cin >> N;
    W = vector<long long>(N + 1);
    DP = vector<pair<int, int>>(N + 1);

    long long ans = LLONG_MIN;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];

        ans = max(ans, W[i]);
    }

    if (ans <= 0) {
        cout << ans;
        return 0;
    }

    dfs(1, 1);


    for (int i = 1; i <= tree_depth; i++) {
        for (int j = i; j <= tree_depth; j++) {
            long long temp = 0;
            long long maxi = 0;

            for (int k = 1; k <= N; k++) {
                if (DP[k].first < i || DP[k].first > j) continue;
                temp = max(0LL, temp + DP[k].second);

                maxi = max(maxi, temp);
            }

            ans = max(ans, maxi);
        }
    }

    cout << ans;

    return 0;
}
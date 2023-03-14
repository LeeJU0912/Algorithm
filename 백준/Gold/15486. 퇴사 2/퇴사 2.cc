#include <bits/stdc++.h>
using namespace std;

int DP[1500001];
vector<pair<int, int>> save;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        save.emplace_back(a, b);
    }

    for (int i = 0; i < N; i++) {
        DP[i] = max(DP[i], DP[i - 1]);
        int jump = save[i].first - 1;
        if (i + jump < N) {
            DP[i + jump] = max(DP[i + jump], DP[i - 1] + save[i].second);
        }
    }

    cout << DP[N - 1];

    return 0;
}
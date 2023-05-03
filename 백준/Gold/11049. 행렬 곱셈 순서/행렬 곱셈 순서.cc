#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;
int DP[500][500];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        save.emplace_back(a, b);
    }

    if (save.size() == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; i + j < N; j++) {
            DP[j][j + i] = INT_MAX;
            for (int k = j; k < j + i; k++) {
                DP[j][j + i] = min(DP[j][j + i], DP[j][k] + DP[k + 1][j + i] + save[j].first * save[k].second * save[j + i].second);
            }
        }
    }

    cout << DP[0][N - 1];

    return 0;
}
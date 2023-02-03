#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, start, maxi;
vector<int> save;

bool DP[51][1001];

int main() {
    FastIO

    cin >> N >> start >> maxi;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    DP[0][start] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= maxi; j++) {
            if (DP[i - 1][j]) {
                if (j + save[i - 1] <= maxi) DP[i][j + save[i - 1]] = true;
                if (j - save[i - 1] >= 0) DP[i][j - save[i - 1]] = true;
            }
        }
    }

    for (int i = maxi; i >= 0; i--) {
        if (DP[N][i]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;


    return 0;
}
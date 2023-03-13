#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> coin;
vector<int> DP;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        cin >> N;

        coin = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> coin[i];
        }

        cin >> M;

        DP = vector<int>(M + 1, 0);

        DP[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= M; j++) {
                DP[j] += DP[j - coin[i]];
            }
        }

        cout << DP[M] << '\n';
    }

    return 0;
}
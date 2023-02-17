#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> save(N);

        for (int i = 0; i < N; i++) {
            cin >> save[i];
        }

        vector<int> DP(N);

        DP[0] = save[0];

        for (int i = 1; i < N; i++) {
            DP[i] = max(DP[i - 1] + save[i], save[i]);
        }

        cout << *max_element(DP.begin(), DP.end()) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N;
int DP[31];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    DP[0] = 1;
    DP[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        DP[i] = DP[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            DP[i] += DP[j] * 2;
        }
    }

    cout << DP[N];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

string bulb[50];

int ans;

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> bulb[i];
    }

    cin >> K;

    for (int i = 0; i < N; i++) {
        int counter = 0;
        for (int j = 0; j < M; j++) {
            if (bulb[i][j] == '0') counter++;
        }

        if (counter > K || (counter % 2 != K % 2)) continue;
        int maxi = 0;
        for (int j = 0; j < N; j++) {
            if (bulb[i] == bulb[j]) maxi++;
        }

        ans = max(ans, maxi);
    }

    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[20][20];
int DP[1048577]; // (1 << 20) + 1

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> save[i][j];
        }
    }

    for (int i = 1; i < (1 << N); i++) {
        DP[i] = 1e9;
    }

    DP[0] = 0;

    for (int i = 0; i < (1 << N); i++) {
        int now = i;
        int counter = 0;

        while(now) {
            if (now & 1) counter++;
            now >>= 1;
        }

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) continue;
            DP[i | (1 << j)] = min(DP[i | (1 << j)], DP[i] + save[counter][j]);
        }
    }

    cout << DP[(1 << N) - 1];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string magic;
string A, B;

int DP_A[100][20];
int DP_B[100][20];

int ans;

int solve(int idx, int magic_idx, bool turn) {
    if (magic_idx == magic.size() - 1) return 1;

    if (turn) {
        if (DP_A[idx][magic_idx]) return DP_A[idx][magic_idx];


        for (int i = idx + 1; i < A.size(); i++) {
            if (B[i] == magic[magic_idx + 1]) {
                DP_A[idx][magic_idx] += solve(i, magic_idx + 1, false);
            }
        }

        return DP_A[idx][magic_idx];
    }
    else {
        if (DP_B[idx][magic_idx]) return DP_B[idx][magic_idx];


        for (int i = idx + 1; i < B.size(); i++) {
            if (A[i] == magic[magic_idx + 1]) {
                DP_B[idx][magic_idx] += solve(i, magic_idx + 1, true);
            }
        }

        return DP_B[idx][magic_idx];
    }
}

int main() {
    FastIO

    cin >> magic >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        if (DP_A[i][0] != 0) continue;
        if (A[i] == magic[0]) {
            ans += solve(i, 0, true);
        }
    }

    for (int i = 0; i < B.size(); i++) {
        if (DP_B[i][0] != 0) continue;
        if (B[i] == magic[0]) {
            ans += solve(i, 0, false);
        }
    }

    cout << ans;

    return 0;
}
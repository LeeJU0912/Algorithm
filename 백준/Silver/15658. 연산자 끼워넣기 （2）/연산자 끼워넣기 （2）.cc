#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> A;
int calc[4];

int maxi = INT_MIN;
int mini = INT_MAX;

void solve(int idx, int val) {
    if (idx == N) {
        maxi = max(maxi, val);
        mini = min(mini, val);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (calc[i] == 0) continue;
        calc[i]--;

        if (i == 0) {
            solve(idx + 1, val + A[idx]);
        }
        else if (i == 1) {
            solve(idx + 1, val - A[idx]);
        }
        else if (i == 2) {
            solve(idx + 1, val * A[idx]);
        }
        else if (i == 3) {
            solve(idx + 1, val / A[idx]);
        }

        calc[i]++;
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < 4; i++) {
        cin >> calc[i];
    }

    for (int i = 0; i < 4; i++) {
        if (calc[i] == 0) continue;
        calc[i]--;

        if (i == 0) {
            solve(2, A[0] + A[1]);
        }
        else if (i == 1) {
            solve(2, A[0] - A[1]);
        }
        else if (i == 2) {
            solve(2, A[0] * A[1]);
        }
        else if (i == 3) {
            solve(2, A[0] / A[1]);
        }

        calc[i]++;
    }

    cout << maxi << '\n' << mini;

    return 0;
}
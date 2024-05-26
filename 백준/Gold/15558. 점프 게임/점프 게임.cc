#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, k;
string line[2];
int visited[2][100001];

bool ans;

void solve(bool turn, int idx, int counter) {
    if (ans) return;
    if (idx >= N) {
        ans = true;
        return;
    }

    if (counter > idx) return;
    if (line[turn][idx] == '0') return;
    if (visited[turn][idx] <= counter) return;
    visited[turn][idx] = counter;

    solve(turn, idx + 1, counter + 1);
    solve(turn, idx - 1, counter + 1);
    solve(!turn, idx + k, counter + 1);
}

int main() {
    FastIO

    cin >> N >> k;
    cin >> line[0] >> line[1];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = INT_MAX;
        }
    }

    solve(false, 0, 0);

    cout << ans;

    return 0;
}
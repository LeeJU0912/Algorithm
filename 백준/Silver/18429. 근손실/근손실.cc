#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;
bool chk[8];

int ans;

void solve(int counter, int hap) {
    if (counter * K > hap) return;
    if (counter == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (chk[i]) continue;
        chk[i] = true;
        solve(counter + 1, hap + save[i]);
        chk[i] = false;
    }
}

int main() {
    FastIO

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    solve(0, 0);

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool chk_sosu(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

void solve(int counter, int now) {
    if (chk_sosu(now)) {
        if (counter == N) {
            cout << now << '\n';
            return;
        }
        for (int i = 1; i <= 9; i++) {
            solve(counter + 1, now * 10 + i);
        }
    }
    else return;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 2; i <= 7; i++) {
        solve(1, i);
    }

    return 0;
}
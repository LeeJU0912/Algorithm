#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int k;
vector<char> save;
bool chk[10];

long long ans_maxi = LLONG_MIN;
long long ans_mini = LLONG_MAX;

void solve(int idx, int now, long long sum) {
    if (idx == k) {
        ans_maxi = max(ans_maxi, sum);
        ans_mini = min(ans_mini, sum);
    }
    if (save[idx] == '<') {
        for (int i = now + 1; i < 10; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            solve(idx + 1, i, sum * 10 + i);
            chk[i] = false;
        }
    }
    else if (save[idx] == '>') {
        for (int i = now - 1; i >= 0; i--) {
            if (chk[i]) continue;
            chk[i] = true;
            solve(idx + 1, i, sum * 10 + i);
            chk[i] = false;
        }
    }
}

int main() {
    FastIO

    cin >> k;

    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        save.push_back(c);
    }

    for (int i = 0; i < 10; i++) {
        chk[i] = true;
        solve(0, i, i);
        chk[i] = false;
    }

    cout.width(k + 1);
    cout.fill('0');
    cout << ans_maxi << '\n';

    cout.width(k + 1);
    cout.fill('0');
    cout << ans_mini;


    return 0;
}
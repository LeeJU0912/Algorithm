#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
bool chk[51];
bool space_chk[91];

int N;
bool ans;

void solve(int idx) {
    if (idx == s.size()) {
        ans = true;
        return;
    }

    int one = s[idx] - '0';

    if (one > 0 && !chk[one]) {
        chk[one] = true;
        space_chk[idx] = true;
        solve(idx + 1);
        if (ans) return;
        chk[one] = false;
        space_chk[idx] = false;
    }
    if (N >= 10 && idx < s.size() - 1 && s[idx] != '0') {
        int two = (s[idx] - '0') * 10 + (s[idx + 1] - '0');

        if (two <= N && !chk[two]) {
            chk[two] = true;
            space_chk[idx + 1] = true;
            solve(idx + 2);
            if (ans) return;
            chk[two] = false;
            space_chk[idx + 1] = false;
        }
    }
}

int main() {
    FastIO

    cin >> s;

    if (s == "1") {
        cout << 1;
        return 0;
    }

    int size = s.size();
    if (size > 9) {
        N += 9;
        size -= 9;
        N += size / 2;
    }
    else {
        N = size;
    }

    int one = s[0] - '0';

    if (one > 0) {
        chk[one] = true;
        space_chk[0] = true;
        solve(1);
        if (!ans) {
            chk[one] = false;
            space_chk[0] = false;
        }
    }
    if (N >= 10 && !ans) {
        int two = (s[0] - '0') * 10 + (s[1] - '0');
        
        if (two <= N) {
            chk[two] = true;
            space_chk[1] = true;
            solve(2);
        }
    }

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (space_chk[i]) {
            cout << ' ';
        }
    }

    return 0;
}
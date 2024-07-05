#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

bool ans;

string solve(int start, int end) {
    if (start == end) {
        string tmp;
        tmp += s[start];

        return tmp;
    }

    int half = (end - start + 1) / 2;

    string l = solve(start, start + half - 1);
    string r = solve(end - half + 1, end);

    if (l.empty() || r.empty()) {
        ans = true;
    }
    else {
        for (int i = 0; i < l.size(); i++) {
            if (l[i] != r[r.size() - 1 - i]) ans = true;
        }
    }

    if (ans) {
        return "";
    }
    else {
        return s.substr(start, end - start + 1);
    }
}

int main() {
    FastIO

    cin >> s;

    solve(0, s.size() - 1);

    cout << (ans ? "IPSELENTI" : "AKARAKA");

    return 0;
}
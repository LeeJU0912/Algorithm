#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int cnt[2];

int main() {
    FastIO

    string s;
    getline(cin,s);
    for (int i = 0; i < s.size() - 2; i++) {
        string tmp = s.substr(i, 3);

        if (tmp == ":-)") cnt[0]++;
        else if (tmp == ":-(") cnt[1]++;
    }

    if (cnt[0] == cnt[1]) {
        if (cnt[0] == 0) {
            cout << "none";
        }
        else {
            cout << "unsure";
        }
    }
    else {
        if (cnt[0] > cnt[1]) {
            cout << "happy";
        }
        else {
            cout << "sad";
        }
    }

    return 0;
}
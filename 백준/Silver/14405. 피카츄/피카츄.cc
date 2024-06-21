#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string save[3] = {"pi", "ka", "chu"};

int main() {
    FastIO

    string s;
    cin >> s;

    bool ans = false;

    int cursor = 0;
    while(cursor < s.size()) {
        string next2;
        next2 += s[cursor];
        next2 += s[cursor + 1];

        if (next2 == save[0] || next2 == save[1]) {
            cursor += 2;
            continue;
        }

        if (cursor < s.size() - 2) {
            string next3;
            next3 += s[cursor];
            next3 += s[cursor + 1];
            next3 += s[cursor + 2];

            if (next3 == save[2]) {
                cursor += 3;
                continue;
            }
        }

        break;
    }

    cout << (cursor == s.size() ? "YES" : "NO");

    return 0;
}
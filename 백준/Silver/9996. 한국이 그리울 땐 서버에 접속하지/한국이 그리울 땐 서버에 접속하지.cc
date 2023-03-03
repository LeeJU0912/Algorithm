#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    string key;
    cin >> key;

    int cursor = 0;
    string first;
    string last;
    while(key[cursor] != '*') {
        first.push_back(key[cursor]);
        cursor++;
    }
    cursor++;
    while(cursor != key.length()) {
        last.push_back(key[cursor]);
        cursor++;
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s.length() < first.length() + last.length()) {
            cout << "NE" << '\n';
            continue;
        }

        bool flag1 = false;
        for (int j = 0; j < first.size(); j++) {
            if (s[j] != key[j]) {
                flag1 = true;
                break;
            }
        }

        bool flag2 = false;
        for (int j = 0; j < last.size(); j++) {
            if (s[s.length() - 1 - j] != last[last.length() - 1 - j]) {
                flag2 = true;
                break;
            }
        }

        if (flag1 || flag2) {
            cout << "NE" << '\n';
        }
        else {
            cout << "DA" << '\n';
        }
    }

    return 0;
}
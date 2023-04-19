#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save(26);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        save[s[0] - 'a']++;
    }

    bool chk = false;
    for (int i = 0; i < 26; i++) {
        if (save[i] >= 5) {
            cout << (char)('a' + i);
            chk = true;
        }
    }

    if (!chk) {
        cout << "PREDAJA";
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    bool found = false;
    for (int i = 1; i <= 5; i++) {
        string s;
        cin >> s;
        if (s.find("FBI") != string::npos) {
            cout << i << ' ';
            found = true;
        }
    }

    if (!found) cout << "HE GOT AWAY!";

    return 0;
}
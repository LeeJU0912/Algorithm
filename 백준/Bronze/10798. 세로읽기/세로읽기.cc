#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    string s[5];

    for (int i = 0; i < 5; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[j].length() <= i) continue;
            cout << s[j][i];
        }
    }

    return 0;
}
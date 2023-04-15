#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> save;

int main(){
    FastIO

    string s;

    while(true) {
        getline(cin, s);

        if (s == "END") break;

        for (int i = s.length() - 1; i >= 0; i--) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}
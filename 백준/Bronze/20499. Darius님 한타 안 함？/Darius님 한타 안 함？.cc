#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    vector<int> save;
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            save.push_back(now);
            now = 0;
        }
        else {
            now *= 10;
            now += s[i] - '0';
        }
    }
    save.push_back(now);

    if (save[0] + save[2] < save[1] || save[1] == 0) cout << "hasu";
    else cout << "gosu";

    return 0;
}
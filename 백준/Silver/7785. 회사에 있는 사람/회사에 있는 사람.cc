#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    map<string, bool, greater<>> m;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b == "enter") {
            m[a] = true;
        }
        else {
            m[a] = false;
        }
    }

    for (auto i : m) {
        if (i.second) cout << i.first << '\n';
    }

    return 0;
}
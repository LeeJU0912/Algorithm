#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (a.length() >= b.length()) {
        cout << "go";
    }
    else {
        cout << "no";
    }

    return 0;
}
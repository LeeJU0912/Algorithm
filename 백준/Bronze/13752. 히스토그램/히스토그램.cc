#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        string s;
        for (int j = 0; j < tmp; j++) {
            s += '=';
        }

        cout << s << '\n';
    }

    return 0;
}
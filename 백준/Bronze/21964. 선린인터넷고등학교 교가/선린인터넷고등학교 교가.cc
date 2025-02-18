#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    string s;
    cin >> s;
    for (int i = N - 5; i < s.size(); i++) {
        cout << s[i];
    }

    return 0;
}
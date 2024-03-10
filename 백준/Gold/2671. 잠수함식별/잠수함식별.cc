#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    cout << (regex_match(s, regex("(100+1+|01)+")) ? "SUBMARINE" : "NOISE");

    return 0;
}
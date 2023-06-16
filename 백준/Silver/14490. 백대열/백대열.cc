#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    long long a = 0;
    long long b = 0;

    int cursor = 0;

    while (s[cursor] != ':') {
        a *= 10;
        a += s[cursor] - '0';
        cursor++;
    }

    cursor++;

    while (cursor != s.length()) {
        b *= 10;
        b += s[cursor] - '0';
        cursor++;
    }

    cout << a / gcd(a, b) << ':' <<  b / gcd(a, b);

    return 0;
}
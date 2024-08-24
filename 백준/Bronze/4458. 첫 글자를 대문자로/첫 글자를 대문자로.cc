#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        
        if ('a' <= s[0] && s[0] <= 'z') {
            s[0] -= 'a';
            s[0] += 'A';
        }

        cout << s << '\n';
    }

    return 0;
}
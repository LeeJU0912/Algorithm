#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            s[j] = tolower(s[j]);
        }
        cout << s << '\n';
    }

    return 0;
}
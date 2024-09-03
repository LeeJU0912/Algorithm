#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s.size() >= 6 && s.size() <= 9) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
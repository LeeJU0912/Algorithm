#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string S, T;

int main() {
    FastIO

    cin >> S >> T;

    while(!T.empty() && S != T) {
        if (T[T.size() - 1] == 'A') {
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if (T.empty()) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}
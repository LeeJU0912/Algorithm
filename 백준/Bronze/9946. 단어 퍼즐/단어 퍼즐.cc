#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string a, b;

    int t = 1;
    while(true) {
        cin >> a >> b;

        if (a == "END" && b == "END") break;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a == b) {
            cout << "Case " << t++ << ": " << "same" << '\n';
        }
        else {
            cout << "Case " << t++ << ": " << "different" << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string N;
    while(true) {
        cin >> N;
        if (N == "0") break;

        int hap = 0;
        for (int i = 0; i < N.size(); i++) {
            if (N[i] == '1') hap += 2;
            else if (N[i] == '0') hap += 4;
            else hap += 3;
        }

        cout << N.size() + 1 + hap << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int L, P;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> P;

    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        cout << temp - L * P << ' ';
    }

    return 0;
}
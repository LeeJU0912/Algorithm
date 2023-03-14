#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    n /= 4;

    for (int i = 0; i < n; i++) {
        cout << "long ";
    }
    cout << "int";

    return 0;
}
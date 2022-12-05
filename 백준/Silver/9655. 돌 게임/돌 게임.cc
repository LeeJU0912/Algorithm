#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    if (N & 1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool SK[1001];

int main() {
    FastIO

    int N;
    cin >> N;

    SK[2] = true;
    SK[4] = true;
    SK[5] = true;

    for (int i = 6; i <= N; i++) {
        if (SK[i - 1] && SK[i - 3] && SK[i - 4]) {
            SK[i] = false;
        }
        else SK[i] = true;
    }

    cout << (SK[N] ? "SK" : "CY");

    return 0;
}
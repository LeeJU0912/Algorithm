#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long N;
    cin >> N;

    cout << (N % 2 == 0 ? "CY" : "SK");

    return 0;
}
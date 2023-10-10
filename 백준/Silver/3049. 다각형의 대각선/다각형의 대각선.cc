#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int N;
    cin >> N;

    cout << (N * (N - 1) * (N - 2) * (N - 3)) / 24;

    return 0;
}
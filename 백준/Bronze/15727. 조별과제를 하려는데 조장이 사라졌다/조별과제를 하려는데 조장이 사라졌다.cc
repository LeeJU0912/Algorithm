#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    if (N % 5) {
        cout << (N / 5) + 1;
    }
    else {
        cout << N / 5;
    }

    return 0;
}
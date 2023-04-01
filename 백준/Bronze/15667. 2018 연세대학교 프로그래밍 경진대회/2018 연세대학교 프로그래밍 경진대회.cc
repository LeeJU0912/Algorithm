#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    N--;

    for (int i = 1; i < 10000; i++) {
        if (i + i * i == N) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
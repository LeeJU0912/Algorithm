#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    if (N % 2) {
        for (int i = 0; i < N; i++) {
            if (i == N - 1) {
                cout << 3;
            }
            else if (i % 2) {
                cout << 2 << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (i % 2) {
                cout << 2 << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
    }

    return 0;
}
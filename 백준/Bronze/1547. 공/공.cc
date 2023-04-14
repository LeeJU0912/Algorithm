#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int M;
    cin >> M;

    int ball = 1;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (a == ball) {
            ball = b;
        }
        else if (b == ball) {
            ball = a;
        }
    }

    cout << ball;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool chk(int num) {
    while(num) {
        int now = num % 10;
        if (now != 4 && now != 7) return false;
        num /= 10;
    }
    return true;
}

int main() {
    FastIO

    int N;
    cin >> N;
    for (int i = N; i >= 4; i--) {
        if (chk(i)) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
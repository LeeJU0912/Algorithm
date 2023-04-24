#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int a = 0;
    int b = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        a += ((temp / 30) + 1) * 10;
        b += ((temp / 60) + 1) * 15;
    }

    if (a < b) {
        cout << "Y " << a;
    }
    else if (a == b) {
        cout << "Y M " << a;
    }
    else {
        cout << "M " << b;
    }

    return 0;
}
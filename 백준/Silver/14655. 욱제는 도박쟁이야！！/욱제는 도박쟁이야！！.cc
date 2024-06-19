#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int a, b;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a += abs(temp);
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        b += abs(temp);
    }

    cout << a + b;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
long long save[101];

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> save[i];

        save[i] *= i;
    }

    for (int i = N; i >= 1; i--) {
        save[i] -= save[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        cout << save[i] << ' ';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;

        cout << M * 2 - N << ' ' << (N - (M * 2 - N)) / 2 << '\n';
    }

    return 0;
}
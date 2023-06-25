#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B, N;

    cin >> A >> B >> N;

    int counter = 0;

    int ans[1000000];

    while (counter <= N) {
        ans[counter] = A / B;

        A %= B;
        A *= 10;

        counter++;
    }

    cout << ans[N];

    return 0;
}
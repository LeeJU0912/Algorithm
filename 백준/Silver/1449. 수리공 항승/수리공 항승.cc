#include <bits/stdc++.h>

using namespace std;

int N, L;
int leak[1001];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> leak[i];
    }

    sort(leak, leak + N);

    for (int i = 0; i < N;) {
        int counter = 1;
        while (leak[i + counter] - leak[i] + 1 <= L) {
            counter++;
        }
        i += counter;
        ans++;
    }

    cout << ans;

    return 0;
}
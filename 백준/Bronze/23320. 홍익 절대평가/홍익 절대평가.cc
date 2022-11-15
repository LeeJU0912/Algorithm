#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];
int X, Y;
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> X >> Y;

    int cut = N * X / 100;

    for (int i = 0; i < N; i++) {
        if (A[i] >= Y) {
            ans++;
        }
    }

    cout << cut << ' ' << ans;

    return 0;
}
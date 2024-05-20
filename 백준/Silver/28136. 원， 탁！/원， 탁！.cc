#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int ans;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (save[i] >= save[i + 1]) ans++;
    }

    if (save[N - 1] >= save[0]) ans++;

    cout << ans;

    return 0;
}
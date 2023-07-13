#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
double ans;

int main() {
    FastIO

    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    int except = round(0.15 * N);

    vector<int> save(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    for (int i = except; i < N - except; i++) {
        ans += save[i];
    }

    cout << (int)round(ans / (N - 2 * except));

    return 0;
}
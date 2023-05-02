#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, L;
    cin >> N >> L;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int idx = -1;

    for (int i = 0; i < N; i++) {
        if (save[i] <= L) {
            idx = i;
            break;
        }
    }

    for (int i = idx; i < N; i++) {
        if (save[i] <= L) {
            L++;
        }
        else {
            break;
        }
    }

    cout << L;

    return 0;
}
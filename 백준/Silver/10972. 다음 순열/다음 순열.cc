#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    if (N == 1) {
        cout << -1;
        return 0;
    }

    next_permutation(save.begin(), save.end());

    int chk = 0;
    for (int i = 0; i < N - 1; i++) {
        if (save[i] < save[i + 1]) {
            chk++;
        }
    }
    if (chk == N - 1) {
        cout << -1;
    }
    else {
        for (int i = 0; i < N; i++) {
            cout << save[i] << ' ';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        int maxi = 0;
        int idx = 0;
        for (int j = 0; i + j <= min(i + S, N - 1); j++) {
            if (maxi < save[i + j]) {
                maxi = save[i + j];
                idx = i + j;
            }
        }

        for (int j = idx; j > i; j--) {
            int temp = save[j];
            save[j] = save[j - 1];
            save[j - 1] = temp;
            S--;
            if (S == 0) break;
        }

        if (S == 0) break;
    }


    for (auto i : save) {
        cout << i << ' ';
    }

    return 0;
}
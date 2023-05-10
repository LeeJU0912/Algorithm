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

    vector<int> length(N);

    int maxi = 0;
    for (int i = 0; i < N; i++) {
        length[i] = 1;

        for (int j = 0; j < i; j++) {
            if (save[j] < save[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        maxi = max(maxi, length[i]);
    }

    cout << N - maxi;

    return 0;
}
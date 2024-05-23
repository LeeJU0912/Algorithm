#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
vector<int> DP;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);
    DP = vector<int>(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    DP[save[0]]++;
    int counter = 1;

    for (int i = 1; i < N; i++) {
        DP[save[i]] = DP[save[i] - 1] + 1;
        counter = max(counter, DP[save[i]]);
    }

    cout << N - counter;

    return 0;
}
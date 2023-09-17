#include <bits/stdc++.h>
using namespace std;

int N;
int save[1001];
int counter[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> save[i];
        counter[i] = 1e9;
    }

    counter[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= save[i]; j++) {
            if (i + j >= N) continue;
            counter[i + j] = min(counter[i + j], counter[i] + 1);
        }
    }

    if (counter[N - 1] == 1e9) {
        cout << -1;
    }
    else {
        cout << counter[N - 1];
    }

    return 0;
}
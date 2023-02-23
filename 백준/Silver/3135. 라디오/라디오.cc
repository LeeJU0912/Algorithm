#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B;
    cin >> A >> B;

    int N;
    cin >> N;

    vector<int> DP(1001, INT_MAX);

    queue<int> save;
    save.push(A);
    DP[A] = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push(temp);
        if (DP[temp]) {
            DP[temp] = 1;
        }
    }

    while(!save.empty()) {
        int now = save.front();
        save.pop();

        for (int i = -1; i <= 1; i += 2) {
            int next = now + i;
            if (next <= 0 || next > 1000) continue;
            if (DP[next] > DP[now] + 1) {
                DP[next] = DP[now] + 1;
                save.push(next);
            }
        }
    }

    cout << DP[B];

    return 0;
}
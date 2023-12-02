#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

long long mod[1000];

int main() {
    FastIO

    cin >> N >> M;

    long long hap = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        hap += temp;
        mod[hap % M]++;
    }

    long long ans = mod[0];
    for (int i = 0; i < M; i++) {
        if (mod[i]) {
            ans += (mod[i] * (mod[i] - 1)) / 2;
        }
    }

    cout << ans;

    return 0;
}
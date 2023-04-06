#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, K;
    cin >> N >> K;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    vector<int> hap(N - K + 1);

    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j < K; j++) {
            hap[i] += save[i + j];
        }
    }

    cout << *max_element(hap.begin(), hap.end());
    
    return 0;
}

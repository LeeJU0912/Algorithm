#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<long long> save(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }
    sort(save.begin(), save.end());


    vector<long long> hap;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            hap.push_back(save[i] + save[j]);
        }
    }
    sort(hap.begin(), hap.end());


    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (binary_search(hap.begin(), hap.end(), save[j] - save[i])) {
                ans = max(ans, save[j]);
            }
        }
    }

    cout << ans;

    return 0;
}
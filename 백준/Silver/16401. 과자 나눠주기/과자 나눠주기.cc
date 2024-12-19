#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int M, N;
    cin >> M >> N;
    vector<int> save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int maxi = 1e9;
    int mini = 1;
    int ans = INT_MAX;
    while(mini <= maxi) {
        int mid = (mini + maxi) / 2;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (save[i] / mid);
        }

        if (cnt < M) {
            maxi = mid - 1;
        }
        else {
            mini = mid + 1;
            ans = mid;
        }
    }

    cout << (ans == INT_MAX ? 0 : ans);

    return 0;
}
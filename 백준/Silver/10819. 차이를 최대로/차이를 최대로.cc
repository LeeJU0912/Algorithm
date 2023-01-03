#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int ans = 0;
    int N;

    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    do {
        int temp = 0;
        for (int i = 1; i < N; i++) {
            temp += abs(v[i - 1] - v[i]);
        }
        ans = max(ans, temp);
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}
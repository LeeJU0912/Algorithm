#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    int ans_counter = 0;

    long long now = v[0];
    int now_counter = 0;

    for (int i = 0; i < N; i++) {
        if (now != v[i]) {
            if (ans_counter < now_counter) {
                ans = now;
                ans_counter = now_counter;
            }
            now_counter = 1;
            now = v[i];
        }
        else {
            now_counter++;
        }
    }

    if (ans_counter < now_counter) {
        ans = now;
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> time(N);

    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    sort(time.begin(), time.end(), greater<>());

    for (int i = 0; i < N; i++) {
        ans = max(ans, time[i] + i + 1);
    }
    
    cout << ans + 1;
    
    return 0;
}
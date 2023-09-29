#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int ans;

int main() {
    FastIO

    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end(), greater<>());

    for (int i = 0; i < N; i++) {
        if (i % 3 == 2) continue;
        ans += save[i];
    }

    cout << ans;

    return 0;
}
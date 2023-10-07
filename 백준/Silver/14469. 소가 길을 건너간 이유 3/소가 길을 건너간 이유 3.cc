#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<pair<int, int>> save;

int ans;

int main() {
    FastIO

    cin >> N;

    save = vector<pair<int, int>>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i].first >> save[i].second;
    }

    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        if (ans < save[i].first) ans = save[i].first;
        ans += save[i].second;
    }

    cout << ans;

    return 0;
}
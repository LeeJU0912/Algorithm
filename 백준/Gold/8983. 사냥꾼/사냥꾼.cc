#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int M, N, L;

vector<int> shot;
vector<pair<int, int>> pigs;

int ans;

int main() {
    FastIO

    cin >> M >> N >> L;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        shot.push_back(temp);
    }

    sort(shot.begin(), shot.end());

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pigs.push_back({a, b});
    }

    for (int i = 0; i < N; i++) {
        if (L < pigs[i].second) continue;
        int mini = max(0, pigs[i].first - (L - pigs[i].second));
        int maxi = min(1000000001, pigs[i].first + (L - pigs[i].second));

        int sch = lower_bound(shot.begin(), shot.end(), mini) - shot.begin();
        if (sch == M) continue;
        if (shot[sch] <= maxi) ans++;
    }

    cout << ans;

    return 0;
}
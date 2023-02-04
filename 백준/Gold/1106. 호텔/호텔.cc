#include <bits/stdc++.h>
using namespace std;

int hap[1100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cost;

    for (int i = 0; i < 1100; i++) {
        hap[i] = INT_MAX;
    }

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cost.emplace_back(a, b);
        hap[b] = min(hap[b], a);
    }

    for (int i = 1; i < C; i++) {
        if (hap[i] == INT_MAX) continue;
        for (int j = 0; j < cost.size(); j++) {
            hap[i + cost[j].second] = min(hap[i + cost[j].second], hap[i] + cost[j].first);
        }
    }

    cout << *min_element(hap + C, hap + C + 100);

    return 0;
}
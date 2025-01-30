#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> snow;
vector<pair<int, pair<int, int>>> snowman;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        snow.push_back(x);
    }

    sort(snow.begin(), snow.end(), greater());

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            snowman.push_back({snow[i] + snow[j], {i, j}});
        }
    }

    sort(snowman.begin(), snowman.end());

    int ans = INT_MAX;
    for (int i = 0; i < snowman.size() - 1; i++) {
        for (int j = i + 1; j < snowman.size(); j++) {
            if (snowman[j].second.first != snowman[i].second.first &&
            snowman[j].second.first != snowman[i].second.second &&
            snowman[j].second.second != snowman[i].second.first &&
            snowman[j].second.second != snowman[i].second.second) {
                ans = min(ans, snowman[j].first - snowman[i].first);
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, C, M;
vector<pair<pair<int, int>, int>> save;

int DP[2001];

int ans;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.second == b.first.second) return a.first.first < b.first.first;
    else return a.first.second < b.first.second;
}

int main() {
    FastIO

    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        save.push_back({{a, b}, c});
    }

    sort(save.begin(), save.end(), compare);

    for (int i = 0; i < M; i++) {
        int from = save[i].first.first;
        int to = save[i].first.second;
        int weight = save[i].second;
        int maxi = 0;

        for (int j = from; j < to; j++) {
            maxi = max(DP[j], maxi);
        }
        int capacity = min(weight, C - maxi);

        for (int j = from; j < to; j++) {
            DP[j] += capacity;
        }
        ans += capacity;
    }

    cout << ans;

    return 0;
}
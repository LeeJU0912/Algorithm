#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FastIO

    int N;
    cin >> N;

    vector<pair<int, int>> save;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        save.emplace_back(a, b);
    }

    sort(save.begin(), save.end(), compare);

    int ans = 1;
    int end_time = save[0].second;

    for (int i = 1; i < save.size(); i++) {
        if (end_time <= save[i].first) {
            end_time = save[i].second;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
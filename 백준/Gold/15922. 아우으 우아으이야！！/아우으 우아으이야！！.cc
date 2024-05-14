#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;

priority_queue<int> pq;

int ans;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        save.push_back({x, y});
    }

    int now = save[0].first;
    pq.push({save[0].second});
    for (int i = 1; i < N; i++) {
        if (save[i].second <= pq.top()) continue;
        else if (save[i].first < pq.top()) {
            pq.pop();
            pq.push(save[i].second);
        }
        else {
            ans += abs(pq.top() - now);

            now = save[i].first;
            pq.push(save[i].second);
        }
    }

    if (!pq.empty()) {
        ans += abs(pq.top() - now);
    }

    cout << ans;

    return 0;
}
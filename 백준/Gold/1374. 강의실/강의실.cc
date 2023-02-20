#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<pair<int, int>> save;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        save.emplace_back(b, c);
    }

    sort(save.begin(), save.end());

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (pq.empty()) {
            pq.push(save[i].second);
            ans++;
        }
        else {
            if (pq.top() > save[i].first) {
                pq.push(save[i].second);
                ans++;
            }
            else {
                pq.pop();
                pq.push(save[i].second);
            }
        }
    }

    cout << ans;

    return 0;
}
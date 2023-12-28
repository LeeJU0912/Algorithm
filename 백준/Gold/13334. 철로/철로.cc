#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> save;
int d;

priority_queue<int, vector<int>, greater<>> pq;

int ans;

int main() {
    FastIO

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a < b) {
            save.push_back({b, a});
        }
        else {
            save.push_back({a, b});
        }

    }

    cin >> d;

    sort(save.begin(), save.end());


    for (int i = 0; i < n; i++) {
        if (save[i].first - save[i].second > d) continue;

        pq.push(save[i].second);

        while(!pq.empty()) {
            if (d < save[i].first - pq.top()) pq.pop();
            else {
                ans = max(ans, (int)pq.size());
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
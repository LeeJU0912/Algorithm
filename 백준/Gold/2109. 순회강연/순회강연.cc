#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int d, p;

priority_queue<int> save[10001];

priority_queue<int, vector<int>, greater<>> pq;

int main() {
    FastIO

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        save[d].push(p);
    }

    for (int i = 1; i <= 10000; i++) {
        if (save[i].empty()) continue;

        int left = save[i].size();

        pq.push(save[i].top());
        save[i].pop();

        for (int j = 1; j < min(i, left); j++) {
            if (pq.size() < i) {
                pq.push(save[i].top());
                save[i].pop();
            }
            else if (pq.top() < save[i].top()) {
                pq.pop();
                pq.push(save[i].top());
                save[i].pop();
            }
            else break;
        }
    }

    int ans = 0;

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
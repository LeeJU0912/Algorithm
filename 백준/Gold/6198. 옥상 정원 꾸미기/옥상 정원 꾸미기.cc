#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

long long ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (pq.empty()) pq.push({temp, i});
        else {
            while(!pq.empty() && pq.top().first <= temp) {
                ans += i - 1 - pq.top().second;
                pq.pop();
            }

            pq.push({temp, i});
        }
    }

    while(!pq.empty()) {
        ans += N - 1 - pq.top().second;
        pq.pop();
    }

    cout << ans;

    return 0;
}
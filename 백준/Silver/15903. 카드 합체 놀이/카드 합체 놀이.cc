#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<>> pq;

int main() {
    FastIO

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    for (int i = 0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    long long ans = 0;

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
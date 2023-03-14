#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<>> pq;

        for (int i = 0; i < K; i++) {
            long long temp;
            cin >> temp;
            pq.push(temp);
        }

        long long ans = 0;

        while(pq.size() > 1) {
            long long one = pq.top();
            pq.pop();
            long long two = pq.top();
            pq.pop();

            ans += one + two;
            pq.push(one + two);
        }

        cout << ans << '\n';
    }

    return 0;
}
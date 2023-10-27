#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, P;

priority_queue<int> pq[500001];

int ans;

int main() {
    FastIO

    cin >> N >> P;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (pq[a].empty() || pq[a].top() < b) {
            ans++;
            pq[a].push(b);
        }
        else if (pq[a].top() > b) {
            while (!pq[a].empty() && pq[a].top() > b) {
                ans++;
                pq[a].pop();
            }

            if (pq[a].top() == b) continue;

            ans++;
            pq[a].push(b);
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    if (N == 1) {
        cout << 0;
        return 0;
    }

    while(pq.size() != 1) {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();

        ans += temp1 + temp2;
        pq.push(temp1 + temp2);
    }
    cout << ans;

    return 0;
}
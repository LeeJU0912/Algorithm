#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

priority_queue<int, vector<int>, greater<>> pq;

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;

            if (pq.size() == N) {
                pq.push(temp);
                pq.pop();
            }
            else {
                pq.push(temp);
            }
        }
    }

    cout << pq.top();

    return 0;
}
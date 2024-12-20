#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    priority_queue<int> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            if (pq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            for (int j = 0; j < a; j++) {
                int x;
                cin >> x;
                pq.push(x);
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, Q;
int A[500001];
int now = 1;
int temple;
set<int> temples;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 1) {
            temples.insert(i);
        }
    }

    for (int i = 0; i < Q; i++) {
        int order;
        cin >> order;
        if (order == 1) {
            int temp;
            cin >> temp;
            if (A[temp]) {
                A[temp] = 0;
                temples.erase(temp);
            }
            else {
                A[temp] = 1;
                temples.insert(temp);
            }
        }
        else if (order == 2) {
            int temp;
            cin >> temp;
            now += temp;
            now %= N;
            if (now == 0) {
                now = N;
            }
        }
        else if (order == 3) {
            if (temples.empty()) {
                cout << -1 << '\n';
                continue;
            }
            if (now > *(--temples.end())) {
                cout << N - now + *temples.begin() << '\n';
            }
            else if (now == *(--temples.end())) {
                cout << 0 << '\n';
            }
            else {
                cout << *temples.lower_bound(now) - now << '\n';
            }

        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

deque<int> dq;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int a;
            cin >> a;

            dq.push_front(a);
        }
        else if (order == 2) {
            int a;
            cin >> a;

            dq.push_back(a);
        }
        else if (order == 3) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (order == 4) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (order == 5) {
            cout << dq.size() << '\n';
        }
        else if (order == 6) {
            if (dq.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (order == 7) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        else if (order == 8) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}
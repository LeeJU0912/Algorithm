#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

stack<int> stk;

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int x;
            cin >> x;
            stk.push(x);
        }
        else if (order == 2) {
            if (stk.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if (order == 3) {
            cout << stk.size() << '\n';
        }
        else if (order == 4) {
            if (stk.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (order == 5) {
            if (stk.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stk.top() << '\n';
            }
        }
    }


    return 0;
}
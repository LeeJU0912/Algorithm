#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    stack<int> stk;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int a;
            cin >> a;
            stk.push(a);
        }
        else if (s == "pop") {
            if (stk.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if (s == "size") {
            cout << stk.size() << '\n';
        }
        else if (s == "empty") {
            if (stk.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (s == "top") {
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
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    string s;
    cin >> s;

    int ans = 0;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        }
        else if (s[i] == ')') {
            if (stk.empty()) {
                ans++;
            }
            else if (stk.top() == '(') {
                stk.pop();
            }
        }
    }

    cout << ans + stk.size();

    return 0;
}
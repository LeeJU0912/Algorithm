#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    stk.push(s[0]);

    for (int i = 1; i < s.length(); i++) {
        if (stk.empty()) {
            stk.push(s[i]);
        }
        else if (s[i] > stk.top()) {
            while(!stk.empty() && s[i] > stk.top() && K != 0) {
                stk.pop();
                K--;
            }
            stk.push(s[i]);
        }
        else {
            stk.push(s[i]);
        }
    }

    while(K != 0) {
        stk.pop();
        K--;
    }

    vector<char> ans;

    while(!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

stack<pair<int, int>> stk;
int ans;

int main() {
    FastIO

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (i + 1 < s.size() && s[i + 1] == '(') {
                stk.push({s[i] - '0', 0});
                i++;
            }
            else {
                if (!stk.empty()) {
                    auto now = stk.top();
                    stk.pop();
                    stk.push({now.first, now.second + 1});
                }
                else ans++;
            }
        }
        else if (s[i] == ')') {
            auto now = stk.top();
            stk.pop();
            if (!stk.empty()) {
                auto next = stk.top();
                stk.pop();
                stk.push({next.first, next.second + now.first * now.second});
            }
            else {
                ans += now.first * now.second;
            }
        }
    }

    cout << ans;

    return 0;
}
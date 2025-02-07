#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

int main() {
    FastIO

    for (int t = 1; ; t++) {
        cin >> s;
        if (s[0] == '-') break;

        int close = 0;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                stk.push(s[i]);
            }
            else {
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                }
                else {
                    close++;
                }
            }
        }

        int ans1 = (stk.size() % 2 == 0 ? stk.size() / 2 : stk.size() / 2 + 1);
        int ans2 = (close % 2 == 0 ? close / 2 : close / 2 + 1);

        cout << t << ". " << ans1 + ans2 << '\n';
    }

    return 0;
}
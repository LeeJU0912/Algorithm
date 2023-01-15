#include <bits/stdc++.h>
using namespace std;

stack<char> stk;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    getline(cin, s);

    bool on = false;

    for (int i = 0; i < s.length(); i++) {
        if (on) {
            if (s[i] == '>') {
                on = false;
            }
            cout << s[i];
            continue;
        }
        if (s[i] == '<') {
            while(!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            on = true;
            cout << s[i];
        }
        else if (s[i] == ' ') {
            while(!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            cout << s[i];
        }
        else {
            stk.push(s[i]);
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }


    return 0;
}
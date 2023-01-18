#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int TC;
    cin >> TC;

    while(TC--) {
        string s;
        cin >> s;

        deque<char> s1;
        stack<char> s2;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                if (s1.empty()) continue;
                s2.push(s1.back());
                s1.pop_back();
            }
            else if (s[i] == '>') {
                if (s2.empty()) continue;
                s1.push_back(s2.top());
                s2.pop();
            }
            else if (s[i] == '-') {
                if (s1.empty()) continue;
                s1.pop_back();
            }
            else {
                s1.push_back(s[i]);
            }
        }

        while(!s1.empty()) {
            cout << s1.front();
            s1.pop_front();
        }
        while(!s2.empty()) {
            cout << s2.top();
            s2.pop();
        }
        cout << '\n';
    }

    return 0;
}
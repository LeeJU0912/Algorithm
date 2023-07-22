#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
int depth[31];

int main() {
    FastIO

    for (int i = 0; i < 31; i++) {
        depth[i] = 0;
    }

    cin >> s;

    if (s.length() % 2) {
        cout << 0;
        return 0;
    }

    stack<int> stk;
    int counter = 0;

    for (int i = 0; i < s.length(); i++) {
        if (!stk.empty()) {
            if ((stk.top() == '(' && s[i] == ']') || (stk.top() == '[' && s[i] == ')')) {
                cout << 0;
                return 0;
            }
        }
        if (s[i] == '(' || s[i] == '[') {
            stk.push(s[i]);
            counter++;
        }
        else {
            if (stk.empty()) {
                cout << 0;
                return 0;
            }
            if (s[i] == ']') {
                depth[counter] += max(3, depth[counter + 1] * 3);
                depth[counter + 1] = 0;
            }
            else if (s[i] == ')') {
                depth[counter] += max(2, depth[counter + 1] * 2);
                depth[counter + 1] = 0;
            }
            counter--;
            stk.pop();
        }
    }

    if (!stk.empty()) {
        cout << 0;
    }
    else {
        cout << depth[1];
    }


    return 0;
}
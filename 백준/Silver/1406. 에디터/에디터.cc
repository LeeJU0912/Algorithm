#include <bits/stdc++.h>
using namespace std;

string s;

stack<char> lef;
stack<char> righ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        lef.push(s[i]);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char temp1;
        cin >> temp1;
        if (temp1 == 'P') {
            char temp2;
            cin >> temp2;
            lef.push(temp2);
        }
        else if (temp1 == 'L') {
            if (lef.empty()) continue;
            righ.push(lef.top());
            lef.pop();
        }
        else if (temp1 == 'D') {
            if (righ.empty()) continue;
            lef.push(righ.top());
            righ.pop();
        }
        else if (temp1 == 'B') {
            if (lef.empty()) continue;
            lef.pop();
        }
    }

    while (!lef.empty()) {
        righ.push(lef.top());
        lef.pop();
    }
    while (!righ.empty()) {
        cout << righ.top();
        righ.pop();
    }
    
    return 0;
}
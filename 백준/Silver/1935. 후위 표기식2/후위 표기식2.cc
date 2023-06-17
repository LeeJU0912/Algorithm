#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
stack<double> stk;
int save[26];

string s;

int main() {
    FastIO

    cin >> N;
    cin >> s;

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            stk.push(save[s[i] - 'A']);
        }
        else if (s[i] == '+') {
            double hap = stk.top();
            stk.pop();
            hap += stk.top();
            stk.pop();
            stk.push(hap);
        }
        else if (s[i] == '-') {
            double hap = stk.top();
            stk.pop();
            hap = stk.top() - hap;
            stk.pop();
            stk.push(hap);
        }
        else if (s[i] == '*') {
            double hap = stk.top();
            stk.pop();
            hap *= stk.top();
            stk.pop();
            stk.push(hap);
        }
        else if (s[i] == '/') {
            double hap = stk.top();
            stk.pop();
            hap = stk.top() / hap;
            stk.pop();
            stk.push(hap);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << stk.top();

    return 0;
}
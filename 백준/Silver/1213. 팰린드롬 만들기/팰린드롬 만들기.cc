#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
int counter[26];

queue<char> front;
stack<char> back;

int single;

int main() {
    FastIO

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        counter[s[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (counter[i] % 2 == 1) single++;
    }

    if (single >= 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string mid = "";
    for (int i = 0; i < 26; i++) {
        while(counter[i] > 1) {
            counter[i] -= 2;
            front.push('A' + i);
            back.push('A' + i);
        }

        if (counter[i] == 1) {
            mid = 'A' + i;
        }
    }

    while(!front.empty()) {
        cout << front.front();
        front.pop();
    }
    cout << mid;
    while(!back.empty()) {
        cout << back.top();
        back.pop();
    }

    return 0;
}
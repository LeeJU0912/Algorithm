#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
set<string> save;

vector<pair<int, int>> pairs;

bool string_chk[200];

void solve(int idx) {
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (string_chk[i]) continue;
        ans += s[i];
    }

    save.insert(ans);

    for (int i = idx + 1; i < pairs.size(); i++) {
        string_chk[pairs[i].first] = true;
        string_chk[pairs[i].second] = true;
        solve(i);
        string_chk[pairs[i].first] = false;
        string_chk[pairs[i].second] = false;
    }
}

int main() {
    FastIO

    cin >> s;

    stack<int> idx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            idx.push(i);
        }
        else if (s[i] == ')') {
            pairs.push_back({idx.top(), i});
            idx.pop();
        }
    }

    for (int i = 0; i < pairs.size(); i++) {
        string_chk[pairs[i].first] = true;
        string_chk[pairs[i].second] = true;
        solve(i);
        string_chk[pairs[i].first] = false;
        string_chk[pairs[i].second] = false;
    }


    for (const auto& x : save) {
        cout << x << '\n';
    }

    return 0;
}
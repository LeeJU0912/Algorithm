#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<string> ans;

bool comp(const string& a, const string& b) {
    if (a.length() < b.length()) return true;
    else if (a.length() > b.length()) return false;
    else {
        if (a.compare(b) > 0) return false;
        else return true;
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        bool chk = false;
        string temp;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                chk = true;
                if (temp == "0") temp.clear();
                temp += s[j];
            }
            else {
                if (chk) {
                    ans.push_back(temp);
                    temp.clear();
                }
                chk = false;
            }
        }
        if (chk) {
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end(), comp);

    for (const string& i : ans) {
        cout << i << '\n';
    }

    return 0;
}
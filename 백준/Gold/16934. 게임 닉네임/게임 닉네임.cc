#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

struct INFO {
    char c;
    INFO* next[26];
    int isEnd;
};

string findAns(INFO * now, const string& s, int idx) {
    if (s.size() == idx) {
        if (now->isEnd) {
            string ret = string(1, now->c);
            ret += to_string(now->isEnd + 1);

            return ret;
        }
        else {
            string ret = string(1, now->c);
            return ret;
        }
    }
    if (now->next[s[idx] - 'a'] == nullptr) {
        string ret = string(1, s[idx]);
        return string(1, now->c) + ret;
    }

    return string(1, now->c) + findAns(now->next[s[idx] - 'a'], s, idx + 1);
}

void insert(INFO * now, const string& s, int idx) {
    if (s.size() == idx) {
        now->isEnd++;
        return;
    }

    if (now->next[s[idx] - 'a'] == nullptr) {
        now->next[s[idx] - 'a'] = new INFO();
        now->next[s[idx] - 'a']->c = s[idx];
        insert(now->next[s[idx] - 'a'], s, idx + 1);
    }
    else {
        insert(now->next[s[idx] - 'a'], s, idx + 1);
    }
}

int main() {
    FastIO

    INFO* root = new INFO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        string ans = findAns(root, s, 0);
        cout << ans.substr(1, ans.size() - 1) << '\n';

        insert(root, s, 0);
    }

    return 0;
}
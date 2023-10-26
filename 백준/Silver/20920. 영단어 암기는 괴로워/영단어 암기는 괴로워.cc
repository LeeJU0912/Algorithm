#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<string> save;
map<string, int> mp;

bool comp(const string& a, const string& b) {
    if (mp[a] == mp[b]) {
        if (a.length() == b.length()) {
            if (a > b) return false;
            else return true;
        }
        else if (a.length() > b.length()) return true;
        else return false;
    }
    else if (mp[a] > mp[b]) return true;
    else return false;
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s.length() < M) continue;

        mp[s]++;
    }

    for (const auto& i : mp) {
        save.push_back(i.first);
    }

    sort(save.begin(), save.end(), comp);

    for (const auto& i : save) {
        cout << i << '\n';
    }

    return 0;
}
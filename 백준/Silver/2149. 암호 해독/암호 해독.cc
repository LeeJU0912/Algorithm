#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string key;
    cin >> key;

    string s;
    cin >> s;

    int cut = s.length() / key.length();

    vector<char> save[10];
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        save[counter].push_back(s[i]);
        if (save[counter].size() == cut) {
            counter++;
        }
    }
    
    string sorted = key;
    sort(sorted.begin(), sorted.end());

    vector<char> ans[10];
    vector<bool> chk(key.length(), false);
    for (int i = 0; i < key.length(); i++) {
        for (int j = 0; j < sorted.length(); j++) {
            if (chk[j]) continue;
            if (key[i] == sorted[j]) {
                ans[i] = save[j];
                chk[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < cut; i++) {
        for (int j = 0; j < key.length(); j++) {
            cout << ans[j][i];
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

set<string> s;
vector<string> save;
bool visited[10];

int n, k;

vector<string> tmp;

void solve() {
    if (tmp.size() == k) {
        string temp;
        for (int i = 0; i < tmp.size(); i++) {
            temp += tmp[i];
        }
        s.insert(temp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        tmp.push_back(save[i]);
        solve();
        tmp.pop_back();
        visited[i] = false;
    }
}

int main() {
    FastIO

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        save.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        visited[i] = true;
        solve();
        visited[i] = false;
    }

    cout << s.size();

    return 0;
}
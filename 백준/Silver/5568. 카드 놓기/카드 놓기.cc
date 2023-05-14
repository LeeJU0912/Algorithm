#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

set<string> s;
vector<string> save;

int n;
int k;

int main() {
    FastIO

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    do {
        string tmp;
        for (int i = 0; i < k; i++) {
            tmp += save[i];
        }
        s.insert(tmp);
    } while (next_permutation(save.begin(), save.end()));

    cout << s.size();

    return 0;
}
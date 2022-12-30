#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int counter = 0;
    int ans = 0;

    vector<int> v;
    for (int i = s.length() - 1; i >= 0; i--) {
        ans += (s[i] - '0') * pow(2, counter);
        if (counter == 2 || i == 0) {
            counter = 0;
            v.push_back(ans);
            ans = 0;
            continue;
        }
        counter++;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }

    return 0;
}
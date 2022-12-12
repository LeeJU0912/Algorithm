#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    set<string> st;

    for (int i = 0; i < s.length(); i++) {
        st.insert(s.substr(i, s.length()));
    }

    for (auto i : st) {
        cout << i << '\n';
    }

    return 0;
}
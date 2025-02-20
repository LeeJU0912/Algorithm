#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    set<char> st;
    st.insert('M');
    st.insert('O');
    st.insert('B');
    st.insert('I');
    st.insert('S');

    string s;
    cin >> s;
    for (char c : s) {
        st.erase(c);
    }

    if (st.empty()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
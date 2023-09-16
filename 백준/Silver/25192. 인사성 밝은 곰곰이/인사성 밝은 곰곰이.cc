#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
set<string> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    bool entered = false;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            entered = true;
            st.clear();
        }
        else {
            if (st.find(s) != st.end()) continue;
            if (entered) {
                if (st.find(s) == st.end()) ans++;
            }
            st.insert(s);
        }
    }

    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<string> save;
set<string> st;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        save.clear();
        st.clear();
        bool ans = false;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            save.push_back(s);
        }

        sort(save.begin(), save.end());

        for (int i = 0; i < n; i++) {
            string temp;
            for (int j = 0; j < save[i].length(); j++) {
                temp += save[i][j];

                if (st.find(temp) != st.end()) {
                    ans = true;
                }
            }

            st.insert(save[i]);
        }


        if (ans) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}
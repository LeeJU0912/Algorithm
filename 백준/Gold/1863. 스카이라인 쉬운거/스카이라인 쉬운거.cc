#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<pair<int, int>> save;
stack<int> stk;

int ans;

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        save.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        if (stk.empty()) {
            stk.push(save[i].second);
        }
        else if (save[i].second > stk.top()) {
            stk.push(save[i].second);
        }
        else if (save[i].second < stk.top()) {
            set<int> st;
            while(!stk.empty() && stk.top() >= save[i].second) {
                if (stk.top() > save[i].second) {
                    st.insert(stk.top());
                }
                stk.pop();
            }

            ans += st.size();
            stk.push(save[i].second);
        }
    }

    set<int> st;
    while(!stk.empty()) {
        if (stk.top() == 0) stk.pop();
        else {
            st.insert(stk.top());
            stk.pop();
        }
    }

    ans += st.size();

    cout << ans;

    return 0;
}
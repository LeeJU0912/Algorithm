#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
set<string, greater<>> st;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        if (b == "enter") {
            st.insert(a);
        }
        else {
            st.erase(a);
        }
    }

    for (auto& x : st) {
        cout << x << '\n';
    }

    return 0;
}
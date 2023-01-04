#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    stack<int> s;

    for (int i = 0; i < N; i++) {
        while(!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[500001];
int ans[500001];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    stack<pair<int, int>> stk;

    stk.push({save[0], 1});

    for (int i = 1; i < N; i++) {
        if (save[i] > stk.top().first) {
            while(!stk.empty() && save[i] > stk.top().first) stk.pop();
            if (!stk.empty()) {
                ans[i] = stk.top().second;
            }
            stk.push({save[i], i + 1});
        }
        else if (stk.top().first >= save[i]) {
            ans[i] = stk.top().second;
            stk.push({save[i], i + 1});
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int counter[1000001];

stack<int> stk;
stack<int> ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        save.push_back(temp);
        counter[temp]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && counter[stk.top()] <= counter[save[i]]) {
            stk.pop();
        }

        if (stk.empty()) {
            ans.push(-1);
        }
        else {
            ans.push(stk.top());
        }

        stk.push(save[i]);
    }

    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<int> ans;
set<vector<int>> st;

void solve(int counter) {
    if (counter == M) {
        st.insert(ans);
        return;
    }

    for (int i = 0; i < N; i++) {
        ans.push_back(save[i]);
        solve(counter + 1);
        ans.pop_back();
    }
}

int main() {
    FastIO

    cin >> N >> M;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    solve(0);

    for (const vector<int>& i : st) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
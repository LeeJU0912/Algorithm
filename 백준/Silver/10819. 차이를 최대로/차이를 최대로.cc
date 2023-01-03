#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> v;
bool visited[8];
vector<int> tmp;

int ans;

void solve() {
    if (tmp.size() == N) {
        int temp = 0;
        for (int i = 1; i < N; i++) {
            temp += abs(tmp[i - 1] - tmp[i]);
        }
        ans = max(ans, temp);
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            tmp.push_back(v[i]);
            solve();
            tmp.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    solve();

    cout << ans;

    return 0;
}
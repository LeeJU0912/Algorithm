#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> go_back;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            go_back.emplace_back(a, b);
        }
    }

    sort(go_back.begin(), go_back.end(), greater<>());

    long long ans = 0;
    int L = INT_MAX;
    int R = INT_MAX;

    for (int i = 0; i < go_back.size(); i++) {
        if (L > go_back[i].first) {
            ans += R - L;
            R = go_back[i].first;
            L = go_back[i].second;
        }
        else {
            L = min(L, go_back[i].second);
        }
    }
    ans += R - L;

    cout << M + ans * 2;

    return 0;
}
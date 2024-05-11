#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, S;
        cin >> T >> S;

        save.push_back({S, T});
    }

    sort(save.begin(), save.end(), greater<>());

    int now = save[0].first;

    for (int i = 0; i < N; i++) {
        if (now > save[i].first) now = save[i].first;

        now -= save[i].second;
    }

    cout << (now >= 0 ? now : -1);

    return 0;
}
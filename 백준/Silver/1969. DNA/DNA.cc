#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string ans;
    int ans2 = 0;

    int N, M;
    cin >> N >> M;

    vector<string> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < M; i++) {
        map<char, int> chk;

        for (int j = 0; j < N; j++) {
            chk[save[j][i]]++;
        }

        auto maxi = max_element(chk.begin(), chk.end(), [](const auto &x, const auto &y) {
            return x.second < y.second;
        });

        ans.push_back(maxi->first);
        ans2 += N - maxi->second;
    }

    cout << ans << '\n';
    cout << ans2;

    return 0;
}
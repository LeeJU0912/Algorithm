#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int J, N;
        cin >> J >> N;

        vector<int> save;

        for (int i = 0; i < N; i++) {
            int R, C;
            cin >> R >> C;
            save.push_back(R * C);
        }

        sort(save.begin(), save.end(), greater<>());

        int ans = 0;

        for (int i = 0; i < N; i++) {
            J -= save[i];
            ans++;

            if (J <= 0) break;
        }

        cout << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }
    sort(save.begin(), save.end());

    int ans = 0;

    for (int t = 0; t < N; t++) {
        int chk = save[t];

        for (int i = 0; i < N; i++) {
            if (i == t) continue;
            int x = i;
            int y = lower_bound(save.begin(), save.end(), chk - save[x]) - save.begin();
            if (y == t) y++;

            if (x != y && save[x] + save[y] == chk) {
                ans++;
                break;
            }
        }
    }


    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int L, H;

vector<pair<int, int>> save;

bool chk[1001];

int ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> L >> H;

        save.push_back({H, L});
    }

    sort(save.begin(), save.end(), greater<>());

    ans = save[0].first;
    chk[save[0].second] = true;

    for (int i = 1; i < N; i++) {
        if (chk[save[i].second]) continue;
        if (save[i].second > save[i - 1].second) {
            for (int j = save[i].second; j > save[i - 1].second; j--) {
                if (chk[j]) break;
                chk[j] = true;

                ans += save[i].first;
            }
        }
        else {
            for (int j = save[i].second; j < save[i - 1].second; j++) {
                if (chk[j]) break;
                chk[j] = true;

                ans += save[i].first;
            }
        }
    }

    cout << ans;

    return 0;
}
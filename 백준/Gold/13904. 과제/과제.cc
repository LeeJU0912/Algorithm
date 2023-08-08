#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int DP[1001];

vector<pair<int, int>> save;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;

        save.push_back({w, d});
    }

    sort(save.begin(), save.end(), greater<>());

    for (int i = 0; i < N; i++) {
        for (int j = save[i].second; j >= 1; j--) {
            if (DP[j] < save[i].first) {
                DP[j] = save[i].first;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += DP[i];
    }

    cout << ans;

    return 0;
}
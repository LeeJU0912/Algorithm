#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
float m;
int money;

vector<pair<int, int>> candy;
int DP[10001];

int ans;

int main() {
    FastIO

    while(true) {
        memset(DP, 0, sizeof(DP));
        ans = 0;

        cin >> n >> m;
        candy = vector<pair<int, int>>(n);

        if (n == 0 && m < 0.005) break;

        money = m * 100 + 0.5;

        for (int i = 0; i < n; i++) {
            int c;
            float p;
            cin >> c >> p;

            int candy_price = p * 100 + 0.5;

            candy[i] = {candy_price, c};
        }

        for (int i = 0; i < n; i++) {
            for (int j = candy[i].first; j <= money; j++) {
                DP[j] = max(DP[j], DP[j - candy[i].first] + candy[i].second);
            }
        }

        cout << DP[money] << '\n';
    }

    return 0;
}
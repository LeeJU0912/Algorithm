#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
vector<int> gap;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    for (int i = 1; i < N; i++) {
        gap.push_back(save[i] - save[i - 1]);
    }

    int GCD = gap[0];
    for (int i = 1; i < gap.size(); i++) {
        GCD = min(GCD, gcd(GCD, gap[i]));
    }

    int ans = 0;

    for (int i = 0; i < gap.size(); i++) {
        ans += (gap[i] / GCD) - 1;
    }

    cout << ans;


    return 0;
}
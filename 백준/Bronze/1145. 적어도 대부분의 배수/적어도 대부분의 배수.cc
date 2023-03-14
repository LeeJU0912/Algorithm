#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main(){
    FastIO

    int save[5];

    for (int i = 0; i < 5; i++) {
        cin >> save[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans = min(ans, lcm(save[i], lcm(save[j], save[k])));
            }
        }
    }

    cout << ans;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arrow(1000001);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (arrow[temp + 1]) {
            arrow[temp]++;
            arrow[temp + 1]--;
        }
        else {
            arrow[temp]++;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
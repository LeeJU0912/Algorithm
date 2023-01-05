#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int ans = 0;
    int counter = 1;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            counter = 1;
        }
        else {
            ans += counter++;
        }
    }

    cout << ans;

    return 0;
}
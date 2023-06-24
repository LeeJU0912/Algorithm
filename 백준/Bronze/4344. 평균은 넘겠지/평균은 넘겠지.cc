#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    cout << fixed;
    cout.precision(3);

    while(T--) {
        int N;
        cin >> N;

        vector<int> save(N);

        for (int i = 0; i < N; i++) {
            cin >> save[i];
        }

        double average = accumulate(save.begin(), save.end(), 0.0) / save.size();

        double okay = 0;
        for (int i = 0; i < N; i++) {
            if (save[i] > average) {
                okay++;
            }
        }

        double ans = okay / save.size() * 100;

        if ((int)(ans * 10000) % 10 >= 5) {
            ans *= 1000;
            ans = (int)ans;
            ans++;
            ans = (double)ans / 1000;
        }
        cout << ans << '%' << '\n';

    }

    return 0;
}
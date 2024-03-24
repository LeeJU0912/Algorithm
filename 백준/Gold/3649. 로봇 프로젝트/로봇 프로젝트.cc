#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int x;
vector<int> save;

int main() {
    FastIO

    while(cin >> x) {
        x *= 10000000;

        int n;
        cin >> n;
        save = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> save[i];
        }

        sort(save.begin(), save.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mini = i + 1;
            int maxi = n - 1;
            if (mini > maxi) continue;

            int temp = 0;
            while(mini <= maxi) {
                int mid = (mini + maxi) / 2;

                if (save[mid] < x - save[i]) {
                    mini = mid + 1;
                }
                else if (save[mid] > x - save[i]) {
                    maxi = mid - 1;
                }
                else {
                    temp = save[i];
                    break;
                }
            }

            if (temp) {
                ans = temp;
                break;
            }
        }

        if (ans) {
            cout << "yes " << ans << ' ' << x - ans << '\n';
        }
        else {
            cout << "danger" << '\n';
        }
    }

    return 0;
}
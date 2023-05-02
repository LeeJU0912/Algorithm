#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int ans;
int ans2[30000];

int main() {
    FastIO

    int N;
    cin >> N;

    int save[30000];
    save[0] = N;
    for (int i = N; i >= 0; i--) {
        save[1] = i;

        int temp = 1;
        int j = 2;
        while(true) {
            save[j] = save[j - 2] - save[j - 1];
            if (save[j] < 0) {
                temp = max(temp, j);
                break;
            }
            j++;
        }

        if (ans < temp) {
            for (j = 0; j < temp; j++) {
                ans2[j] = save[j];
            }
            ans = temp;
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << ans2[i] << ' ';
    }

    return 0;
}
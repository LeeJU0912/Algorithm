#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<int> save;
int lis[501];

int binary_search(int start, int end, int val) {
    int idx;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (lis[mid] >= val) {
            idx = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return idx;
}

int main() {
    FastIO

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        save = vector<int>(n);

        for (int i = 0; i < n; i++) {
            cin >> save[i];
        }

        long long ans = 0;
        for (int x = 0; x < n; x++) {
            memset(lis, 0, sizeof(lis));

            int counter = 1;
            lis[1] = save[x];
            for (int i = x; i < n; i++) {
                if (lis[counter] < save[i]) {
                    lis[counter + 1] = save[i];
                    counter++;
                }
                else {
                    int idx = binary_search(1, counter, save[i]);

                    lis[idx] = save[i];
                }
                ans += counter;
            }
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}
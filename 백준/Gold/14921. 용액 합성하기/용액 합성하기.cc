#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int start = i + 1;
        int end = N - 1;

        int gap = INT_MAX;
        int x = start;

        while(start <= end) {
            int mid = (start + end) / 2;

            if (save[i] + save[mid] < 0) {
                if (gap > abs(save[mid] + save[i])) {
                    gap = abs(save[mid] + save[i]);
                    x = mid;
                }

                start = mid + 1;

            }
            else {
                if (gap > abs(save[i] + save[mid])) {
                    gap = abs(save[mid] + save[i]);
                    x = mid;
                }
                end = mid - 1;
            }
        }

        if (abs(ans) > abs(save[i] + save[x])) {
            ans = save[i] + save[x];
        }
    }

    cout << ans;

    return 0;
}
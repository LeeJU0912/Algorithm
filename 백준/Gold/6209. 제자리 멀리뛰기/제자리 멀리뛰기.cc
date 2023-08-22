#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int d, n, m;
vector<int> save;
int ans;

int main() {
    FastIO

    cin >> d >> n >> m;

    save = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int start = 1;
    int end = d;

    while(start <= end) {
        int mid = (start + end) / 2;

        int now = 0;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (save[i] - now >= mid) {
                now = save[i];
            }
            else {
                counter++;
            }
        }

        if (counter > m) {
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int save[300001];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> save[i];
    }

    int start = 1;
    int end = 1e9;
    int ans;
    while(start <= end) {
        int mid = (start + end) / 2;

        int hap = 0;
        for (int i = 0; i < M; i++) {
            int div = save[i] % mid;
            if (div == 0) {
                hap += save[i] / mid;
            }
            else {
                hap += save[i] / mid + 1;
            }
        }

        if (hap <= N) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
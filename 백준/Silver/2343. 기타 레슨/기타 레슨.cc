#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int save[100001];

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int start = 1;
    int end = 1000000000;

    while(start <= end) {
        int mid = (start + end) / 2;

        int hap = 0;

        int maxi = 0;

        int count = 0;

        for (int i = 0; i < N; i++) {
            if (hap + save[i] > mid) {
                maxi = max(maxi, hap);
                hap = save[i];
                count++;
            }
            else hap += save[i];
        }

        maxi = max(maxi, hap);
        count++;
        
        if (count > M) {
            start = mid + 1;
        }
        else {
            ans = min(ans, maxi);
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
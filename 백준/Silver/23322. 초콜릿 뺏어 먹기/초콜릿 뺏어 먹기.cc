#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[2001];
int ans;
int day;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }


    while (true) {
        int gap = 0;
        int idx = -1;

        for (int i = K; i < N; i++) {
            if (gap < a[i] - a[i - K]) {
                gap = a[i] - a[i - K];
                idx = i;
                break;
            }
        }
        
        if (idx != -1) {
            ans += gap;
            a[idx] = a[idx - K];
        }
        else {
            break;
        }
        day++;

        sort(a, a + N);
        if (a[0] == a[N - 1]) break;
    }

    cout << ans << ' ' << day;

    return 0;
}
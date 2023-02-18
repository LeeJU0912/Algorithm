#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> crane_limit(N);

    for (int i = 0; i < N; i++) {
        cin >> crane_limit[i];
    }

    int M;
    cin >> M;

    vector<int> box(M);

    for (int i = 0; i < M; i++) {
        cin >> box[i];
    }

    sort(crane_limit.begin(), crane_limit.end());
    sort(box.begin(), box.end());

    vector<int> crane_maxidx(N, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            if (box[j] <= crane_limit[i]) {
                crane_maxidx[i] = j;
                break;
            }
        }
    }

    vector<bool> picked(M, false);
    int counter = 0;
    while (counter < M) {
        ans++;
        for (int i = 0; i < N; i++) {
            for (int j = crane_maxidx[i]; j >= 0; j--) {
                if (picked[j]) continue;
                picked[j] = true;
                crane_maxidx[i] = j;
                counter++;
                break;
            }
        }

        if (ans > M) {
            cout << -1;
            return 0;
        }
    }

    cout << ans;


    return 0;
}
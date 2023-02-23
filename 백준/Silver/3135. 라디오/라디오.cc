#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B;
    cin >> A >> B;

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int ans = 0;

    if (A < B) {
        sort(save.begin(), save.end());
        int gap = INT_MAX;
        int go = A;
        for (int i = 0; i < N; i++) {
            if (abs(B - save[i]) < gap) {
               go = save[i];
               gap = abs(B - save[i]);
            }
        }
        ans = abs(B - go) + 1;
    }
    else {
        sort(save.begin(), save.end(), greater<>());
        int gap = INT_MAX;
        int go = A;
        for (int i = 0; i < N; i++) {
            if (abs(B - save[i]) < gap) {
                go = save[i];
                gap = abs(B - save[i]);
            }
        }
        ans = abs(go - B) + 1;
    }

    cout << min(ans, abs(A - B));


    return 0;
}
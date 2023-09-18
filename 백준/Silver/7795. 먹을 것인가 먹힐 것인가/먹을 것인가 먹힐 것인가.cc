#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        vector<int> B(M);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(B.begin(), B.end());

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > B[M - 1]) {
                ans += M;
                continue;
            }
            ans += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        }

        cout << ans << '\n';
    }


    return 0;
}
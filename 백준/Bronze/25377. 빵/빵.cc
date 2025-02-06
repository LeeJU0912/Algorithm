#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int ans = INT_MAX;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        if (A > B) continue;
        ans = min(ans, B);
    }

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
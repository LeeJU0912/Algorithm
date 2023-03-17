#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int ans;

int recursive(int a) {
    if (a == 1) return 0;
    else {
        for (int i = 1; i < a; i++) {
            return i * (a - i) + recursive(i) + recursive(a - i);
        }
    }
}

int main(){
    FastIO

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        ans = max(ans, i * (N - i) + recursive(i) + recursive(N - i));
    }

    cout << ans;

    return 0;
}
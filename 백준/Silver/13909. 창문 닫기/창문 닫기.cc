#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    int ans = 0;
    for (int i = 1; i * i <= N; i++) {
        ans++;
    }
    
    cout << ans;

    return 0;
}
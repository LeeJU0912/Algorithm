#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string a, b;
int A[26], B[26];
int ans;

int main() {
    FastIO

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        A[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++) {
        B[b[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        ans += abs(A[i] - B[i]);
    }

    cout << ans;

    return 0;
}
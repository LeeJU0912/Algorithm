#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string N;
    int B;
    cin >> N >> B;

    int ans = 0;

    int counter = 0;
    for (int i = N.length() - 1; i >= 0; i--) {
        if (N[i] >= 'A' && N[i] <= 'Z') {
            ans += pow(B, counter) * (N[i] - 'A' + 10);
        }
        else {
            ans += pow(B, counter) * (N[i] - '0');
        }
        counter++;
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string N;
    cin >> N;

    if (N.length() == 1) {
        cout << N[0];
        return 0;
    }
    string temp = N.substr(1, N.length() - 1);

    unsigned long long ans = 0;

    int multi = 9;
    for (int i = 1; i < N.length(); i++) {
        ans += multi * i;
        multi *= 10;
    }

    ans += (N[0] - '1') * pow(10, N.length() - 1) * N.length();
    ans += (stoll(temp) + 1) * N.length();

    cout << ans;

    return 0;
}